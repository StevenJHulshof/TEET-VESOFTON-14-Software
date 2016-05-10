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

// TODO add real framebuffer
color_t frameBuffer[10][10];

/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
 * @brief	Set pixel color into frame buffer.
 *
 * @param position	Position structure containing X and Y coördinates.
 * @param color		Color of the pixel.
 * @return	Status of operation.
 */
status_t setPixelData(sPosition_t* position, color_t color) {

	// Set color to frame buffer.
	frameBuffer[position->x][position->y] = color;

	// Report status
	if(frameBuffer[position->x][position->y] != color) {
		return VGA_FB_COLOR_NOT_SET;
	}

	return VGA_SUCCESS;
}

/* End of file pixel_data.c */
