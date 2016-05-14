/******************************************************************************
 * Begin of file fonts_display.c
 * @author: Niek Klaverstijn.
 * @version: 1.0
 * Created: 14-05-2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Functions for retrieving bitmap data from memory and displaying them
 * on the screen.
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "system.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
 sChar_t getBitmap(char ascii_char, charSize_t size, charStyle_t style){

		fontStyle_t fontStyle;
		uint8_t* bitmapArray;
		sChar_t bitmapData;
		uint8_t shift;

		if (style == Regular)
		{
			if (size == Size_18) fontStyle = FontStyle_Roboto18;
			if (size == Size_12) fontStyle = FontStyle_Roboto12;
		}
		if (style == Bold)
		{
			if (size == Size_18) fontStyle = FontStyle_Roboto18Bold;
			if (size == Size_12) fontStyle = FontStyle_Roboto12;
		}

		//get address from bitmapram
		bitmapArray = fontStyle.GlyphBitmaps;
		//increment pointer to asked ascii char
		shift = ascii_char-fontStyle.FirstAsciiCode;
		bitmapData.FirstByte = bitmapArray+shift;

		bitmapData.CharHeight = fontStyle.GlyphHeight;
		bitmapData.CharWidth = *(fontStyle.GlyphWidth+shift);

		return bitmapData;
 }

 /* End of file fonts_display.c */
