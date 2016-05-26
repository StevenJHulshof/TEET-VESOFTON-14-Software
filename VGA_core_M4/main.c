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

	SystemInit();


	VGA_D_screenInit();
	sPosition_t center = {160, 120};
	sRadii_t radii = {140, 100};
	int i;
	while(1){
		if(V_SYNC_FLAG) {
		VGA_P_fillScreen(VGA_COL_BLUE);

		for(i = 1; i < 50; i++) {

				VGA_P_drawPrimitive(&center, &radii, 0, VGA_COL_RED, VGA_COL_GREEN, i, VGA_ELLIPSE);
			}
		}
		//VGA_FX_bloomScreen(VGA_BLOOM_INT_5);
	}
	return VGA_SUCCESS;
}
/* End of file main.c */
