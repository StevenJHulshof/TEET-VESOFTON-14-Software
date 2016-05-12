/*******************************************************************************
 * Begin of file shapes_data.c
 *
 * @author: Steven Hulshof
 * Created: 12/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Functions for processing the shapes [primitive, line, ellipse].
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "shapes_data.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
status_t VGA_calculateEllipseData(sPosition_t* centerPointPos,
								  sRadii_t* radii,
								  int rotationDegrees,
								  color_t lineColor,
								  color_t fillColor,
								  uint8_t lineWeight) {

	sPosition_t pixelPos;
	status_t status;
	float theta;
	float rotationRadian = ((float) rotationDegrees) * M_PI / 180;

	// Draw ellipse
	for(theta = 0; theta < 2*M_PI; theta += 0.01) {

		// Set ellipse pixel relative to origin
		pixelPos.x = radii->a * cosf(theta);
		pixelPos.y = radii->b * sinf(theta);

		// Rotate ellipse
		pixelPos.x = 	cosf(rotationRadian) * pixelPos.x -
						sinf(rotationRadian) * pixelPos.y;
		pixelPos.y = 	sinf(rotationRadian) * pixelPos.x +
						cosf(rotationRadian) * pixelPos.y;

		// Set ellipse pixel relative to center point
		pixelPos.x = centerPointPos->x + pixelPos.x;
		pixelPos.y = centerPointPos->y + pixelPos.y;

		// Draw pixel
		status = VGA_setPixelData(&pixelPos, lineColor);

		// Report status
		if(status != VGA_SUCCESS) {
			return status;
		}
	}

	return status;
}

/* End of file shapes_data.c */
