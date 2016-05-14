/*******************************************************************************
 * Begin of file shapes_data.c
 *
 * @author: Steven Hulshof
 * Created: 12/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Functions for processing the shapes [primitive, line, ellipse].
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "shapes_data.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
sPosition_t VGA_translateEllipsePixelPos(	sPosition_t* 	centerPointPos,
							  				sRadii_t* 		radii,
							  				float 			cosAngle,
							  				float 			sinAngle,
							  				float 			theta	) {

	// Set ellipse pixel relative to origin
	sPosition_t pixelPos		= {
		radii->a * cosf(theta),
		radii->b * sinf(theta)
	};

	// Buffer prevents skewing
	sPosition_t pixelPosBuf		= {
		pixelPos.x,
		pixelPos.y
	};

	// Translate pixel rotation
	pixelPos.x = cosAngle * pixelPosBuf.x - sinAngle * pixelPosBuf.y;
	pixelPos.y = cosAngle * pixelPosBuf.y + sinAngle * pixelPosBuf.x;

	// Set ellipse pixel relative to center point
	pixelPos.x = centerPointPos->x + pixelPos.x;
	pixelPos.y = centerPointPos->y + pixelPos.y;

	return pixelPos;
}

status_t VGA_drawEllipseFrame(	sPosition_t*	centerPointPos,
			   					sRadii_t* 		radii,
			   					color_t			lineColor,
			   					float 			cosAngle,
			   					float 			sinAngle	) {

	status_t 	status = VGA_SUCCESS;
	float 		theta;

	// Draw frame line
	for(theta = 0; theta < 2*M_PI; theta += ELLIPSE_RESOLUTION) {

		// Translate pixel position
		sPosition_t pixelPos = VGA_translateEllipsePixelPos(centerPointPos,
															radii,
															cosAngle,
															sinAngle,
															theta);

		// Draw pixel
		status = VGA_setPixelData(&pixelPos, lineColor);

		// Report status
		if(status != VGA_SUCCESS) {
			return status;
		}
	}

	return status;
}

status_t VGA_drawEllipseFill(	sPosition_t*	centerPointPos,
								sRadii_t* 		radii,
								color_t			lineColor,
								float 			cosAngle,
								float 			sinAngle	) {

	status_t 	status = VGA_SUCCESS;
	float 		theta;

	// Fill the ellipse
	for(theta = 0; theta < 2*M_PI; theta += ELLIPSE_RESOLUTION) {

		// Translate pixel position
		sPosition_t pixelPos = VGA_translateEllipsePixelPos(centerPointPos,
															radii,
															cosAngle,
															sinAngle,
															theta);

		// TODO: Draw line centerPos to pixelPos.

		// Report status
		if(status != VGA_SUCCESS) {
			return status;
		}
	}

	return status;
}

status_t VGA_drawEllipseLineFill(	sPosition_t*	centerPointPos,
									sRadii_t* 		radii,
									color_t			lineColor,
									float 			cosAngle,
									float 			sinAngle,
									float			halfWeight) {

	status_t 	status = VGA_SUCCESS;
	float 		theta;

	// Fill the ellipse
	for(theta = 0; theta < 2*M_PI; theta += ELLIPSE_RESOLUTION) {

		// Set outer line pixel
		sRadii_t radiiBuf = {
			radii->a + halfWeight,
			radii->b + halfWeight
		};

		// Translate outer line pixel position
		sPosition_t pixelPosOut = VGA_translateEllipsePixelPos(	centerPointPos,
																&radiiBuf,
																cosAngle,
																sinAngle,
																theta	);

		// Set inner line pixel
		radiiBuf.a = radii->a - halfWeight;
		radiiBuf.b = radii->b - halfWeight;

		// Translate inner line pixel position
		sPosition_t pixelPosIn = VGA_translateEllipsePixelPos(	centerPointPos,
																&radiiBuf,
																cosAngle,
																sinAngle,
																theta	);

		// TODO: Draw line pixelPosIn to PixelPosOut.

		// Report status
		if(status != VGA_SUCCESS) {
			return status;
		}
	}

	return status;
}

status_t VGA_calculateEllipseData(	sPosition_t*	centerPointPos,
								  	sRadii_t* 		radii,
								  	int 			rotationDegrees,
								  	color_t 		lineColor,
								  	color_t 		fillColor,
								  	uint8_t			lineWeight	) {

	// Initialize variables
	status_t 	status			= VGA_SUCCESS;
	float 		rotationRadian 	= rotationDegrees * M_PI / 180;
	float 		sinAngle 		= sinf(rotationRadian);
	float 		cosAngle		= cosf(rotationRadian);
	float		halfWeight		= lineWeight * 0.5;

	// Specify ellipse state
	if(lineWeight > 1) {

		if(fillColor == VGA_COL_TRANSPARANT) {

			status = VGA_drawEllipseLineFill(centerPointPos, radii, lineColor, cosAngle, sinAngle, halfWeight);
		} else {

			// Set outer line ellipse
			sRadii_t radiiBuf = {
				radii->a + halfWeight,
				radii->b + halfWeight
			};
			status = VGA_drawEllipseFill(centerPointPos, &radiiBuf, lineColor, cosAngle, sinAngle);

			// Report status
			if(status != VGA_SUCCESS) {
				return status;
			}

			// Set inner line ellipse
			radiiBuf.a = radii->a + halfWeight;
			radiiBuf.b = radii->b + halfWeight;
			status = VGA_drawEllipseFill(centerPointPos, &radiiBuf, lineColor, cosAngle, sinAngle);
		}
	} else {
		if(fillColor == VGA_COL_TRANSPARANT) {

			status = VGA_drawEllipseFrame(centerPointPos, radii, lineColor, cosAngle, sinAngle);
		} else {

			status = VGA_drawEllipseFill(centerPointPos, radii, lineColor, cosAngle, sinAngle);

			// Report status
			if(status != VGA_SUCCESS) {
				return status;
			}

			status = VGA_drawEllipseFrame(centerPointPos, radii, lineColor, cosAngle, sinAngle);
		}
	}

	return status;
}

/* End of file shapes_data.c */
