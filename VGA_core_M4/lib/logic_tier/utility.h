/*******************************************************************************
 * Begin of file utility.h
 *
 * @author: Lukas ten Hove
 * Created: 18/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief General utility library for use in other functions.
 *
 ******************************************************************************/

#ifndef UTILITY_H_
#define UTILITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "sin_LUT.h"
#include "math.h"

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief	Get sin value for given theta in radians.
 *
 * @param thetaRad	angle theta in radians.
 * @return	sin of given theta.
 */

float getSinLut(float thetaRad);

/**
 * @brief	Get cos value for given theta in radians.
 *
 * @param thetaRad	angle theta in radians.
 * @return	cos of given theta.
 */

float getCosLut(float thetaRad);


#endif /* UTILITY_H */
/* End of file utility.h */
