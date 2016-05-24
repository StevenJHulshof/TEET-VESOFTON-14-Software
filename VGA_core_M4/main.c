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

/*******************************************************************************
 * Main
 ******************************************************************************/
int main(void) {

	SystemInit();

	status_t status = setDemoBackground();
	if(status != VGA_SUCCESS) {
		return status;
	}




	VGA_D_screenInit();

	while(1);
	return VGA_SUCCESS;
}
/* End of file main.c */
