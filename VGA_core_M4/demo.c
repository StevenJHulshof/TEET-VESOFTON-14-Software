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

	//status = VGA_FX_bloomScreen(VGA_BLOOM_INT_3);

	return status;
}

status_t setDemoText(){
	status_t status = VGA_SUCCESS;

	char text[] = "Demo software ontwikkeling!";
	sPosition_t sPos = {50,20};

//	status = VGA_P_printString(sPos, text, Size_24, Regular, VGA_COL_RED);

	VGA_L_processStringData(text, SIZE_24, BOLD, sPos, VGA_COL_WHITE);

	char text3[] = "HJC@6'&% ";
	sPos.x = 60;
	sPos.y = 44;
	VGA_L_processStringData(text3, SIZE_24, EMOJI, sPos, VGA_COL_WHITE);

	char text2[] = "Welkom Franc en Michiel!";
	sPosition_t sPos2 = {80,80};

	status = VGA_P_printString(sPos2, text2, SIZE_18, BOLD, VGA_COL_YELLOW);

	char text4[] = "Door: Niek, Lukas en Steven";
		sPos.x = 105;
		sPos.y = 66;
		VGA_L_processStringData(text4, SIZE_12, REGULAR, sPos, VGA_COL_MAGENTA);

	return status;
}

status_t setDemoShapes(){
	status_t status = VGA_SUCCESS;

	sPosition_t sPos1[4] = {
						  {35,15}
						, {310,15}
						, {310,100}
						, {35,100}
						};

	status = VGA_P_drawPolygon(sPos1, 4, VGA_COL_CYAN, VGA_COL_BLUE, 4);

	sPosition_t sPos2[8] = {
							  {20,200}
							, {30,170}
							, {50,220}
							, {25,190}
							, {10,170}
							, {60,200}
							, {75,165}
							, {5,190}
							};

	status = VGA_P_drawPolygon(sPos2, 8, VGA_COL_CYAN, VGA_COL_MAGENTA, 1);

//	int i;
	sRadii_t rot = {60, 20};
	sPosition_t sPos3 = {160, 200};

	//for(i=0;i<360;i+=20){
		VGA_P_drawPrimitive(&sPos3, &rot, 0, VGA_COL_YELLOW, VGA_COL_GREEN, 5, VGA_ELLIPSE);
//	}
	sPosition_t endPos[2] = {
			{20, 110},
			{300, 220},
	};
	VGA_P_drawLine(endPos, VGA_COL_RED, 5);

	sPosition_t sPos4 = {300, 150};
	sRadii_t radii = {100, 30};
	VGA_P_drawPrimitive(&sPos4, &radii, 10, VGA_COL_GREEN, VGA_COL_TRANSPARENT, 10, VGA_PENTAGON);


	return status;
}

/* End of file fx_data.c */
