 /*******************************************************************************
 * Begin of file main.c
 *
 * @author: Lukas ten Hove, Steven Hulshof, Niek Klaverstijn.
 * @version: 1.0
 * Created: 19/04/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Main file of VGA_core project.
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "main.h"
#include "system.h"
#include "pixel_data.h"
#include <math.h>

/*******************************************************************************
 * Main
 ******************************************************************************/
int main(void) {

	SystemInit();
	UB_VGA_Screen_Init();

	sPosition_t sPos;
	sBitmap_t sTempchar;
//
//		VGA_setPixelData(&sPos, VGA_COL_BLUE);
	VGA_processScreenData(VGA_COL_RED);


	int x,y;
	for(x = 100, y = 100; x < 200; x++, y++) {
			sPos.x = x;
			sPos.y = y;
			VGA_setPixelData(&sPos, VGA_COL_BLUE);

	}

	sPosition_t sPos2 = {100, 100};
	color_t clr = VGA_getPixelData(&sPos2);
	for(x = 200, y = 100; x < 300; x++, y++) {
				sPos.x = x;
				sPos.y = y;
				VGA_setPixelData(&sPos, clr);

		}

	sTempchar = getBitmap('$',Size_18,Regular);

	while(1) {



	}
}
/* End of file main.c */
