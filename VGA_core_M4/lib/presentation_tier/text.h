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
 * @param size	Select font size as defined in enumerated type charSize_t
 * @param style Select font style as defined in enumerated type charStyle_t
 * @param sPos  Start position of upperleft corner of char
 * @parm color color of the char
 * @return	Structure with chardata according to enumerated type sBitmap_t
 */
status_t VGA_P_printString(	sPosition_t stringPos,
						char* string,
						charSize_t size,
						charStyle_t style,
						color_t color	);

#endif /* TEXT_H_ */
/* End of file text.h */
