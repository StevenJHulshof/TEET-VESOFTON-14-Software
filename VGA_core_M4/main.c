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
#include "fonts_display.h"
#include <math.h>
#include <stdlib.h>
#include "utility.h"

/*******************************************************************************
 * Main
 ******************************************************************************/
int main(void) {

	SystemInit();
	VGA_screenInit();
	sPosition_t charPos ={100,100};

	processStringData("Koffie?@NU!!!$#@!$#@jajajaja$",Size_18,Regular, charPos, VGA_COL_BLUE);

	while(1) {
	}
}
/* End of file main.c */
