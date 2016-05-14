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
}sChar_t;

/*******************************************************************************
 * Functions
 ******************************************************************************/

 /* End of file fonts_display.h */

 
