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
uint8_t VGA_pixelInPrimitive(	sPosition_t 	verticePos[],
								sPosition_t* 	pixelPos,
								uint16_t 		numberOfVertices	) {

	uint8_t inPrimitive = 0;
	int   	i;
	int 	j = numberOfVertices - 1 ;

	for(i = 0; i < numberOfVertices; i++) {


		if ((((float) verticePos[i].y > (float) pixelPos->y) !=
			((float) verticePos[j].y > (float) pixelPos->y)) &&
		    ((float) pixelPos->x < ((float) verticePos[j].x -
		    (float) verticePos[i].x) * ((float) pixelPos->y -
		    (float) verticePos[i].y) / ((float) verticePos[j].y -
		    (float) verticePos[i].y) + (float) verticePos[i].x) ) {

			if(inPrimitive == 1) {
				inPrimitive = 0;
			} else {
				inPrimitive = 1;
			}
		}

		j = i;
	}

	return inPrimitive;
}

status_t setPrimitiveFrame(	sPosition_t verticePos[],
							uint16_t 	numberOfVertices,
							color_t 	lineColor	) {

	status_t status = VGA_SUCCESS;
	uint16_t vertice;

	for(vertice = 0; vertice < numberOfVertices; vertice++) {

		sPosition_t line[2];
		line[0] = verticePos[vertice];

		if(vertice > numberOfVertices-2) {
			line[1] = verticePos[0];
		} else {
			line[1] = verticePos[vertice+1];
		}

		status = VGA_setSingleLine(line, lineColor);

		if(status != VGA_SUCCESS) {
			return status;
		}
	}

	return status;
}

status_t VGA_processPrimitiveData(	sPosition_t verticePos[],
									uint16_t	numberOfVertices,
									color_t		lineColor,
									color_t		fillColor,
									uint8_t		lineWeight	) {

	status_t status = VGA_SUCCESS;
	uint16_t i, x, y;
	uint16_t minY = INF;
	uint16_t minX = INF;
	uint16_t maxY = 0;
	uint16_t maxX = 0;

	for(i = 0; i < numberOfVertices; i++) {

		if(verticePos[i].x < minX) {
			minX = verticePos[i].x;
		}
		if(verticePos[i].y < minY) {
			minY = verticePos[i].y;
		}
		if(verticePos[i].x > maxX) {
			maxX = verticePos[i].x;
		}
		if(verticePos[i].y > maxY) {
			maxY = verticePos[i].y;
		}
	}

	for(y = minY; y < maxY; y++) {
		for(x = minX; x < maxX; x++) {

			sPosition_t pixelPos = {x, y};

			if(VGA_pixelInPrimitive(verticePos, &pixelPos, numberOfVertices) != 0) {

				status = VGA_setPixelData(&pixelPos, fillColor);
				if(status != VGA_SUCCESS) {
					return status;
				}
			}
		}
	}

	status = setPrimitiveFrame(verticePos, numberOfVertices, lineColor);

	return status;
}

status_t VGA_setSingleLine(    sPosition_t endPointPos[2],
                               color_t     lineColor   ) {

	status_t 	status = VGA_SUCCESS;
	sPosition_t startPos;
	sPosition_t endPos;
	sPosition_t pixelPos;
	uint16_t	x;
	int			y;
	float 		a;

	// Specify start position and end position
	if(endPointPos[0].x > endPointPos[1].x) {
		startPos = endPointPos[1];
		endPos = endPointPos[0];
	} else {
		startPos = endPointPos[0];
		endPos = endPointPos[1];
	}

	// Specify dx and dy
	sPosition_t deltaPos = {
		endPos.x - startPos.x,
		endPos.y - startPos.y
	};

	// Prevent empty pixels
	if(fabs(deltaPos.y) < fabs(deltaPos.x)) {

		// Calculate slope
		a = (float) deltaPos.y / (float) deltaPos.x;

		// Draw line
		for(x = 0; x < deltaPos.x+1; x++) {

			// Set pixel position
			pixelPos.x = x + startPos.x;
			pixelPos.y = a * x + startPos.y;
			status = VGA_setPixelData(&pixelPos, lineColor);

			// Report status
			if(status != VGA_SUCCESS) {
				return status;
			}
		}
	} else {

		// Calculate slope
		a = (float) deltaPos.x / (float) deltaPos.y;

		// Specify whether line should climb or fall
		if(deltaPos.y < 0) {

			// Draw line
			for(y = 0; y > deltaPos.y-1; y--) {

				// Set pixel position
				pixelPos.x = a * y + startPos.x;
				pixelPos.y = y + startPos.y;
				status = VGA_setPixelData(&pixelPos, lineColor);

				// Report status
				if(status != VGA_SUCCESS) {
					return status;
				}
			}
		} else {

			// Draw line
			for(y = 0; y < deltaPos.y+1; y++) {

				// Set pixel position
				pixelPos.x = a * y + startPos.x;
				pixelPos.y = y + startPos.y;
				status = VGA_setPixelData(&pixelPos, lineColor);

				// Report status
				if(status != VGA_SUCCESS) {
					return status;
				}
			}
		}
	}

	return status;
}

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

status_t VGA_setEllipseFrame(	sPosition_t*	centerPointPos,
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

status_t VGA_setEllipseFill(	sPosition_t*	centerPointPos,
								sRadii_t* 		radii,
								color_t			color,
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

		// Draw line from centerPos to pixelPos.
		sPosition_t line[2] = {*centerPointPos, pixelPos};
		status = VGA_setSingleLine(line, color);

		// Report status
		if(status != VGA_SUCCESS) {
			return status;
		}
	}

	return status;
}

status_t VGA_setEllipseLineFill(	sPosition_t*	centerPointPos,
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

		// Draw line from pixelPosIn to PixelPosOut.
		sPosition_t line[2] = {pixelPosIn, pixelPosOut};
		status = VGA_setSingleLine(line, lineColor);

		// Report status
		if(status != VGA_SUCCESS) {
			return status;
		}
	}

	return status;
}

status_t VGA_processEllipseData(	sPosition_t*	centerPointPos,
								  	sRadii_t* 		radii,
								  	int 			rotationDegrees,
								  	color_t 		lineColor,
								  	color_t 		fillColor,
								  	uint8_t			lineWeight	) {

	status_t 	status			= VGA_SUCCESS;
	float 		rotationRadian 	= rotationDegrees * M_PI / 180;
	float 		sinAngle 		= sinf(rotationRadian);
	float 		cosAngle		= cosf(rotationRadian);
	float		halfWeight		= lineWeight * 0.5;

	// Report status
	if(lineColor == VGA_COL_TRANSPARENT || lineWeight < 1) {
		return VGA_ERROR_ARGUMENT_OUT_OF_BOUNDS;
	}

	// Specify ellipse state
	if(lineWeight > 1) {

		// Line weight = 1 Fill = transparent
		if(fillColor == VGA_COL_TRANSPARENT) {

			status = VGA_setEllipseLineFill(centerPointPos, radii, lineColor, cosAngle, sinAngle, halfWeight);

		// Line weight = 1 Fill = not transparent
		} else {

			// Set outer line ellipse
			sRadii_t radiiBuf = {
				radii->a + halfWeight,
				radii->b + halfWeight
			};
			status = VGA_setEllipseFill(centerPointPos, &radiiBuf, lineColor, cosAngle, sinAngle);

			// Report status
			if(status != VGA_SUCCESS) {
				return status;
			}

			// Set inner line ellipse
			radiiBuf.a = radii->a - halfWeight;
			radiiBuf.b = radii->b - halfWeight;
			status = VGA_setEllipseFill(centerPointPos, &radiiBuf, fillColor, cosAngle, sinAngle);
		}
	} else {
		// Line weight > 1 Fill = transparent
		if(fillColor == VGA_COL_TRANSPARENT) {

			status = VGA_setEllipseFrame(centerPointPos, radii, lineColor, cosAngle, sinAngle);

		// Line weight > 1 Fill = not transparent
		} else {

			status = VGA_setEllipseFill(centerPointPos, radii, fillColor, cosAngle, sinAngle);

			// Report status
			if(status != VGA_SUCCESS) {
				return status;
			}

			status = VGA_setEllipseFrame(centerPointPos, radii, lineColor, cosAngle, sinAngle);
		}
	}

	return status;
}

/* End of file shapes_data.c */
