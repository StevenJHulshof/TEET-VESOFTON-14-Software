/*******************************************************************************
 * Begin of file utility.h
 *
 * @author: Lukas ten Hove
 * Created: 18/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief	General utility library for use in other functions.
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
 * @param	lineColor	Primitive frame line color. Ranging 0 to 255.
 * @param	fillColor	Primitive fill color. Ranging -1 to 255.
 * @param	lineWeight	Primitive frame line weight. Ranging 1 to 255.
 *
 * @return	Status of operation.
 * @return	VGA_SUCCESS 					- 	Operation is success.
 * @return	VGA_RADII_OUT_OF_BOUNDS			-	Input radii is out of bounds.
 * 												(radii > 0).
 * @return	VGA_LINE_COL_OUT_OF_BOUNDS		-	Input line color is out of
 * 												bounds. (0 to 255).
 * @return	VGA_FILL_COL_OUT_OF_BOUNDS		-	Input fill color is out of
 * 												bounds. (-1 to 255).
 * @return	VGA_LINE_WEIGHT_OUT_OF_BOUNDS	- 	Input line weight is out of
 * 												bounds. (1 to 255).
 */
status_t UTIL_checkBoundaries(	sRadii_t* 	radii,
								color_t 	lineColor,
								color_t 	fillColor,
								uint8_t 	lineWeight	);

/**
 * @brief	Checks whether parameter is positive or negative. Returns
 * 			respectively 1 or -1.
 *
 * @param	i	Input parameter.
 *
 * @return	Positive or negative increment based on input parameter. 1 or -1.
 */
int UTIL_sign(int i);

/**
 * @brief	Constrain any value between 0->2*PI.
 *
 * @param 	thetaRad	Angle in radians.
 *
 * @return	Mapped theta value.
 */
float UTIL_mapToUnitCircle(float thetaRad);

/**
 * @brief	Get sine value for given theta in radians.
 *
 * @param 	thetaRad	Angle in radians.
 *
 * @return	Sine of given theta.
 */
float UTIL_getSinLut(float thetaRad);

/**
 * @brief	Get cosine value for given theta in radians.
 *
 * @param 	thetaRad	Angle in radians.
 *
 * @return	Cosine of given theta.
 */
float UTIL_getCosLut(float thetaRad);

/**
 * @brief	Convert RGB values to the color byte used by the VGA library.
 *
 * @param 	red		Red component. Ranging 0 to 255.
 * @param 	green	Green component. Ranging 0 to 255.
 * @param 	blue	Blue component. Ranging 0 to 255.
 *
 * @return	Converted color. Ranging 0 to 255.
 */
color_t UTIL_convertColor(int red, int green, int blue);

#endif /* UTILITY_H */
/* End of file utility.h */
