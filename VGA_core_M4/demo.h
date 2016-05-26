/*******************************************************************************
 * Begin of file demo.h
 *
 * @author: Steven Hulshof
 * Created: 24/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Functions for the demo software.
 *
 * this file demonstrates some functionalities of the vga_lib API. The functions
 * demonstrate:
 * - printing text
 * - drawing primitive shapes
 * - drawing polygon shapes
 * - using FX
 * - catching the return status
 *
 ******************************************************************************/

#ifndef DEMO_H_
#define DEMO_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

//include "vga_lib.h" to use the API.
#include "vga_lib.h"

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
status_t setDemoBackground(void);
status_t setDemoShapes();
status_t setDemoText();

#endif /* DEMO_H_ */
/* End of file demo.h */
