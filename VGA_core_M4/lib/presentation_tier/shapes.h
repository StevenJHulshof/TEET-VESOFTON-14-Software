/*******************************************************************************
 * Begin of file shapes.h
 *
 * @author: Steven Hulshof
 * Created: 23/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief 	This file contains the draw functions of the VGA lib shapes. Triangle,
 * 			square, pentagon, hexagon, heptagon, octagon, nonagon, decagon, ellipse,
 * 			polygon.
 *
 ******************************************************************************/

#ifndef SHAPES_H_
#define SHAPES_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "shapes_data.h"

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief	Draws line on VGA screen.
 *
 * @param 	endPointPos[2]	End point positions of the line.
 * @param 	lineColor		Color of the line.
 * @param	lineWeight		Weight of the line.
 * @return	Status of operation.
 */
status_t VGA_drawLine(	sPosition_t endPointPos[2],
						color_t lineColor,
						uint8_t lineWeight	);

/**
 *	@brief	Draws primitive on VGA screen.
 *
 *	@param	centerPointPos	Center point position of the primitive.
 *	@param	radii			Radius x and y of the primitive.
 *	@param	rotationDegrees	Rotation of the primitive in degrees.
 *	@param	lineColor		Primitive frame line color.
 *	@param	fillColor		Primitive fill color.
 *	@param	lineWeight		Primitive frame line weight.
 *	@param	primitiveShape	Primitive default shape.
 *	@return	Status of operation.
 */
status_t VGA_drawPrimitive(	sPosition_t* 		centerPointPos,
							sRadii_t*			radii,
							uint16_t			rotationDegrees,
							color_t				lineColor,
							color_t				fillColor,
							uint8_t				lineWeight,
							primitiveShape_t	primitiveShape);

#endif /* SHAPES_H_ */
/* End of file shapes.h */
