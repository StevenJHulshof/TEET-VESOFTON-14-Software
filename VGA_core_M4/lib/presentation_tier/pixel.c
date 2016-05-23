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
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "pixel.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
 * @brief	Draws pixel on VGA screen.
 *
 * @param	pixelPos	Position of the pixel, contains x and y coordinates.
 * @param	color		Color of the pixel.
 * @return	Status of operation.
 */
status_t VGA_drawPixel(sPosition_t* pixelPos, color_t color) {

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
	status = VGA_setPixelData(pixelPos, color);

	return status;
}

/* End of file shapes.c */
