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

/*******************************************************************************
 * Main
 ******************************************************************************/
int main(void) {
	
	SystemInit();
	UB_VGA_Screen_Init();

	VGA_processScreenData(VGA_COL_CYAN);

	sPosition_t center = {100, 100};
	sRadii_t radii = {60, 30};

	VGA_calculateEllipseData(&center, &radii, 0, VGA_COL_RED, VGA_COL_BLACK, 0);

	while(1);
}
/* End of file main.c */

