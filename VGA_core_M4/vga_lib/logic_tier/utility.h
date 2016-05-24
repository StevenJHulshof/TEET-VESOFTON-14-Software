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
#include "sin_lut.h"
#include "math.h"
#include "system.h"

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief	Checks argument boundaries of primitives.
 *
 * @param	radii		Radius x and y of the primitive.
 * @param	lineColor	Primitive frame line color.
 * @param	fillColor	Primitive fill color.
 * @param	lineWeight	Primitive frame line weight.
 * @return	Status of operation.
 */
status_t UTIL_checkBoundaries(	sRadii_t* 	radii,
								color_t 	lineColor,
								color_t 	fillColor,
								uint8_t 	lineWeight	);

/**
 * @brief	Checks whether parameter is positive or negative. Returns respectively 1 or -1.
 *
 * @param	i		Input parameter.
 * @return	sign	Positive or negative increment based on input parameter.
 */
int UTIL_sign(int i);

/**
 * @brief	Constrain any value between 0->2*PI
 *
 * @param 	thetaRad	angle theta in radians.
 * @return	mapped theta value.
 */
float UTIL_mapToUnitCircle(float thetaRad);

/**
 * @brief	Get sin value for given theta in radians.
 *
 * @param 	thetaRad	angle theta in radians.
 * @return	sin of given theta.
 */
float UTIL_getSinLut(float thetaRad);

/**
 * @brief	Get cos value for given theta in radians.
 *
 * @param 	thetaRad	angle theta in radians.
 * @return	cos of given theta.
 */
float UTIL_getCosLut(float thetaRad);

#endif /* UTILITY_H */
/* End of file utility.h */
