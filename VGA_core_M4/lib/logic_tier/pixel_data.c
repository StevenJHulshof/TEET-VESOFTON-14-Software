/*******************************************************************************
 * Begin of file pixel_data.c
 *
 * @author: Steven Hulshof
 * Created: 10/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Functions for manipulating the VGA_RAM.
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "pixel_data.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
status_t VGA_setPixelData(	sPosition_t* 	position,
							color_t 		color	) {

	if(	position->x >= 0 && position->x < VGA_DISPLAY_X &&
		position->y >= 0 && position->y < VGA_DISPLAY_Y		) {

		// Set color to frame buffer
		VGA_RAM1[(int) position->y*(VGA_DISPLAY_X+1)+ (int) position->x] = color;

		// Report status
		if(VGA_getPixelData(position) != color) {
			return VGA_PIXEL_NOT_SET;
		}
	}

	return VGA_SUCCESS;
}

color_t VGA_getPixelData(	sPosition_t* position	) {

	// Get pixel data
	return VGA_RAM1[(int) (position->y*(VGA_DISPLAY_X+1))+ (int) position->x];
}

status_t VGA_processScreenData(	color_t color	) {

	sPosition_t sPos;
	status_t 	status;
	uint8_t 	y;
	uint16_t 	x;

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
