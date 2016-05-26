/*******************************************************************************
 * Begin of file shapes.c
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "shapes.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
status_t VGA_P_drawLine(	sPosition_t endPointPos[2],
							color_t 	lineColor,
							uint8_t 	lineWeight	) {

	status_t status = VGA_SUCCESS;

	// Check whether arguments are inside bounds
	if(lineColor < 0 || lineColor > 0xFF) {
		return VGA_LINE_COL_OUT_OF_BOUNDS;
	}
	if(lineWeight < 1) {
		return VGA_LINE_WEIGHT_OUT_OF_BOUNDS;
	}

	// Process line data
	status = VGA_L_setLineData(endPointPos, lineColor, lineWeight);

	return status;
}

status_t VGA_P_drawPrimitive(	sPosition_t* 		centerPointPos,
								sRadii_t*			radii,
								uint16_t			rotationDegrees,
								color_t				lineColor,
								color_t				fillColor,
								uint8_t				lineWeight,
								primitiveShape_t	primitiveShape) {

	status_t status = VGA_SUCCESS;

	// Check whether arguments are inside bounds
	status = UTIL_checkBoundaries(	radii,
									lineColor,
									fillColor,
									lineWeight	);

	// Report status
	if(status != VGA_SUCCESS) {
		return status;
	}

	// Process primitive data
	status = VGA_L_setPrimitiveData(	centerPointPos,
									radii,
									rotationDegrees,
									lineColor,
									fillColor,
									lineWeight,
									primitiveShape	);

	return status;
}

status_t VGA_P_drawPolygon(	sPosition_t verticePos[],
							uint16_t	numberOfVertices,
							color_t		lineColor,
							color_t		fillColor,
							uint8_t		lineWeight) {

	status_t status = VGA_SUCCESS;
	sRadii_t radiiDummy = {0, 0};

	// Check whether arguments are inside bounds
	status = UTIL_checkBoundaries(	&radiiDummy,
									lineColor,
									fillColor,
									lineWeight	);

	// Report status
	if(status != VGA_SUCCESS) {
		return status;
	}

	// Process polygon data
	status = VGA_L_setPolygonData(verticePos,
								numberOfVertices,
								lineColor,
								fillColor,
								lineWeight);

	return status;
}

/* End of file shapes.c */
