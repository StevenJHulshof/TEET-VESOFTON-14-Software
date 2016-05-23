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
 * @param	pixelPos	Position of the pixel, contains x and y coordinates.
 * @param	color		Color of the pixel.
 * @return	Status of operation.
 */
status_t VGA_drawPixel(sPosition_t* pixelPos, color_t color);

#endif /* PIXEL_H_ */
/* End of file pixel.h */
