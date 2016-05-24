/*******************************************************************************
 * Begin of file fx_data.h
 *
 * @author: Steven Hulshof
 * Created: 24/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Functions for adding screen effects to the VGA screen.
 *
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
 * @param	bloomInt	The intensity of the bloom effect.
 * @return	Status of operation.
 */
status_t VGA_FX_bloomScreen(bloomIntensity_t bloomInt);

#endif /* FX_DATA_H_ */
/* End of file fx_data.h */
