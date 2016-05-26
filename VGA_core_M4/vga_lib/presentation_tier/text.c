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
 * This file contains a print string function, which can be used to print
 * ASCII strings on the VGA screen.
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "text.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
status_t VGA_P_printString(	sPosition_t stringPos,
							char*	 	string,
							charSize_t 	size,
							charStyle_t style,
							color_t 	color	) {

	status_t status = VGA_SUCCESS;

	// Check whether arguments are inside bounds
	if(	size != Size_12 && size != Size_18 && size != Size_24) {
		return VGA_STRING_INVALID_FONTSIZE;
	}
	if( style != Bold && style != Regular && style != Emoji) {
		return VGA_STRING_INVALID_FONTSTYLE;
	}
	if(color < 0 || color > 0xFF) {
		return VGA_STRING_COL_OUT_OF_BOUNDS;
	}

	// call string processing function
	VGA_L_processStringData(string, size, style, stringPos, color);

	return status;
}

/* End of file text.c */
