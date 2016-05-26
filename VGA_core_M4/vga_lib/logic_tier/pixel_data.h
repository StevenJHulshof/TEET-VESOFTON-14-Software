/*******************************************************************************
 * Begin of file pixel_data.h
 *
 * @author: Steven Hulshof
 * Created: 10/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Functions for manipulating the VGA_RAM.
 *
 * These functions are present in the logic layer of the VGA library. They will
 * process the pixel data input in the presentation layer.
 ******************************************************************************/

#ifndef PIXEL_DATA_H_
#define PIXEL_DATA_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "system.h"
#include "vga_screen.h"

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief	Set pixel color into frame buffer.
 *
 * This functions is called from VGA_P_drawPixel for processing. Writes
 * directly into the VGA_RAM1 DMA buffer to set pixel color.
 *
 * @param position	Position structure containing x and y coordinates.
 * @param color		Color of the pixel. Ranging 0 to 255.
 *
 * @return	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 		-	Operation is success.
 * @return	VGA_PIXEL_NOT_SET 	-	Set pixel operation has failed.
 */
status_t VGA_L_setPixelData(	sPosition_t*	position,
								color_t 		color	);

/**
 * @brief	Get pixel data from frame buffer.
 *
 * Returns the pixel color from the VGA_RAM1 DMA buffer. This function is
 * called in VGA_P_getPixelColor() for processing and VGA_L_setPixelData()
 * for checking whether the pixel has been set correctly.
 *
 * @param 	position	Position structure containing x and y coordinates.
 *
 * @return 	Color of the pixel. Ranging 0 to 255.
 */
color_t VGA_L_getPixelData(	sPosition_t* position	);

/**
 * @brief	Fills screen with the input color.
 *
 * Is called from VGA_P_fillScreen() for processing the screen fill. Calls
 * VGA_L_setPixelData() to set individual pixels.
 *
 * @param 	color	Color of the screen fill. Accepts value ranging
 * 					0 to 255.
 *
 * @return	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 		- 	Operation is success.
 * @return	VGA_PIXEL_NOT_SET 	- 	Set pixel operation has failed.
 */
status_t VGA_L_processScreenData(	color_t color	);

#endif /* PIXEL_DATA_H_ */
/* End of file pixel_data.h */
