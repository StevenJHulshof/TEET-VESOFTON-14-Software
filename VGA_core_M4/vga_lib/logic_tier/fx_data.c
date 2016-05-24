/*******************************************************************************
 * Begin of file fx_data.c
 *
 * @author: Steven Hulshof
 * Created: 24/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Functions for adding screen effects to the VGA screen.
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fx_data.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
 * @brief	Adds a blooming effect to the VGA screen.
 *
 * @param	bloomInt	The intensity of the bloom effect.
 * @return	Status of operation.
 */
status_t VGA_FX_bloomScreen(bloomIntensity_t bloomInt) {

	status_t status = VGA_SUCCESS;
	color_t avg;
	uint8_t n;
	int x, y, xB, yB, r, b, g;

	// Loop through screen
	for(y = 0; y < VGA_DISPLAY_Y; y++) {
		for(x = 0; x < VGA_DISPLAY_X; x++) {

			// Reset values
			n = 0;
			r = 0;
			g = 0;
			b = 0;

			// Set bloom based on intensity
			for(yB = y-bloomInt; yB < y+bloomInt+1; yB++) {
				for(xB = x-bloomInt; xB < x+bloomInt+1; xB++) {

					// Check whether pixel is inside the screen
					if(xB > 0 && xB < VGA_DISPLAY_X && yB > 0 && yB < VGA_DISPLAY_Y) {
						sPosition_t pixelPos = {xB, yB};
						color_t color = VGA_L_getPixelData(&pixelPos);
						r += (color >> 5) & 0x07;
						g += (color >> 2) & 0x07;
						b += color & 0x03;
						n++;
					}
				}
			}

			avg = ((r/n)<<5)|((g/n)<<2)|(b/n);
			sPosition_t pixelPos = {x, y};
			status = VGA_L_setPixelData(&pixelPos, avg);
			if(status != VGA_SUCCESS) {
				return status;
			}
		}
	}

	return status;
}

/* End of file fx_data.c */
