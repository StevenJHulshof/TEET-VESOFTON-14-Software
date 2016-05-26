/*******************************************************************************
 * Begin of file shapes_data.h
 *
 * @author: Steven Hulshof, Lukas ten Hove
 * Created: 12/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Functions for processing the shapes.
 *
 * These functions are present in the logic layer of the VGA library. They will
 * process the data input in the presentation layer.
 ******************************************************************************/

#ifndef SHAPES_DATA_H_
#define SHAPES_DATA_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "system.h"
#include "pixel_data.h"
#include "utility.h"

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief	Processes line weight data to pixel position.
 *
 * This function is called by VGA_L_setLineData() for processing the line
 * weight. The line weight is processed with the VGA_L_setPrimitiveData() to
 * create a hexagon shape around the line pixels.
 *
 * @param	centerPointPos	Pixel position around which the line weight should
 * 							be calculated.
 * @param	lineColor		Color of the line. Ranging 0 to 255.
 * @param	lineWeight		Weight of the line. Ranging 1 to 255.
 *
 * @return 	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 		- 	Operation is success.
 * @return	VGA_PIXEL_NOT_SET 	- 	Set pixel operation has failed.
 */
status_t VGA_L_setLineWeight( sPosition_t*	centerPointPos,
							  color_t		lineColor,
							  uint8_t		lineWeight	);
/**
 * @brief	Processes line data to pixel positions.
 *
 * This function is called by VGA_P_drawLine() or VGA_L_setPolygonframe()
 * for processing. After calculating the line data using the Bresenham
 * algorithm this function will call VGA_L_setPixelData() for draw the line
 * into the VGA_RAM1 DMA buffer.
 *
 * @param 	endPointPos		End point positions of the line.
 * @param 	lineColor		Color of the line. Ranging 0 to 255.
 * @param	lineWeight		Weight of the line in pixels. Ranging 1 to 255.
 *
 * @return	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 		- 	Operation is success.
 * @return	VGA_PIXEL_NOT_SET 	- 	Set pixel operation has failed.
 */
status_t VGA_L_setLineData(	sPosition_t endPointPos[2],
							color_t 	lineColor,
							uint8_t		lineWeight	);

/**
 * @brief	Fills polygon with fillColor parameter.
 *
 * This function is called by VGA_L_setPolygonData() for processing the
 * polygon fill. It uses the efficient version of the Point-In-Polygon
 * algorithm to calculate the fill pixel positions. After calculations it will
 * call the VGA_L_setPixelData() for processing.
 *
 * @param	vertices			Positions of the polygon vertices.
 * @param 	numberOfVertices	Total number of polygon vertices. Must be the
 * 								same as the array length of verticePos.
 * @param	imageBorder			Image border constraints. These consist of the
 * 								minimum x,y coordinates and the maximum x,y
 * 								coordinates.
 * @param	fillColor 			Fill color of the polygon. Ranging 0 to 255.
 *
 * @return	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 		- 	Operation is success.
 * @return	VGA_PIXEL_NOT_SET 	- 	Set pixel operation has failed.
 */
status_t VGA_L_setPolygonFill(	sPosition_t vertices[],
								uint16_t 	numberOfVertices,
								sPosition_t imageBorder[2],
								color_t 	fillColor	);

/**
 * @brief	Set polygon frame line.
 *
 * This function is called by VGA_L_setPolygonData() for processing the frame
 * lines. Using the vertices as line end points, this function calls
 * VGA_L_setLineData to draw the polygon frame lines.
 *
 * @param	verticePos			Positions of the polygon vertices.
 * @param 	numberOfVertices	Total number of polygon vertices. Must be the
 * 								same as the array length of verticePos.
 * @param 	lineColor			Line color of the polygon. Ranging 0 to 255.
 * @param	lineWeight			Weight of the line. Ranging 1 to 255.
 *
 * @return	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 		- 	Operation is success.
 * @return	VGA_PIXEL_NOT_SET 	- 	Set pixel operation has failed.
 */
status_t VGA_L_setPolygonFrame(	sPosition_t verticePos[],
								uint16_t 	numberOfVertices,
								color_t 	lineColor,
								uint8_t		lineWeight	);

/**
 * @brief	Process polygon data to pixel position.
 *
 * This function is called by VGA_P_drawPolygon() for processing and
 * VGA_L_setPrimitiveData() for processing default primitive shapes. The
 * polygon is set by creating the fill by calling VGA_L_setPolygonFill() and
 * by creating the frame by calling the VGA_L_setPolygonFrame().
 *
 * @param	verticePos			Positions of the polygon vertices.
 * @param 	numberOfVertices	Total number of polygon vertices. Must be the
 * 								same as the array length of verticePos.
 * @param 	lineColor			Line color of the polygon. Ranging 0 to 255.
 * @param	fillColor 			Fill color of the polygon. Ranging -1 to 255.
 * @param	lineWeight			Weight of the line. Ranging 1 to 255.
 *
 * @return	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 		- 	Operation is success.
 * @return	VGA_PIXEL_NOT_SET 	- 	Set pixel operation has failed.
 */
status_t VGA_L_setPolygonData(	sPosition_t	verticePos[],
								uint16_t	numberOfVertices,
								color_t		lineColor,
								color_t		fillColor,
								uint8_t		lineWeight	);

/**
 * @brief	Process primitive data to pixel position.
 *
 * This function is called by VGA_P_drawPrimitive() for processing. The
 * primitive is calculated using an ellipse calculation. The different shapes
 * are created using different sample sizes during the ellipse calculation.
 * After the calculations, this function will call VGA_L_setPolygonData() to
 * set the primitive shape in the VGA_RAM1 DMA buffer.
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
 *
 * @return	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 		- 	Operation is success.
 * @return	VGA_PIXEL_NOT_SET 	- 	Set pixel operation has failed.
 */
status_t VGA_L_setPrimitiveData(	sPosition_t* 		centerPointPos,
									sRadii_t* 			radii,
									uint16_t 			rotationDegrees,
									color_t				lineColor,
									color_t				fillColor,
									uint8_t				lineWeight,
									primitiveShape_t	primitiveShape	);

#endif /* SHAPES_DATA_H_ */
/* End of file shapes_data.h */
