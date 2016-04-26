 /*******************************************************************************
 * Begin of file main.c
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
#include "stm32_ub_vga_screen.h"
#include <math.h>

/*******************************************************************************
 * Main
 ******************************************************************************/
int main(void) {
	
	// System speed to 168MHz
	SystemInit(); 

	// Init VGA-Screen
	UB_VGA_Screen_Init(); 

	UB_VGA_FillScreen(VGA_COL_BLACK);
	int x, y, c = 0;
	for(y=0; y<280; y++) {
		for(x=0; x<320; x++, c++) {
			if(c > 255) c=0;
			UB_VGA_SetPixel(x, y, c);
		}
	}


  while(1) {

  }
}
/* End of file main.c */

