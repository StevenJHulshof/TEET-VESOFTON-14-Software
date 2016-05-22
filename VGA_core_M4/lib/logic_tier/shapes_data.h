/*******************************************************************************
 * Begin of file shapes_data.h
 *
 * @author: Steven Hulshof, Lukas ten Hove
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
#include "utility.h"
#include <stdint.h>
#include <math.h>
#include <string.h>

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief	Processes line weight data to pixel position.
 *
 * @param	centerPointPos	Pixel position around which the line weight should be calculated.
 * @param	lineColor		Color of the line.
 * @param	lineWeight		Weight of the line.
 * @return 	Status of operation.
 */
status_t VGA_setLineWeight( sPosition_t*	centerPointPos,
							color_t			lineColor,
							uint8_t			lineWeight	);
/**
 * @brief	Processes line data to pixel positions.
 *
 * @param 	endPointPos[2]	End point positions of the line.
 * @param 	lineColor		Color of the line.
 * @param	lineWeight		Weight of the line.
 * @return	Status of operation.
 */
status_t VGA_setLineData(	sPosition_t endPointPos[2],
							color_t 	lineColor,
							uint8_t		lineWeight	);

/**
 * @brief	Fills polygon with fillColor parameter using
 * 			efficient version of the Point-In-Polygon algorithm.
 *
 * @param	vertices			Vertices of the polygon to fill.
 * @param	numberOfVertices	Total number of vertices.
 * @param	imageBorder			Image border constraints.
 * @param	fillColor			Color to fill.
 * @return	Status of operation.
 */
status_t VGA_setPolygonFill(sPosition_t vertices[],
							uint16_t 	numberOfVertices,
							sPosition_t imageBorder[2],
							color_t 	fillColor);

/**
 * @brief	Set polygon frame line.
 *
 * @param	verticePos[]		Positions of the polygon vertices.
 * @param	numberOfVertices	Total number of polygon vertices.
 * @param	lineColor			Line color of the polygon.
 * @param	lineWeight			Weight of the line.
 * @return	Status of operation.
 */
status_t VGA_setPolygonFrame(	sPosition_t verticePos[],
								uint16_t 	numberOfVertices,
								color_t 	lineColor,
								uint8_t		lineWeight	);

/**
 * @brief	Process polygon data to pixel position.
 *
 * @param	verticePos[]		Positions of the polygon vertices.
 * @param 	numberOfVertices	Total number of polygon vertices.
 * @param 	lineColor			Line color of the polygon.
 * @param	fillColor 			Fill color of the polygon.
 * @param	lineWeight			Weight of the line.
 * @return	Status of operation.
 */
status_t VGA_setPolygonData(	sPosition_t	verticePos[],
								uint16_t	numberOfVertices,
								color_t		lineColor,
								color_t		fillColor,
								uint8_t		lineWeight	);

/**
 * @brief	Process primitive data to pixel position.
 *
 * @param	centerPointPos	Center point position of the primitive.
 * @param	radii			Radii of the primitive. This will be calculated through a circle algorithm.
 * @param	rotationDegrees	Rotation in degrees.
 * @param	lineColor		Color of the frame line.
 * @param	fillColor		Color of the primitive fill.
 * @param 	lineWeight		Weight of the frame line.
 * @param	primitiveShape	Default shape of the primitive.
 * @return	Status of operation.
 */
status_t VGA_setPrimitiveData(	sPosition_t* 		centerPointPos,
								sRadii_t* 			radii,
								uint16_t 			rotationDegrees,
								color_t				lineColor,
								color_t				fillColor,
								uint16_t			lineWeight,
								primitiveShape_t	primitiveShape	);

#endif /* SHAPES_DATA_H_ */
/* End of file shapes_data.h */
