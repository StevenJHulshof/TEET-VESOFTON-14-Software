/*******************************************************************************
 * Begin of file text.h
 *
 * @author: Lukas ten Hove
 * Created: 23/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief 	This file contains functions utilizing the font_display library.
 *
 * This file contains a print string function, which can be used to print
 * ASCII strings on the VGA screen.
 ******************************************************************************/

#ifndef TEXT_H_
#define TEXT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fonts_display.h"

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief	Print a string at given pixel coordinates
 *
 * This function will call the VGA_L_processStringData() function to print a
 * string of text onto the screen.
 *
 * @param stringPos	Select start position using the sPosition_t structure.
 * @param string	String to print onto the screen.
 * @param size		Select font style as defined in enumerated type charSize_t.
 * @param style 	Select font style as defined in enumerated type charStyle_t.
 * @param color		Select font style as defined in enumerated type color_t or
 * 					by entering an 8-bit value.
 *
 * @return	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 					- 	Operation is success.
 * @return	VGA_STRING_INVALID_FONTSTYLE	- 	Given font style does not exist.
 * @return	VGA_STRING_INVALID_FONTSIZE		- 	Given font size does not exist.
 * @return	GA_STRING_COL_OUT_OF_BOUNDS		-	Input font color is out of
 * 												bounds. (0 to 255).
 *
 * @code{.c}
 * sPosition_t pixelPos = {100, 100};
 * status_t status = VGA_P_printString(	&pixelPos,
 * 										"Example string.\n",
 * 										Size_24,
 * 										Regular,
 * 										VGA_COL_GREEN	);
 * if(status != VGA_SUCCESS) {
 * 	return status;
 * }
 * @endcode
 */
status_t VGA_P_printString(	sPosition_t stringPos,
							char* 		string,
							charSize_t 	size,
							charStyle_t style,
							color_t 	color	);

#endif /* TEXT_H_ */
/* End of file text.h */
