/*******************************************************************************
 * Begin of file pixel.h
 *
 * @author: Steven Hulshof
 * Created: 23/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief 	This file contains the draw functions of the VGA lib pixels.
 *
 * The functionalities range from drawing a single a pixel on the screen to
 * filling the entire screen with a color and reading a single pixel color.
 ******************************************************************************/

#ifndef PIXEL_H_
#define PIXEL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "pixel_data.h"

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief	Draws pixel on VGA screen.
 *
 * This function will call the VGA_L_setPixelData() for processing. Can be used
 * if the user requires a single pixel operation.
 *
 * @param	pixelPos	Position of the pixel. Contains x and y coordinates.
 * @param	color		Color of the pixel. Ranging 0 to 255.
 *
 * @return	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 				- 	Operation is success.
 * @return	VGA_PIXEL_NOT_SET 			- 	Set pixel operation has failed.
 * @return	VGA_PIXEL_OUT_OF_SCREEN 	- 	Input pixel position is outside
 * 											screen bounds.
 * @return	VGA_LINE_COL_OUT_OF_BOUNDS	-	Input line color is out of bounds.
 * 											(0 to 255).
 *
 * @code{.c}
 * sPosition_t pixelPos = {100, 100};
 * status_t status = VGA_P_drawPixel(&pixelPos, VGA_COL_RED);
 * if(status != VGA_SUCCESS) {
 * 	return status;
 * }
 * @endcode
 */
status_t VGA_P_drawPixel(	sPosition_t* 	pixelPos,
							color_t 		color	);

/**
 * @brief	Get pixel color from pixel position.
 *
 * This function will call VGA_L_getPixelData() for processing. Can be used
 * if the user requires the color of a single pixel.
 *
 * @param	pixelPos	Position of the pixel. Contains x and y coordinates.
 *
 * @return	color		Color of the pixel. Ranging 0 to 255.
 *
 * @code{.c}
 * sPosition_t pixelPos = {100, 100};
 * color_t pixelColor = VGA_P_getPixelColor(&pixelPos);
 * @endcode
 */
color_t VGA_P_getPixelColor(	sPosition_t* pixelPos	);

/**
 * @brief	Fills screen with input color.
 *
 * This function will call VGA_L_processScreenData() for processing. Can be used
 * if the user requires a filled screen consisting of one color.
 *
 * @param	color	Color of the screen fill. Ranging 0 to 255.
 *
 * @return	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 		- 	Operation is success.
 * @return	VGA_PIXEL_NOT_SET 	- 	Set pixel operation has failed.
 *
 * @code{.c}
 * status_t status = VGA_P_fillScreen(VGA_COL_BLUE);
 * if(status != VGA_SUCCESS) {
 * 	return status;
 * }
 * @endcode
 */
status_t VGA_P_fillScreen(	color_t color	);

#endif /* PIXEL_H_ */
/* End of file pixel.h */
