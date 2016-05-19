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
/**
 * @brief	Checks whether parameter is positive or negative. Returns respectively 1 or -1.
 *
 * @param	i		Input parameter.
 * @return	sign	Positive or negative increment based on input parameter.
 */
int VGA_sign(int i) {

	int sign;

	// Check whether input parameter is positive or negative
    if (i < 0) {
    	sign = -1;
    } else {
    	sign = 1;
    }

    return sign;
}

float mapToUnitCircle(float thetaRad){
	while (thetaRad < 0){
		thetaRad += (2*M_PI);
	};

	while (thetaRad > (2*M_PI)){
		thetaRad -= (2*M_PI);
	};

	return thetaRad;
}

float getSinLut(float thetaRad){
	float corrThetaRad = mapToUnitCircle(thetaRad);

	int index = (int) ((corrThetaRad/M_PI)*180);

	float result = sin_LUT[index];

	return result;
}

float getCosLut(float thetaRad){
	float result = getSinLut(thetaRad + M_PI_2);

	return result;
}

/* End of utility.c */
