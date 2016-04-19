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
	UB_VGA_SetPixel(10,10,10);

  while(1) {

  }
}
/* End of file main.c */

