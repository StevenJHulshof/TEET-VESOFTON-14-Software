/*******************************************************************************
 * Begin of file fx_data.h
 *
 * @author: Steven Hulshof
 * Created: 24/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief 	Functions for processing screen effects.
 *
 * Contains function to add bloom effect to the VGA screen.
 ******************************************************************************/

#ifndef FX_H_
#define FX_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fx_data.h"

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief	Adds a blooming effect to the VGA screen.
 *
 * This function adds, based on the input intensity, a bloom effect to the
 * screen. It will call VGA_L_setBloomScreenData() for processing the effect.
 *
 * @note	This function slows application drastically per bloom
 * 			intensity level.
 *
 * @param	bloomInt	The intensity of the bloom effect defined in the enum
 * 						bloomIntensity_t. Ranging 0 to 7.
 *
 * @return	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 				- 	Operation is success.
 * @return	VGA_PIXEL_NOT_SET 			- 	Set pixel operation has failed.
 * @return	VGA_BLOOM_INT_OUT_OF_BOUNDS	-	Input bloom intensity out of bounds.
 * 											(0 to 7).
 *
 * @code{.c}
 * status_t status = VGA_P_bloomScreen(VGA_BLOOM_INT_4);
 * if(status != VGA_SUCCESS) {
 * 	return status;
 * }
 * @endcode
 */
status_t VGA_P_bloomScreen(bloomIntensity_t bloomInt);

#endif /* FX_H_ */
/* End of file fx_data.h */
