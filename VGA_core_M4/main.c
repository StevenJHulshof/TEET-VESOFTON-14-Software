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
#include "shapes_data.h"
#include <math.h>

void testEllipseShape() {
	sPosition_t center = {50, 120};
	sRadii_t radii = {20, 80};

	int p;
	for(p=0; p < 360; p+=5) {
		center.x+=3;
		radii.b-=1;

		VGA_calculateEllipseData(&center, &radii, p, VGA_COL_BLACK, VGA_COL_TRANSPARANT, 0);
	}
}


/*******************************************************************************
 * Main
 ******************************************************************************/
int main(void) {
	
	SystemInit();
	UB_VGA_Screen_Init();

	VGA_processScreenData(VGA_COL_CYAN);
	testEllipseShape();

	while(1){
	//	int p;
			//for(p = 0; p < 30; p++) {

		//		while(i--); i = 10000000;
		//	}
	}
}
/* End of file main.c */

