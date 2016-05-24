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
 * @brief	Checks argument boundaries of shapes.
 *
 * @param	radii		Radius x and y of the shape.
 * @param	lineColor	Shape frame line color.
 * @param	fillColor	Shape fill color.
 * @param	lineWeight	Shape frame line weight.
 * @return	Status of operation.
 */
status_t UTIL_checkBoundaries(	sRadii_t* 	radii,
								color_t 	lineColor,
								color_t 	fillColor,
								uint8_t 	lineWeight	) {

	status_t status = VGA_SUCCESS;

	// Check primitive boundaries
	if(radii->x < 0 || radii->y < 0) {
		status = VGA_RADII_OUT_OF_BOUNDS;
	}
	if(lineColor < 0 || lineColor > 0xFF) {
		status = VGA_LINE_COL_OUT_OF_BOUNDS;
	}
	if(fillColor < -1 || fillColor > 0xFF) {
		status = VGA_FILL_COL_OUT_OF_BOUNDS;
	}
	if(lineWeight < 1) {
		status = VGA_LINE_WEIGHT_OUT_OF_BOUNDS;
	}

	return status;
}

/**
 * @brief	Checks whether parameter is positive or negative. Returns respectively 1 or -1.
 *
 * @param	i		Input parameter.
 * @return	sign	Positive or negative increment based on input parameter.
 */
int UTIL_sign(int i) {

	int sign;

	// Check whether input parameter is positive or negative
    if (i < 0) {
    	sign = -1;
    } else {
    	sign = 1;
    }

    return sign;
}

float UTIL_mapToUnitCircle(float thetaRad){

	while (thetaRad < 0){
		thetaRad += (2*M_PI);
	};

	while (thetaRad > (2*M_PI)){
		thetaRad -= (2*M_PI);
	};

	return thetaRad;
}

float UTIL_getSinLut(float thetaRad){

	float corrThetaRad = UTIL_mapToUnitCircle(thetaRad);

	int index = (int) ((corrThetaRad/M_PI)*180);

	float result = sin_LUT[index];

	return result;
}

float UTIL_getCosLut(float thetaRad){

	float result = UTIL_getSinLut(thetaRad + M_PI_2);

	return result;
}

/* End of utility.c */