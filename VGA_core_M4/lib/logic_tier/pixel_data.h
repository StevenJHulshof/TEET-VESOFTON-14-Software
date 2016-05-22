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
 * @param position	Position structure containing X and Y coordinates.
 * @param color		Color of the pixel.
 * @return	Status of operation.
 */
status_t VGA_setPixelData(	sPosition_t* position,
							color_t color	);

/**
 * @brief	Get pixel data from frame buffer.
 *
 * @param position	Position structure containing X and Y coordinates.
 * @return color	Color of the pixel.
 */
color_t VGA_getPixelData(	sPosition_t* position	);

/**
 * @brief	Fills screen with the input color.
 *
 * @param color	Color of the pixel.
 * @return	Status of operation.
 */
status_t VGA_processScreenData(	color_t color	);

#endif /* PIXEL_DATA_H */
/* End of file pixel_data.h */
