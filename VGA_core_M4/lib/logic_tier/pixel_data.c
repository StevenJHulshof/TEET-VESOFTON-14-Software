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
status_t VGA_setPixelData(sPosition_t* position, color_t color) {

	// Set color to frame buffer
	VGA_RAM1[position->y*(VGA_DISPLAY_X+1)+position->x] = color;

	// Report status
	if(VGA_getPixelData(position) != color) {
		return VGA_COLOR_NOT_SET;
	}

	return VGA_SUCCESS;
}

color_t VGA_getPixelData(sPosition_t* position) {

	// Get pixel data
	return VGA_RAM1[(position->y*(VGA_DISPLAY_X+1))+position->x];
}

status_t VGA_processScreenData(color_t color) {

	uint8_t y;
	uint16_t x;
	sPosition_t sPos;
	status_t status;

	// Fill screen with color
	for(y = 0; y < VGA_DISPLAY_Y; y++) {
		for(x = 0; x < VGA_DISPLAY_X; x++) {

			// Set coordinates
			sPos.x = x;
			sPos.y = y;

			// Set pixel
			status = VGA_setPixelData(&sPos, color);

			// Report status
			if(status != VGA_SUCCESS) {
				return status;
			}
		}
	}

	return status;
}

/* End of file pixel_data.c */
