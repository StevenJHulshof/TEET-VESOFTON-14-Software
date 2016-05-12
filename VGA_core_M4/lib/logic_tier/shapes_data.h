/*******************************************************************************
 * Begin of file shapes_data.h
 *
 * @author: Steven Hulshof
 * Created: 12/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Functions for processing the shapes [primitive, line, ellipse].
 *
 ******************************************************************************/

#ifndef SHAPES_DATA_H_
#define SHAPES_DATA_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "system.h"
#include "pixel_data.h"
#include <stdint.h>
#include <math.h>

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief	Calculates pixel positions of the ellipse.
 *
 * @param centerPointPos	Center position of the ellipse.
 * @param radii	Radii a and b are used for determining the shape of the ellipse.
 * @param rotationDegrees	Rotation of the ellipse in degrees.
 * @param lineColor	Line color of the ellipse.
 * @param fillColor Fill color of the ellipse.
 * @param lineWeight	Line weight of the ellipse.
 * @return	Status of operation.
 */
status_t VGA_calculateEllipseData(sPosition_t* centerPointPos,
								  sRadii_t* radii,
								  int rotationDegrees,
								  color_t lineColor,
								  color_t fillColor,
								  uint8_t lineWeight);

#endif /* SHAPES_DATA_H_ */
/* End of file shapes_data.h */
