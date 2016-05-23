/******************************************************************************
 * Begin of file fonts_display.h
 * @author: Niek Klaverstijn
 * @version: 1.0
 * Created: 14-05-2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Functions for retrieving bitmap data from memory and displaying them
 * on the screen.
 ******************************************************************************/

#ifndef FONT_DISPLAY_H_
#define FONT_DISPLAY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "system.h"
#include "fontlibrary.h"

/*******************************************************************************
 * Data structures
 ******************************************************************************/

/** @brief Character structure */
typedef struct {
	uint8_t* FirstByte;
	uint8_t ByteWidth;
	uint8_t CharWidth;
	uint8_t CharHeight;
} sBitmap_t;

/*******************************************************************************
 * Enumerators
 ******************************************************************************/
 typedef enum {
	Size_18,
	Size_12
}charSize_t;

 typedef enum {
	Regular,
	Bold
}charStyle_t;

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
 /**
  * @brief	Get bitmapdata from gememory for ASCII character
  *
  * @param size	Select font size as defined in enumerated type charSize_t
  * @param style Select font style as defined in enumerated type charStyle_t
  * @return	Structure with chardata according to enumerated type sBitmap_t
  */
sBitmap_t getBitmap(char ascii_char, charSize_t size, charStyle_t style);

/**
 * @brief	Get bitmapdata from gememory for ASCII character
 *
 * @param size	Select font size as defined in enumerated type charSize_t
 * @param style Select font style as defined in enumerated type charStyle_t
 * @param sPos  Start position of upperleft corner of char
 * @parm color color of the char
 * @return	Structure with chardata according to enumerated type sBitmap_t
 */
sBitmap_t processCharData(	char ascii_char,
							charSize_t size,
							charStyle_t style,
							sPosition_t sStartPos,
							color_t color);

/**
 * @brief	Create string with processchardata
 *
 * @param size	Select font size as defined in enumerated type charSize_t
 * @param style Select font style as defined in enumerated type charStyle_t
 * @param sPos  Start position of upperleft corner of char
 * @parm color color of the char
 * @return	Structure with chardata according to enumerated type sBitmap_t
 */
void processStringData(	char* ascii_string,
							uint8_t strLength,
							charSize_t size,
							charStyle_t style,
							sPosition_t sStartPos,
							color_t color);

#endif /* FONT_DISPLAY_H_ */
 /* End of file fonts_display.h */
