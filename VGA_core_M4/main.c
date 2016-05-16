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

		VGA_processEllipseData(&center, &radii, p, VGA_COL_BLACK, VGA_COL_TRANSPARENT, 0);
	}
}

/*******************************************************************************
 * Main
 ******************************************************************************/
int main(void) {
	
	SystemInit();
	UB_VGA_Screen_Init();

	VGA_processScreenData(VGA_COL_CYAN);
	//testEllipseShape();

//	sPosition_t ellipsePos = {80, 50};
//	sRadii_t radii = {30, 10};
//	VGA_processEllipseData(&ellipsePos, &radii, 0, VGA_COL_BLACK, VGA_COL_TRANSPARENT, 3);
//
//	ellipsePos.x = 240;
//	VGA_processEllipseData(&ellipsePos, &radii, 15, VGA_COL_MAGENTA, VGA_COL_GREEN, 7);
//
//	ellipsePos.x = 80;
//	ellipsePos.y = 190;
//	VGA_processEllipseData(&ellipsePos, &radii, 30, VGA_COL_BLUE, VGA_COL_GREEN, 1);
//
//	ellipsePos.x = 240;
//	VGA_processEllipseData(&ellipsePos, &radii, 45, VGA_COL_MAGENTA, VGA_COL_TRANSPARENT, 1);

	sPosition_t primitive[10] = {
			{100, 100},
			{120, 150},
			{150, 99},
			{170, 170},
			{170, 100},
			{190, 130},
			{240, 100},
			{190, 80},
			{233, 50},
			{100, 190}
	};

	VGA_processPrimitiveData(primitive, 10, VGA_COL_BLACK, VGA_COL_RED, 1);

	while(1){
	//	int p;
			//for(p = 0; p < 30; p++) {

		//		while(i--); i = 10000000;
		//	}
	}
}
/* End of file main.c */

