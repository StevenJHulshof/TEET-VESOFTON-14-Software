/*******************************************************************************
 * Begin of file fx_data.h
 *
 * @author: Steven Hulshof
 * Created: 24/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Functions for adding screen effects to the VGA screen.
 ******************************************************************************/

#ifndef FX_DATA_H_
#define FX_DATA_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "system.h"
#include "pixel_data.h"

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief	Adds a blooming effect to the VGA screen.
 *
 * This function will call VGA_L_getPixelData() to check the surrounding pixels.
 * After averaging the RGB components of the color, it will call the
 * VGA_L_setPixelData() for processing.
 *
 * @param	bloomInt	The intensity of the bloom effect defined in the enum
 * 						bloomIntensity_t. Ranging 0 to 7.
 *
 * @return	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 		- 	Operation is success.
 * @return	VGA_PIXEL_NOT_SET 	- 	Set pixel operation has failed.
 *
 * @code{.c}
 * status_t status = VGA_FX_bloomScreen(VGA_BLOOM_INT_5);
 * if(status != VGA_SUCCESS) {
 * 	return status;
 * }
 * @endcode
 */
status_t VGA_FX_bloomScreen(bloomIntensity_t bloomInt);

#endif /* FX_DATA_H_ */
/* End of file fx_data.h */
