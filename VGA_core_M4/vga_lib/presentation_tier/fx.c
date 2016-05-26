/*******************************************************************************
 * Begin of file fx.c
 *
 * @author: Steven Hulshof
 * Created: 24/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Functions for adding screen effects.
 *
 * Contains function to add bloom effect to the VGA screen.
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fx.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
status_t VGA_P_bloomScreen(bloomIntensity_t bloomInt) {

	status_t status = VGA_SUCCESS;

	// Validate argument
	if(bloomInt < VGA_BLOOM_INT_1 || bloomInt > VGA_BLOOM_INT_7) {
		return VGA_BLOOM_INT_OUT_OF_BOUNDS;
	}

	status = VGA_L_setBloomScreenData(bloomInt);

	return status;
}

/* End of file fx.c */
