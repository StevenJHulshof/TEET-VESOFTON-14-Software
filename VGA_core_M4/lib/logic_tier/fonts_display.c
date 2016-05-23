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
#include "pixel_data.h"

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
	sBitmapdata.ByteWidth = sFontstyle.GlyphBytesWidth;
	sBitmapdata.CharHeight = sFontstyle.GlyphHeight;
	sBitmapdata.CharWidth = *(sFontstyle.GlyphWidth+shift);

	return sBitmapdata;
 }

 sBitmap_t processCharData(	char ascii_char, charSize_t size,
 							charStyle_t style,
 							sPosition_t sStartPos,
 							color_t color){

	 sBitmap_t sChardata;
	 sPosition_t sNextPos = sStartPos;
	 uint8_t shift = 0;
	 int i;
	 int j;

	 sChardata = getBitmap(ascii_char, size, style);

	 uint8_t* pX = sChardata.FirstByte;
	 uint8_t* pY = sChardata.FirstByte;

	 //for loop for y-axis
	 for (i = 0; i < sChardata.CharHeight; i++,  sNextPos.y++)
	 {
		 //for loop for x-axis
		 for (j = 0; j < sChardata.CharWidth; j++, sNextPos.x++)
		 {
			 //bitwise compare MSB with bitmap, shift for each pixel
			 if(0x80 & *pX<<(j-shift))
			 {
				 VGA_setPixelData(&sNextPos, color);
			 }
			 //need to increment pointer for wide chars
			 if (j == 7)
			 {
				 pX++;
				 shift = 8;
			 }
			 //prepare for 3-byte wide chars
			 if (j == 15)
			 {
				 pX++;
				 shift = 16;
			 }
		 }
		 //skip bytes according to bytewidth
		 pY = pY+sChardata.ByteWidth;
		 pX = pY;
		 sNextPos.x = sStartPos.x;
		 shift = 0;
	 }

	 return sChardata;
 }

// void processStringData(	char* ascii_string,
// 							uint8_t strLength,
// 							charSize_t size,
// 							charStyle_t style,
// 							sPosition_t sStartPos,
// 							color_t color){
//
//
//	 for(i = 0; i < strLength; i++)
//	 {
//		 if(ascii_string[i] < 32)
//			 if
//	 }
//
// }

 /* End of file fonts_display.c */
