/*******************************************************************************
 * Begin of file shapes_data.h
 *
 * @author: Steven Hulshof
 * Created: 12/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Functions for processing the shapes [primitive, line, ellipse].
 *
 ******************************************************************************/

#ifndef SHAPES_DATA_H_
#define SHAPES_DATA_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "system.h"
#include "pixel_data.h"
#include <stdint.h>
#include <math.h>

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
status_t VGA_processPrimitiveData(	sPosition_t verticePos[],
									uint16_t	numberOfVertices,
									color_t		lineColor,
									color_t		fillColor,
									uint8_t		lineWeight	);


/**
 * @brief Draws single line without weight.
 *
 * @param endPointPos[2]	End point positions of the line.
 * @param lineColor			Line color.
 * @return	Status of operation.
 */
status_t VGA_setSingleLine(	sPosition_t endPointPos[2],
							color_t 	lineColor);

/**
 * @brief Translates pixel position based on rotation.
 *
 * @param centerPointPos	Center position of the ellipse.
 * @param radii				Radii a and b are used for determining the shape of the ellipse.
 * @param cosAngle			Cosine of the rotation angle.
 * @param sinAngle			Sine of the rotation angle.
 * @param theta				Radial variable (0, 2PI).
 * @return pixelPos			Position of the translated pixel.
 */
sPosition_t VGA_translateEllipsePixelPos(	sPosition_t* 	centerPointPos,
							  				sRadii_t* 		radii,
							  				float 			cosAngle,
							  				float 			sinAngle,
							  				float 			theta	);

/**
 * @brief Draw ellipse pixel frame.
 *
 * @param centerPointPos	Center position of the ellipse.
 * @param radii				Radii a and b are used for determining the shape of the ellipse.
 * @param lineColor			Line color of the ellipse.
 * @param cosAngle			Cosine of the rotation angle.
 * @param sinAngle			Sine of the rotation angle.
 * @return	Status of operation.
 */
status_t VGA_setEllipseFrame(	sPosition_t*	centerPointPos,
			   					sRadii_t* 		radii,
			   					color_t			lineColor,
			   					float 			cosAngle,
			   					float 			sinAngle	);

/**
 * @brief Draw ellipse fill.
 *
 * @param centerPointPos	Center position of the ellipse.
 * @param radii				Radii a and b are used for determining the shape of the ellipse.
 * @param color				Color of the ellipse fill.
 * @param cosAngle			Cosine of the rotation angle.
 * @param sinAngle			Sine of the rotation angle.
 * @return	Status of operation.
 */
status_t VGA_setEllipseFill(	sPosition_t*	centerPointPos,
								sRadii_t* 		radii,
								color_t			color,
								float 			cosAngle,
								float 			sinAngle	);

/**
 * @brief Draw ellipse fill.
 *
 * @param centerPointPos	Center position of the ellipse.
 * @param radii				Radii a and b are used for determining the shape of the ellipse.
 * @param lineColor			Line color of the ellipse.
 * @param cosAngle			Cosine of the rotation angle.
 * @param sinAngle			Sine of the rotation angle.
 * @param halfWeight		Half the line weight of the ellipse.
 * @return	Status of operation.
 */
status_t VGA_setEllipseLineFill(	sPosition_t*	centerPointPos,
									sRadii_t* 		radii,
									color_t			lineColor,
									float 			cosAngle,
									float 			sinAngle,
									float			halfWeight	);

/**
 * @brief	Calculates pixel positions of the ellipse.
 *
 * @note	Function will not work of lineColor = VGA_COL_TRANSPARANT.
 *
 * @param centerPointPos	Center position of the ellipse.
 * @param radii	Radii 		a and b are used for determining the shape of the ellipse.
 * @param rotationDegrees	Rotation of the ellipse in degrees.
 * @param lineColor			Line color of the ellipse.
 * @param fillColor 		Fill color of the ellipse.
 * @param lineWeight		Line weight of the ellipse.
 * @return	Status of operation.
 */
status_t VGA_processEllipseData(	sPosition_t*	centerPointPos,
								  	sRadii_t* 		radii,
								  	int 			rotationDegrees,
								  	color_t 		lineColor,
								  	color_t 		fillColor,
								  	uint8_t 		lineWeight	);

#endif /* SHAPES_DATA_H_ */
/* End of file shapes_data.h */
