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

//file with demo functions
#include "demo.h"

/*******************************************************************************
 * Main
 ******************************************************************************/
int main(void) {

	SystemInit();

	status_t status;

   /*functions used to demonstrate the functionality of the API.
	* from file: demo.c
	*/

	status = setDemoBackground();
	if (status != VGA_SUCCESS)
		return status;

	status = setDemoShapes();
	if (status != VGA_SUCCESS)
		return status;

	status = setDemoText();
	if (status != VGA_SUCCESS)
		return status;

	/*initialize the VGA driver last to prevent the screen from showing frames that
	are still being processed.*/
	VGA_D_screenInit();

	while(1){

	}
	return VGA_SUCCESS;
}
/* End of file main.c */
