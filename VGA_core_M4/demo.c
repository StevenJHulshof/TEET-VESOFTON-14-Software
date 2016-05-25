/*******************************************************************************
 * Begin of file demo.c
 *
 * @author: Steven Hulshof
 * Created: 24/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Functions for the demo software.
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "demo.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
status_t setDemoBackground(void) {

	status_t status = VGA_SUCCESS;
	int i, r;

	status = VGA_P_fillScreen(VGA_COL_BLUE);
	if(status != VGA_SUCCESS) {
		return status;
	}

	sPosition_t centerPos[5] = {
			{50, 50},
			{270, 50},
			{50, 190},
			{270, 190},
			{160, 120}
	};
	sRadii_t radii[5] = {
			{10, 80},
			{10, 80},
			{10, 80},
			{10, 80},
			{80, 10}
	};
	primitiveShape_t shape[5] = {
			VGA_TRIANGLE,
			VGA_SQUARE,
			VGA_PENTAGON,
			VGA_HEXAGON,
			VGA_ELLIPSE
	};
	color_t color[5] = {
			VGA_COL_YELLOW,
			VGA_COL_YELLOW-30,
			VGA_COL_GREEN+30,
			VGA_COL_GREEN,
			VGA_COL_RED
	};
	uint8_t lineWeight[5] = {1, 1, 1, 1, 3};

	for(i = 0; i < 5; i++) {
		for(r = 0; r < 360; r+=10) {
			status = VGA_P_drawPrimitive(&centerPos[i],
										&radii[i],
										r,
										color[i],
										VGA_COL_TRANSPARENT,
										lineWeight[i],
										shape[i]);
			if(status != VGA_SUCCESS) {
				return status;
			}
		}
	}

	status = VGA_FX_bloomScreen(VGA_BLOOM_INT_3);

	return status;
}

status_t setDemoText(){
	status_t status = VGA_SUCCESS;

	char text[] = "Demo software ontwikkeling!";
	sPosition_t sPos = {100,100};

	status = VGA_P_printString(sPos, text, Size_24, Regular, VGA_COL_RED);

	char text2[] = "Demo software ontwikkeling!";
	sPosition_t sPos2 = {100,100};

	status = VGA_P_printString(sPos2, text2, Size_12, Bold, VGA_COL_WHITE);

	return status;
}

status_t setDemoShapes(){
	status_t status = VGA_SUCCESS;

	sPosition_t sPos1[4] = {
						  {100,100}
						, {125,100}
						, {100,200}
						, {125,200}
						};

	status = VGA_P_drawPolygon(sPos1, 4, VGA_COL_CYAN, VGA_COL_MAGENTA, 4);

	sPosition_t sPos2[8] = {
							  {100,100}
							, {125,100}
							, {100,200}
							, {125,200}
							, {125,100}
							, {100,200}
							, {125,200}
							, {124,200}
							};

	status = VGA_P_drawPolygon(sPos2, 8, VGA_COL_CYAN, VGA_COL_MAGENTA, 4);

	int i;
	sRadii_t rot = {40, 20};
	sPosition_t sPos3 = {150, 150};

	for(i=0;i<360;i+=60){
		VGA_P_drawPrimitive(&sPos3, &rot, i, VGA_COL_YELLOW, VGA_COL_BLACK, 4, VGA_ELLIPSE);
	}




	return status;
}

/* End of file fx_data.c */
