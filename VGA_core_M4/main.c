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
	sPosition_t charPos ={0,0};
//	int i;
//	for (i = 0; i < 73; ++i) {
//		VGA_L_processCharData(i+32,Size_24,Emoji, charPos, VGA_COL_WHITE);
//		charPos.x +=24;
//		if ((i%12)==0){
//			charPos.y+=22;
//			charPos.x=0;
//		}
//	}

	VGA_L_processStringData("WELKOM OP CHILLFEST 2016",Size_18,Bold,charPos,VGA_COL_RED);

	while(1) {

	}
}
/* End of file main.c */
