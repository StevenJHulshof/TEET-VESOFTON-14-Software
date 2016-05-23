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
#include <stdlib.h>
#include "utility.h"

/*******************************************************************************
 * Main
 ******************************************************************************/
int main(void) {

	SystemInit();
	VGA_screenInit();

<<<<<<< HEAD
	//long int i = 10000000;
=======
//	sPosition pixelPos = {100, 100};
//	color_t pixelColor = VGA_getPixelData(&pixelPos);
>>>>>>> refs/remotes/origin/master

	while(1) {
//}


			while(VGA_lockFlag);
			DMA_Cmd(DMA2_Stream5, DISABLE);


			VGA_processScreenData(rand() % 256);

			sPosition_t cPos = {160, 120};
		//	sRadii_t radii = {80, 80};
			sRadii_t radii2 = {(rand() % 60) + 100, (rand() % 20) + 60};
			color_t fillColor;
			VGA_setPrimitiveData(&cPos, &radii2, rand() % 360, rand() % 256, (rand() % 256) - 1, (rand() % 10) + 1, (rand() % 7) + 2);
			int x, y, sample, sampleT;
			sampleT = ((rand() % 8) +3);
			for(y = 40, sample = 2; y < VGA_DISPLAY_Y; y += 80) {
				for(x = 53; x < VGA_DISPLAY_X; x += 107, sample++) {
					radii2.y = (rand() % 20) + 20;
					radii2.x = (rand() % 20) + 20;
					if(sample == sampleT) {
						fillColor = -1;
					} else {
						fillColor = rand() % 256;
					}
					cPos.x = x;
					cPos.y = y;
					VGA_setPrimitiveData(&cPos, &radii2, rand() % 360, rand() % 256, fillColor, (rand() % 10) + 1, sample);
				}
			}
			DMA_Cmd(DMA2_Stream5, ENABLE);
	}
}
/* End of file main.c */
