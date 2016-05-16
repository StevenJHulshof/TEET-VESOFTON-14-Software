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
#include "fonts_display.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
 sBitmap_t getBitmap(char ascii_char, charSize_t size, charStyle_t style){

	fontStyle_t sFontstyle;
	uint8_t* bitmapArray;
	sBitmap_t sBitmapdata;
	uint8_t shift;

	if (style == Regular)
	{
		if (size == Size_18) sFontstyle = FontStyle_Roboto18;
		if (size == Size_12) sFontstyle = FontStyle_Roboto12;
	}
	if (style == Bold)
	{
		if (size == Size_18) sFontstyle = FontStyle_Roboto18Bold;
		if (size == Size_12) sFontstyle = FontStyle_Roboto12;
	}

	//get address from bitmap in sram
	bitmapArray = sFontstyle.GlyphBitmaps;
	//increment pointer to asked ascii char
	shift = ascii_char-sFontstyle.FirstAsciiCode;

	//get address of first byte by incrementing pointer with shift times size of char bitmap
	sBitmapdata.FirstByte = bitmapArray+(shift*sFontstyle.GlyphHeight*sFontstyle.GlyphBytesWidth);

	sBitmapdata.CharHeight = sFontstyle.GlyphHeight;
	sBitmapdata.CharWidth = *(sFontstyle.GlyphWidth+shift);

	return sBitmapdata;
 }

 sBitmap_t processCharData(	char ascii_char, charSize_t size,
 							charStyle_t style,
 							sPosition_t sStartPos,
 							color_t color){

	 sBitmap_t sChardata;
	 sPosition_t sNextPos;
	 int i;
	 int j;

	 sChardata = getBitmap(ascii_char, size, style);

	 for (i = sStartPos.y; (sNextPos.y-sStartPos.y) < sChardata.CharHeight; ++i)
	 {
		 for (j = sStartPos.x; (sStartPos.x-sNextPos.x) < (sChardata.CharWidth*8); ++j)
		 {
			 if(0x80 & *sChardata.FirstByte<<j)
			 {
				 VGA_setPixelData(sNextPos, color);
			 }
		 }
		 sNextPos.x = sStartPos.x;
	 }
 }

 /* End of file fonts_display.c */
