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
#include "shapes_data_v2.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
int VGA_sign(int i) {

    if (i < 0) {
    	return -1;
    } else {
    	return 1;
    }
}

status_t VGA_setLineWeight( sPosition_t*	centerPos,
							color_t			lineColor,
							uint8_t			lineWeight) {

	float r = lineWeight * 0.5;
	sRadii_t radii = {r, r};

	return VGA_setPrimitiveData(centerPos, &radii, 0, lineColor, lineColor, 1, VGA_HEXAGON);
}

status_t VGA_setLineData(    sPosition_t 	endPointPos[2],
                         	 color_t     	lineColor,
                         	 uint8_t		lineWeight	) {

	status_t 	status = VGA_SUCCESS;
	sPosition_t pixelPos;
	sPosition_t deltaPos = {
		endPointPos[1].x - endPointPos[0].x,
		endPointPos[1].y - endPointPos[0].y
	};

	if(fabs(deltaPos.y) > fabs(deltaPos.x)) {
		for(pixelPos.y = endPointPos[0].y; pixelPos.y != endPointPos[1].y; pixelPos.y += VGA_sign(deltaPos.y)) {
			pixelPos.x = endPointPos[0].x + (pixelPos.y - endPointPos[0].y) * deltaPos.x / deltaPos.y;

			if(lineWeight > 1) {
				status = VGA_setLineWeight(&pixelPos, lineColor, lineWeight);
			} else {
				status = VGA_setPixelData(&pixelPos, lineColor);
			}
			if(status != VGA_SUCCESS) {
				return status;
			}
		}
	} else {
		for(pixelPos.x = endPointPos[0].x; pixelPos.x != endPointPos[1].x; pixelPos.x += VGA_sign(deltaPos.x)) {
			pixelPos.y = endPointPos[0].y + (pixelPos.x - endPointPos[0].x) * deltaPos.y / deltaPos.x;
			if(lineWeight > 1) {
				status = VGA_setLineWeight(&pixelPos, lineColor, lineWeight);
			} else {
				status = VGA_setPixelData(&pixelPos, lineColor);
			};
			if(status != VGA_SUCCESS) {
				return status;
			}
		}
	}
	return status;
}

uint8_t VGA_pixelInPolygon(	sPosition_t 	verticePos[],
							sPosition_t* 	pixelPos,
							uint16_t 		numberOfVertices	) {

	uint8_t inPolygon = 0;
	int   	i;
	int 	j = numberOfVertices - 1 ;

	for(i = 0; i < numberOfVertices; i++) {


		if (((	(float) verticePos[i].y 	> 	(float) pixelPos->y) 		!=
			(	(float) verticePos[j].y 	> 	(float) pixelPos->y)	) 	&&
		    (	(float) pixelPos->x 		< (	(float) verticePos[j].x 	-
		    	(float) verticePos[i].x) 	* (	(float) pixelPos->y 		-
		    	(float) verticePos[i].y) 	/ (	(float) verticePos[j].y 	-
		    	(float) verticePos[i].y) 	+ 	(float) verticePos[i].x	) 	) {

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

status_t VGA_setPolygonFrame(	sPosition_t verticePos[],
								uint16_t 	numberOfVertices,
								color_t 	lineColor,
								uint8_t		lineWeight) {

	status_t status = VGA_SUCCESS;
	uint16_t vertice;

	for(vertice = 0; vertice < numberOfVertices; vertice++) {

		sPosition_t line[2];
		line[0] = verticePos[vertice];

		if(vertice > numberOfVertices-2) {
			line[1] = verticePos[0];
		} else {
			line[1] = verticePos[vertice+1];
		}

		status = VGA_setLineData(line, lineColor, lineWeight);

		if(status != VGA_SUCCESS) {
			return status;
		}
	}

	return status;
}

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

	if(fillColor != VGA_COL_TRANSPARENT) {

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

		for(y = minY; y < maxY; y++) {
			for(x = minX; x < maxX; x++) {

				sPosition_t pixelPos = {x, y};

				if(VGA_pixelInPolygon(verticePos, &pixelPos, numberOfVertices) != 0) {

					status = VGA_setPixelData(&pixelPos, fillColor);
					if(status != VGA_SUCCESS) {
						return status;
					}
				}
			}
		}
	}

	status = VGA_setPolygonFrame(verticePos, numberOfVertices, lineColor, lineWeight);

	return status;
}


status_t VGA_setPrimitiveData(	sPosition_t* 	centerPointPos,
								sRadii_t* 		radii,
								uint16_t 		rotationDegrees,
								color_t			lineColor,
								color_t			fillColor,
								uint16_t		lineWeight,
								sampleSize_t	sampleSize) {

	sPosition_t	pixelPos[MAX_SAMPLES];
	float 		theta;
	uint16_t 	sample;
	float 		rotationRadian = rotationDegrees * M_PI / 180;
	float 		cosAngle = cosf(rotationRadian);
	float 		sinAngle = sinf(rotationRadian);

	memset(pixelPos, -1, MAX_SAMPLES);

	for(theta = 0, sample = 0;
		theta < (2 * M_PI);
		theta += (2 * M_PI / sampleSize), sample++) {

		// Set ellipse pixel relative to origin
		pixelPos[sample].x = radii->x * cosf(theta);
		pixelPos[sample].y = radii->y * sinf(theta);

		// Buffer prevents skewing
		sPosition_t pixelPosBuf	= pixelPos[sample];

		// Translate pixel rotation
		pixelPos[sample].x = cosAngle * pixelPosBuf.x - sinAngle * pixelPosBuf.y;
		pixelPos[sample].y = cosAngle * pixelPosBuf.y + sinAngle * pixelPosBuf.x;

		// Set ellipse pixel relative to center point
		pixelPos[sample].x = centerPointPos->x + pixelPos[sample].x;
		pixelPos[sample].y = centerPointPos->y + pixelPos[sample].y;
	}

	return VGA_setPolygonData(pixelPos, sampleSize, lineColor, fillColor, lineWeight);
}
/* End of file shapes_data.c */
