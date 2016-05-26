/*******************************************************************************
 * Begin of file shapes.c
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
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "pixel.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
status_t VGA_P_drawPixel(	sPosition_t* pixelPos,
                            color_t color	) {

	status_t status = VGA_SUCCESS;

	// Check whether arguments are inside bounds
	if(	pixelPos->x < 0 || pixelPos->y < 0 ||
		pixelPos->x >= VGA_DISPLAY_X || pixelPos->y >= VGA_DISPLAY_Y) {

		return VGA_PIXEL_OUT_OF_SCREEN;
	}
	if(color < 0 || color > 0xFF) {
		return VGA_LINE_COL_OUT_OF_BOUNDS;
	}

	// Set pixel data
	status = VGA_L_setPixelData(pixelPos, color);

	return status;
}

color_t VGA_P_getPixelColor(	sPosition_t* pixelPos	) {

	// Get pixel data
	color_t color = VGA_L_getPixelData(pixelPos);

	return color;
}

status_t VGA_P_fillScreen(color_t color) {

	status_t status = VGA_SUCCESS;

	// Process screen data
	status = VGA_L_processScreenData(color);

	return status;
}

/* End of file shapes.c */
