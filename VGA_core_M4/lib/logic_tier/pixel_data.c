/*******************************************************************************
 * Begin of file pixel_data.c
 *
 * @author: Steven Hulshof
 * Created: 10/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Functions for manipulating the frame buffer.
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "pixel_data.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
status_t setPixelData(sPosition_t* position, color_t color) {

	// Set color to frame buffer
	VGA_RAM1[position->y*(VGA_DISPLAY_X+1)+position->x] = color;

	// Report status
	if(VGA_RAM1[position->y*(VGA_DISPLAY_X+1)+position->x] != color) {
		return VGA_FB_COLOR_NOT_SET;
	}

	return VGA_SUCCESS;
}

color_t getPixelData(sPosition_t* position) {

	// Get pixel data
	return VGA_RAM1[position->y*(VGA_DISPLAY_X+1)+position->x];
}

/* End of file pixel_data.c */
