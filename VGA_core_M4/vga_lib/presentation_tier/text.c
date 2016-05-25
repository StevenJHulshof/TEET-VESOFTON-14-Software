/*******************************************************************************
 * Begin of file text.c
 *
 * @author: Lukas ten Hove
 * Created: 23/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief 	This file contains functions utilizing the font_display library.
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "text.h"

/*******************************************************************************
 * Functions
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
						color_t color	) {

	status_t status = VGA_SUCCESS;

//	// Check whether arguments are inside bounds
//	if(	size != Size_12 || size!= Size_18) {
//		return VGA_STRING_INVALID_FONTSIZE;
//	}
//	if( style != Bold || style != Regular) {
//		return VGA_STRING_INVALID_FONTSTYLE;
//	}
//	if(color < 0 || color > 0xFF) {
//		return VGA_STRING_COL_OUT_OF_BOUNDS;
//	}

	// call string processing function
	VGA_L_processStringData(string, size, style, stringPos, color);

	return status;
}

/* End of file text.c */
