/*******************************************************************************
 * Begin of file utility.c
 *
 * @author: Lukas ten Hove
 * Created: 18/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief General utility library for use in other functions.
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "utility.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
float getSinLut(float thetaRad){
	int index = (int) (thetaRad/M_PI*180) % 360;

	float result = sin_LUT[index];

	return result;
}

float getCosLut(float thetaRad){
	float result = getSinLut(0.5 * M_PI - thetaRad);

	return result;
}

/* End of utility.c */
