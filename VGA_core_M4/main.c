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
#include "demo.h"
#include "vga_screen.h"

/*******************************************************************************
 * Main
 ******************************************************************************/
int main(void) {
	char text2[] = "Welkom Franc en Michiel!";
	sPosition_t sPos2 = {80,80};
	color_t color[2] = {VGA_COL_YELLOW, VGA_COL_BLUE};
	uint8_t blink = 1;
	uint8_t delay = 0;

	SystemInit();

	status_t status = setDemoBackground();
	if(status != VGA_SUCCESS) {
		return status;
	}

	//setDemoBackground();

	setDemoShapes();

	setDemoText();

	VGA_D_screenInit();

	while(1){
		if(V_SYNC_FLAG)
		{
			status = VGA_P_printString(sPos2, text2, Size_18, Bold, color[blink]);
			if (delay == 10)
			{
				blink = !blink;
				delay=0;
			}
			delay++;
		}
	}
	return VGA_SUCCESS;
}
/* End of file main.c */
