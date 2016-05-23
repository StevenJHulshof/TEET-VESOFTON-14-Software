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

/*******************************************************************************
 * Main
 ******************************************************************************/
int main(void) {

	SystemInit();
	VGA_screenInit();

	VGA_fillScreen(VGA_COL_BLUE);
	status_t status = VGA_SUCCESS;

	sPosition_t pixelPos = {10, 10};
	status = VGA_drawPixel(&pixelPos, VGA_COL_RED);
	if(status != VGA_SUCCESS) {
		return status;
	}

	sPosition_t center = {100, 60};
	sRadii_t radii = {20, 60};
	status = VGA_drawPrimitive(&center, &radii, 45, VGA_COL_MAGENTA, VGA_COL_BLACK, 5, VGA_HEXAGON);
	if(status != VGA_SUCCESS) {
		return status;
	}

	sPosition_t poly[5] = {
			{200, 200},
			{130, 170},
			{20, 30},
			{60, 200},
			{170, 50}
	};
	status = VGA_drawPolygon(poly, 5, VGA_COL_WHITE, VGA_COL_GREEN, 2);
	if(status != VGA_SUCCESS) {
		return status;
	}

	while(1);
}

//			while(VGA_lockFlag);
//			DMA_Cmd(DMA2_Stream5, DISABLE);
//
//
//			VGA_processScreenData(rand() % 256);
//
//			sPosition_t cPos = {160, 120};
//		//	sRadii_t radii = {80, 80};
//			sRadii_t radii2 = {(rand() % 60) + 100, (rand() % 20) + 60};
//			color_t fillColor;
//			VGA_setPrimitiveData(&cPos, &radii2, rand() % 360, rand() % 256, (rand() % 256) - 1, (rand() % 10) + 1, (rand() % 7) + 2);
//			int x, y, sample, sampleT;
//			sampleT = ((rand() % 8) +3);
//			for(y = 40, sample = 2; y < VGA_DISPLAY_Y; y += 80) {
//				for(x = 53; x < VGA_DISPLAY_X; x += 107, sample++) {
//					radii2.y = (rand() % 20) + 20;
//					radii2.x = (rand() % 20) + 20;
//					if(sample == sampleT) {
//						fillColor = -1;
//					} else {
//						fillColor = rand() % 256;
//					}
//					cPos.x = x;
//					cPos.y = y;
//					VGA_setPrimitiveData(&cPos, &radii2, rand() % 360, rand() % 256, fillColor, (rand() % 10) + 1, sample);
//				}
//			}
//			DMA_Cmd(DMA2_Stream5, ENABLE);
//	}
//}
/* End of file main.c */
