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
#include <string.h>


/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
int VGA_sign(int i);

status_t VGA_setLineWeight( sPosition_t*	centerPos,
							color_t			lineColor,
							uint8_t			lineWeight);
/**
 * @brief Draws single line without weight.
 *
 * @param endPointPos[2]	End point positions of the line.
 * @param lineColor			Line color.
 * @return	Status of operation.
 */
status_t VGA_setLineData(	sPosition_t endPointPos[2],
							color_t 	lineColor,
							uint8_t		lineWeight	);

/**
 * @brief	Checks whether a pixel is inside the polygon using the
 * 			Point-In-Polygon algorithm.
 *
 * @param verticePos[]	Positions of the polygon vertices.
 * @param pixelPos		Pointer to the pixel position that will be checked.
 * @param numberOfVertices	Total number of polygon vertices.
 * @return inPolygon	Returns 1 when pixel is inside the polygon, otherwise 0.
 */
uint8_t VGA_pixelInPolygon(	sPosition_t 	verticePos[],
							sPosition_t* 	pixelPos,
							uint16_t 		numberOfVertices	);

/**
 * @brief	Set polygon frame line.
 *
 * @param verticePos[]	Positions of the polygon vertices.
 * @param numberOfVertices	Total number of polygon vertices.
 * @param lineColor	Line color of the polygon.
 */
status_t VGA_setPolygonFrame(	sPosition_t verticePos[],
								uint16_t 	numberOfVertices,
								color_t 	lineColor,
								uint8_t		lineWeight	);

/**
 * @brief	Set polygon with fill and frame line.
 *
 * @param verticePos[]	Positions of the polygon vertices.
 * @param numberOfVertices	Total number of polygon vertices.
 * @param lineColor	Line color of the polygon.
 * @param fillColor Fill color of the polygon.
 */
status_t VGA_setPolygonData(	sPosition_t verticePos[],
								uint16_t	numberOfVertices,
								color_t		lineColor,
								color_t		fillColor,
								uint8_t		lineWeight	);

status_t VGA_setPrimitiveData(	sPosition_t* 	centerPointPos,
								sRadii_t* 		radii,
								uint16_t 		rotationDegrees,
								color_t			lineColor,
								color_t			fillColor,
								uint16_t		lineWeight,
								sampleSize_t	sampleSize	);





#endif /* SHAPES_DATA_H_ */
/* End of file shapes_data.h */
