/******************************************************************************
 * Begin of file fonts_display.h
 * @author: Niek Klaverstijn
 * @version: 1.0
 * Created: 14-05-2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief	Contains string manipulation functions.
 *
 * This file contains functions for retrieving bitmap data from memory and
 * displaying them on the screen.
 ******************************************************************************/

#ifndef FONT_DISPLAY_H_
#define FONT_DISPLAY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "system.h"
#include "font_library.h"

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief	Get bitmapdata from gememory for ASCII character
 *
 * This function is called by VGA_L_processCharData() to get the bitmap
 * of the character needed.
 *
 * @param 	ascii_char	Character represented in ASCII.
 * @param 	size		Select font size as defined in enumerated type
 * 						charSize_t
 * @param 	style 		Select font style as defined in enumerated type
 * 						charStyle_t
 *
 * @return	Structure with chardata according to enumerated type sBitmap_t
 */
sBitmap_t* VGA_L_getBitmap(	char 		ascii_char,
							charSize_t 	size,
							charStyle_t style	);

/**
 * @brief	Get bitmapdata from gememory for ASCII character
 *
 * This function is called by VGA_L_processStringData for processing
 * individual characters. This function will call the VGA_L_setPixelData() to
 * set the characters in VGA_RAM1 DMA buffer.
 *
 * @param	ascii_char	Character represented in ASCII.
 * @param 	size		Select font size as defined in enumerated type
 * 						charSize_t
 * @param 	style 		Select font style as defined in enumerated type
 * 						charStyle_t
 * @param 	sStartPos  	Start position of upperleft corner of char
 * @param 	color 		Color of the character. Ranging 0 to 255.
 *
 * @return	Structure with chardata according to enumerated type sBitmap_t
 */
sBitmap_t* VGA_L_processCharData(	char 		ascii_char,
									charSize_t 	size,
									charStyle_t style,
									sPosition_t sStartPos,
									color_t 	color);

/**
 * @brief	Creates string from input parameters.
 *
 * This function is called by VGA_P_printString() for processing the input
 * string. It will call VGA_L_processCharData for processing individual
 * characters.
 *
 * @param ascii_string	String represented in ASCII.
 * @param size			Select font size as defined in enumerated type
 * 						charSize_t.
 * @param style 		Select font style as defined in enumerated type
 * 						charStyle_t.
 * @param sStartPos		Start position of upper left corner of the string.
 * @param color 		Color of the string.
 *
 * @return	Structure with chardata according to enumerated type sBitmap_t
 */
void VGA_L_processStringData(	char* 		ascii_string,
								charSize_t 	size,
								charStyle_t style,
								sPosition_t sStartPos,
								color_t 	color	);

#endif /* FONT_DISPLAY_H_ */
 /* End of file fonts_display.h */
