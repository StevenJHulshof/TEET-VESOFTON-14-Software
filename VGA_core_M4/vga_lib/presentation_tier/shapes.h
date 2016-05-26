/*******************************************************************************
 * Begin of file shapes.h
 *
 * @author: Steven Hulshof
 * Created: 23/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief 	This file contains the draw functions of the VGA lib shapes.
 *
 * The following shapes can be created using this file: Line, triangle, square,
 * pentagon, hexagon, heptagon, octagon, nonagon, decagon, ellipse and polygon.
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
 * This function will call VGA_L_setLineData() for processing. Can be used
 * if the user requires a straight line on the screen.
 *
 * @param 	endPointPos		End point positions of the line.
 * @param 	lineColor		Color of the line. Ranging 0 to 255.
 * @param	lineWeight		Weight of the line in pixels. Ranging 1 to 255.
 * @return	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 					- 	Operation is success.
 * @return	VGA_PIXEL_NOT_SET 				- 	Set pixel operation has failed.
 * @return	VGA_LINE_COL_OUT_OF_BOUNDS		-	Input line color is out of
 * 												bounds. (0 to 255).
 * @return	VGA_LINE_WEIGHT_OUT_OF_BOUNDS	- 	Input line weight is out of
 * 												bounds. (1 to 255).
 *
 * @code{.c}
 * sPosition_t endPoints[2] = {{50, 50}, {100, 100}};
 * status_t status = VGA_P_drawLine(endPoints, VGA_COL_BLUE, 4);
 * if(status != VGA_SUCCESS) {
 * 	return status;
 * }
 * @endcode
 */
status_t VGA_P_drawLine(	sPosition_t endPointPos[2],
							color_t lineColor,
							uint8_t lineWeight	);

/**
 * @brief	Draws primitive on VGA screen.
 *
 * This functions will call VGA_L_setPrimitiveData() for processing. Can be
 * used if the user requires a default primitive shape.
 *
 * @param	centerPointPos	Center point position of the primitive. Contains x
 *							and y coordinates.
 * @param	radii			Radius x and y of the primitive. Must be above 0.
 * @param	rotationDegrees	Rotation of the primitive in degrees.
 * @param	lineColor		Primitive frame line color. Ranging 0 to 255.
 * @param	fillColor		Primitive fill color. Ranging -1 to 255.
 * @param	lineWeight		Primitive frame line weight. Ranging 1 to 255.
 * @param	primitiveShape	Primitive default shape as the primitiveShape_t
 *							enum defines.
 * @return	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 					- 	Operation is success.
 * @return	VGA_PIXEL_NOT_SET 				- 	Set pixel operation has failed.
 * @return	VGA_RADII_OUT_OF_BOUNDS			-	Input radii is out of bounds.
 * 												(radii > 0).
 * @return	VGA_LINE_COL_OUT_OF_BOUNDS		-	Input line color is out of
 * 												bounds. (0 to 255).
 * @return	VGA_FILL_COL_OUT_OF_BOUNDS		-	Input fill color is out of
 * 												bounds. (-1 to 255).
 * @return	VGA_LINE_WEIGHT_OUT_OF_BOUNDS	- 	Input line weight is out of
 * 												bounds. (1 to 255).
 *
 * @code{.c}
 * sPosition_t centerPos = {160, 120};
 * sRadii_t radii = (30, 50};
 * status_t status = VGA_P_drawPrimitive(	&centerPos,
 * 										&radii,
 * 										45,
 * 										VGA_COL_RED,
 * 										VGA_COL_TRANSPARENT,
 * 										3,
 * 										VGA_PENTAGON	);
 * if(status != VGA_SUCCESS) {
 * 	return status;
 * }
 * @endcode
 */
status_t VGA_P_drawPrimitive(	sPosition_t* 		centerPointPos,
								sRadii_t*			radii,
								uint16_t			rotationDegrees,
								color_t				lineColor,
								color_t				fillColor,
								uint8_t				lineWeight,
								primitiveShape_t	primitiveShape);

/**
 * @brief	Draws polygon on the VGA screen.
 *
 * This function will call VGA_L_setPolygonData() for processing. Can be used
 * if the user requires a custom polygon shape.
 *
 * @param	verticePos			Positions of the polygon vertices.
 * @param 	numberOfVertices	Total number of polygon vertices. Must be the
 * 								same as the array length of verticePos.
 * @param 	lineColor			Line color of the polygon. Ranging 0 to 255.
 * @param	fillColor 			Fill color of the polygon. Ranging -1 to 255.
 * @param	lineWeight			Weight of the line. Ranging 1 to 255.
 * @return	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 					- 	Operation is success.
 * @return	VGA_PIXEL_NOT_SET 				- 	Set pixel operation has failed.
 * @return	VGA_LINE_COL_OUT_OF_BOUNDS		-	Input line color is out of
 * 												bounds. (0 to 255).
 * @return	VGA_FILL_COL_OUT_OF_BOUNDS		-	Input fill color is out of
 * 												bounds. (-1 to 255).
 * @return	VGA_LINE_WEIGHT_OUT_OF_BOUNDS	- 	Input line weight is out of
 * 												bounds. (1 to 255).
 *
 * @code{.c}
 * sPosition_t verticePos[5] = {
 * 	{10, 10}, {20, 20}, {50, 50}, (30, 40}, {40, 80}
 * };
 * status_t status = VGA_P_drawPolygon(	verticePos,
 * 										5,
 * 										VGA_COL_BLACK,
 * 										VGA_COL_GREEN,
 * 										2	);
 * if(status != VGA_SUCCESS) {
 * 	return status;
 * }
 * @endcode
 */
status_t VGA_P_drawPolygon(	sPosition_t verticePos[],
							uint16_t	numberOfVertices,
							color_t		lineColor,
							color_t		fillColor,
							uint8_t		lineWeight);

#endif /* SHAPES_H_ */
/* End of file shapes.h */
