/*******************************************************************************
 * Begin of file fx_data.h
 *
 * @author: Steven Hulshof
 * Created: 24/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief 	Functions for processing screen effects.
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
 * @brief	Processes blooming effect.
 *
 * This function is called by VGA_P_bloomScreen(). It will add a bloom effect
 * to the entire VGA_RAM1 DMA Buffer. This function will call
 * VGA_L_getPixelData() to check the surrounding pixels. After averaging
 * the RGB components of the color, it will call the VGA_L_setPixelData()
 * for processing.
 *
 * @note	This function slows application drastically per bloom
 * 			intensity level.
 *
 * @param	bloomInt	The intensity of the bloom effect defined in the enum
 * 						bloomIntensity_t. Ranging 0 to 7.
 *
 * @return	Status of operation. Possible return values:
 * @return	VGA_SUCCESS 		- 	Operation is success.
 * @return	VGA_PIXEL_NOT_SET 	- 	Set pixel operation has failed.
 */
status_t VGA_L_setBloomScreenData(bloomIntensity_t bloomInt);

#endif /* FX_DATA_H_ */
/* End of file fx_data.h */
