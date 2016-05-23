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
#include "vga_lib.h"
#include "fonts_display.h"

/*******************************************************************************
 * Main
 ******************************************************************************/
int main(void) {

	SystemInit();
	VGA_D_screenInit();
	sPosition_t charPos ={100,100};

	VGA_L_processStringData("Koffie?@NU!!!$#@!$#@jajajaja$",Size_18,Regular, charPos, VGA_COL_BLUE);

	while(1) {
	}
}
/* End of file main.c */
