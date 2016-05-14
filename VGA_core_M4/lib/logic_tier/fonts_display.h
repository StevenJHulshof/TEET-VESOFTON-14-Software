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

 /*******************************************************************************
  * Data structures
  ******************************************************************************/

/** @brief Character structure */
typedef struct {
	uint8_t * FirstByte;
	uint8_t CharWidth;
	uint8_t CharHeight;
} sChar_t;

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
  * @brief	Get bitmapdata from memory for ASCII character
  *
  * @param size	Select font size as defined in enumerated type charSize_t
  * @param styleSelect font style as defined in enumerated type charStyle_t
  * @return	Structure with chardata according to enumerated type sChar_t
  */
sChar_t getBitmap(char ascii_char, charSize_t size, charStyle_t style);

 /* End of file fonts_display.h */
