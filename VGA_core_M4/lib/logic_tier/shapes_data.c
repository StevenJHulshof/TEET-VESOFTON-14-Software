/*******************************************************************************
 * Begin of file shapes_data.c
 *
 * @author: Steven Hulshof, Lukas ten Hove
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
/**
 * @brief	Processes line weight data to pixel position.
 *
 * @param	centerPointPos	Pixel position around which the line weight should be calculated.
 * @param	lineColor		Color of the line.
 * @param	lineWeight		Weight of the line.
 * @return 	Status of operation.
 */
status_t VGA_setLineWeight( sPosition_t*	centerPointPos,
							color_t			lineColor,
							uint8_t			lineWeight) {

	float 		r = lineWeight * 0.5;
	sRadii_t 	radii = {r, r};

	// Use primitive function to create circle around the pixel
	return VGA_setPrimitiveData(centerPointPos, &radii, 0, lineColor, lineColor, 1, VGA_HEXAGON);
}

/**
 * @brief	Processes line data to pixel positions.
 *
 * @param 	endPointPos[2]	End point positions of the line.
 * @param 	lineColor		Color of the line.
 * @param	lineWeight		Weight of the line.
 * @return	Status of operation.
 */
status_t VGA_setLineData(    sPosition_t 	endPointPos[2],
                         	 color_t     	lineColor,
                         	 uint8_t		lineWeight	) {

	status_t 	status = VGA_SUCCESS;
	sPosition_t pixelPos;

	// Calculate dx and dy
	sPosition_t deltaPos = {
		endPointPos[1].x - endPointPos[0].x,
		endPointPos[1].y - endPointPos[0].y
	};

	// Check whether x plots from y or y plots from x
	if(fabs(deltaPos.y) > fabs(deltaPos.x)) {

		// Loop through line pixel data
		for(pixelPos.y = endPointPos[0].y;
			pixelPos.y != endPointPos[1].y;
			pixelPos.y += VGA_sign(deltaPos.y)) {

			// Calculate x pixel position
			pixelPos.x = endPointPos[0].x + (pixelPos.y - endPointPos[0].y) * deltaPos.x / deltaPos.y;

			// Set line weight
			if(lineWeight > 1) {
				status = VGA_setLineWeight(&pixelPos, lineColor, lineWeight);
			} else {
				status = VGA_setPixelData(&pixelPos, lineColor);
			}

			// Report status
			if(status != VGA_SUCCESS) {
				return status;
			}
		}
	} else {

		// Loop through line pixel data
		for(pixelPos.x = endPointPos[0].x;
			pixelPos.x != endPointPos[1].x;
			pixelPos.x += VGA_sign(deltaPos.x)) {

			// Calculate y pixel position
			pixelPos.y = endPointPos[0].y + (pixelPos.x - endPointPos[0].x) * deltaPos.y / deltaPos.x;

			// Set line weight
			if(lineWeight > 1) {
				status = VGA_setLineWeight(&pixelPos, lineColor, lineWeight);
			} else {
				status = VGA_setPixelData(&pixelPos, lineColor);
			};

			// Report status
			if(status != VGA_SUCCESS) {
				return status;
			}
		}
	}
	return status;
}

/**
 * @brief	Checks whether a pixel is inside the polygon using the
 * 			Point-In-Polygon algorithm.
 *
 * @param 	verticePos[]		Positions of the polygon vertices.
 * @param 	pixelPos			Pointer to the pixel position that will be checked.
 * @param 	numberOfVertices	Total number of polygon vertices.
 * @return 	inPolygon			Returns 1 when pixel is inside the polygon, otherwise 0.
 */
uint8_t VGA_pixelInPolygon(	sPosition_t 	verticePos[],
							sPosition_t* 	pixelPos,
							uint16_t 		numberOfVertices	) {

	uint8_t inPolygon = 0;
	int   	i;
	int 	j = numberOfVertices - 1 ;

	// Check whether pixel is in or outside the polygon
	for(i = 0; i < numberOfVertices; i++) {

		// Check pixel placement per vertice
		if (((	(float) verticePos[i].y 	> 	(float) pixelPos->y) 		!=
			(	(float) verticePos[j].y 	> 	(float) pixelPos->y)	) 	&&
		    (	(float) pixelPos->x 		< (	(float) verticePos[j].x 	-
		    	(float) verticePos[i].x) 	* (	(float) pixelPos->y 		-
		    	(float) verticePos[i].y) 	/ (	(float) verticePos[j].y 	-
		    	(float) verticePos[i].y) 	+ 	(float) verticePos[i].x	) 	) {

			// Enable/disable pixel placement
			if(inPolygon == 1) {
				inPolygon = 0;
			} else {
				inPolygon = 1;
			}
		}

		j = i;
	}

	return inPolygon;
}

status_t VGA_setPolygonFill(sPosition_t vertices[],
							uint16_t numberOfVertices,
							int IMAGE_BOT,
							int IMAGE_TOP,
							int IMAGE_LEFT,
							int IMAGE_RIGHT,
							color_t fillColor) {

	int  		nodes, i, j, swap;
	int 		nodeX[MAX_SAMPLES];
	sPosition_t pixelPos;
	status_t	status = VGA_SUCCESS;

	// Loop through the rows of the image
	for(pixelPos.y = IMAGE_TOP; pixelPos.y < IMAGE_BOT; pixelPos.y++) {

		// Build a list of nodes
		nodes = 0;
		j = numberOfVertices-1;

		for (i = 0; i < numberOfVertices; i++) {

			if ((	(float) vertices[i].y <  (double) pixelPos.y 	&&
					(float) vertices[j].y >= (double) pixelPos.y) 	||
				(	(float) vertices[j].y <  (double) pixelPos.y 	&&
					(float) vertices[i].y >= (double) pixelPos.y)	) {

				nodeX[nodes++] = (int) 	((float) vertices[i].x +
										((float) pixelPos.y -
										(float) vertices[i].y) /
										((float) vertices[j].y -
										(float) vertices[i].y) *
										((float) vertices[j].x -
										(float) vertices[i].x));
			}

			j = i;
		}

		// Sort the nodes, via bubble sort
	  	i=0;
	  	while (i<nodes-1) {

	  		if (nodeX[i] > nodeX[i+1]) {
	  			swap = nodeX[i];
	  			nodeX[i] = nodeX[i+1];
	  			nodeX[i+1] = swap;
	  			if (i) {
	  				i--;
	  			}
	  		}
	  		else {
	  			i++;
	  		}
	  	}

	  	// Fill the pixels between node pairs
	  	for(i = 0; i < nodes; i += 2) {
	  		if(nodeX[i] >= IMAGE_RIGHT) {
	  			break;
	  		}
	  		if(nodeX[i+1] > IMAGE_LEFT ) {
	  			if(nodeX[i] < IMAGE_LEFT ) {
	  				nodeX[i] = IMAGE_LEFT;
	  			}
	  			if(nodeX[i+1] > IMAGE_RIGHT) {
	  				nodeX[i+1] = IMAGE_RIGHT;
	  			}
	  			for(pixelPos.x = nodeX[i]+1;
	  				pixelPos.x < nodeX[i+1]+1;
	  				pixelPos.x++) {
	  				status = VGA_setPixelData(&pixelPos, fillColor);
	  			}
	  		}
	  	}
	}

	return status;
}

/**
 * @brief	Set polygon frame line.
 *
 * @param	verticePos[]		Positions of the polygon vertices.
 * @param	numberOfVertices	Total number of polygon vertices.
 * @param	lineColor			Line color of the polygon.
 * @param	lineWeight			Weight of the line.
 * @return	Status of operation.
 */
status_t VGA_setPolygonFrame(	sPosition_t verticePos[],
								uint16_t 	numberOfVertices,
								color_t 	lineColor,
								uint8_t		lineWeight) {

	status_t status = VGA_SUCCESS;
	uint16_t vertice;

	// Draw polygon
	for(vertice = 0; vertice < numberOfVertices; vertice++) {

		sPosition_t line[2];
		line[0] = verticePos[vertice];

		if(vertice > numberOfVertices-2) {
			line[1] = verticePos[0];
		} else {
			line[1] = verticePos[vertice+1];
		}

		// Draw line from polygon vertice to polygon vertice + 1
		status = VGA_setLineData(line, lineColor, lineWeight);

		// Report status
		if(status != VGA_SUCCESS) {
			return status;
		}
	}

	return status;
}

/**
 * @brief	Process polygon data to pixel position.
 *
 * @param	verticePos[]		Positions of the polygon vertices.
 * @param 	numberOfVertices	Total number of polygon vertices.
 * @param 	lineColor			Line color of the polygon.
 * @param	fillColor 			Fill color of the polygon.
 * @param	lineWeight			Weight of the line.
 * @return	Status of operation.
 */
status_t VGA_setPolygonData(	sPosition_t verticePos[],
								uint16_t	numberOfVertices,
								color_t		lineColor,
								color_t		fillColor,
								uint8_t		lineWeight) {

	status_t 	status = VGA_SUCCESS;
	int 		x, y;
	uint8_t		i;
	int 		minY = INF;
	int 		minX = INF;
	uint16_t 	maxY = 0;
	uint16_t 	maxX = 0;

	// Use algorithm only when fill is needed
	if(fillColor != VGA_COL_TRANSPARENT) {

		// Set boundaries of the polygon image
		for(i = 0; i < numberOfVertices; i++) {

			if(verticePos[i].x < minX) {
				minX = verticePos[i].x;
			}
			if(verticePos[i].y < minY) {
				minY = verticePos[i].y;
			}
			if(verticePos[i].x > maxX) {
				maxX = verticePos[i].x;
			}
			if(verticePos[i].y > maxY) {
				maxY = verticePos[i].y;
			}
		}

		status = VGA_setPolygonFill(verticePos, numberOfVertices, maxY, minY, minX, maxX, fillColor);

		// Report status
		if(status != VGA_SUCCESS) {
			return status;
		}
	}

	// Draw polygon frame
	status = VGA_setPolygonFrame(verticePos, numberOfVertices, lineColor, lineWeight);

	return status;
}

/**
 * @brief	Process primitive data to pixel position.
 *
 * @param	centerPointPos	Center point position of the primitive.
 * @param	radii			Radii of the primitive. This will be calculated through a circle algorithm.
 * @param	rotationDegrees	Rotation in degrees.
 * @param	lineColor		Color of the frame line.
 * @param	fillColor		Color of the primitive fill.
 * @param 	lineWeight		Weight of the frame line.
 * @param	primitiveShape	Default shape of the primitive.
 * @return	Status of operation.
 */
status_t VGA_setPrimitiveData(	sPosition_t* 		centerPointPos,
								sRadii_t* 			radii,
								uint16_t 			rotationDegrees,
								color_t				lineColor,
								color_t				fillColor,
								uint16_t			lineWeight,
								primitiveShape_t	primitiveShape	) {

	sPosition_t	pixelPos[MAX_SAMPLES];
	float 		theta;
	uint16_t 	sample;
	float 		rotationRadian = rotationDegrees * M_PI / 180;
	float 		cosAngle = getCosLut(rotationRadian);
	float 		sinAngle = getSinLut(rotationRadian);

	// Make sure unused index will not be processed in setPixelData
	memset(pixelPos, -1, MAX_SAMPLES);

	for(theta = 0, sample = 0;
		theta < (2 * M_PI);
		theta += (2 * M_PI / primitiveShape), sample++) {

		// Set ellipse pixel relative to origin
		pixelPos[sample].x = radii->x * getCosLut(theta);
		pixelPos[sample].y = radii->y * getSinLut(theta);

		// Buffer prevents skewing
		sPosition_t pixelPosBuf	= pixelPos[sample];

		// Translate pixel rotation
		pixelPos[sample].x = cosAngle * pixelPosBuf.x - sinAngle * pixelPosBuf.y;
		pixelPos[sample].y = cosAngle * pixelPosBuf.y + sinAngle * pixelPosBuf.x;

		// Set ellipse pixel relative to center point
		pixelPos[sample].x = centerPointPos->x + pixelPos[sample].x;
		pixelPos[sample].y = centerPointPos->y + pixelPos[sample].y;
	}

	return VGA_setPolygonData(pixelPos, primitiveShape, lineColor, fillColor, lineWeight);
}
/* End of file shapes_data.c */
