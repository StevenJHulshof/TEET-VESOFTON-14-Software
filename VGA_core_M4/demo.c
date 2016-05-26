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

	//create status variable to catch function returns.
	status_t status = VGA_SUCCESS;

	//loop variables
	int i, r;

	//fill background and catch the status.
	status = VGA_P_fillScreen(VGA_COL_BLUE);
	if(status != VGA_SUCCESS)
		return status;

	//initialize array with the centre positions of the different figures.
	sPosition_t centerPos[5] = {
			{50, 50},
			{270, 50},
			{50, 190},
			{270, 190},
			{160, 120}
	};

	//initialize array with length and width of the different figures.
	sRadii_t radii[5] = {
			{10, 80},
			{10, 80},
			{10, 80},
			{10, 80},
			{80, 10}
	};

	//initialize array with different kind of primitive shapes.
	primitiveShape_t shape[5] = {
			VGA_TRIANGLE,
			VGA_SQUARE,
			VGA_PENTAGON,
			VGA_HEXAGON,
			VGA_ELLIPSE
	};

	//initialize array with colors for the different primitive figures.
	color_t color[5] = {
			VGA_COL_YELLOW,
			VGA_COL_YELLOW-30,
			VGA_COL_GREEN+30,
			VGA_COL_GREEN,
			VGA_COL_RED
	};

	//initialize array with line weights for the different figures.
	uint8_t lineWeight[5] = {1, 1, 1, 1, 3};

	for(i = 0; i < 5; i++) {
		for(r = 0; r < 360; r+=10) {
			//draw shapes and catch the status.
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

	//apply bloom FX to the screen, drawn up to this point.
	status = VGA_FX_bloomScreen(VGA_BLOOM_INT_3);

	return status;
}

status_t setDemoText(){
	//initialize status to catch function returns.
	status_t status = VGA_SUCCESS;

	//create string with function text.
	char text[] = "Demo VGA_lib API!";

	//initialize position structure for the position
	sPosition_t sPos = {50,20};

	//print string and catch the status
	status = VGA_P_printString(sPos, text, Size_24, Bold, VGA_COL_WHITE);
	if (status != VGA_SUCCESS)
		return status;

	//initialize string with emoji set to print
	char text3[] = "HJC@6'&% ";

	//change values in the sPos aray for the next string
	sPos.x = 60;
	sPos.y = 44;

	//print string and catch the status
	status = VGA_P_printString(sPos, text3, Size_24, Emoji, VGA_COL_WHITE);
	//status = VGA_L_processStringData(text3, Size_24, Emoji, sPos, VGA_COL_WHITE);
	if (status != VGA_SUCCESS)
			return status;

	//initialize string with text to print on the screen.
	char text2[] = "Demo Text!";

	//initialize array with the centre position of the string.
	sPosition_t sPos2 = {80,80};

	//print the string and catch the status.
	status = VGA_P_printString(sPos2, text2, Size_18, Bold, VGA_COL_YELLOW);
	if (status != VGA_SUCCESS)
			return status;

	//initialize string with text to print on the screen.
	char text4[] = "By: Niek, Lukas en Steven";

	//initialize sPos array with the position of the next string.
	sPos.x = 105;
	sPos.y = 66;

	//print the string and catch the status.
	VGA_P_printString(sPos, text4, Size_12, Regular, VGA_COL_MAGENTA);
	if (status != VGA_SUCCESS)
			return status;

	return status;
}

status_t setDemoShapes(){
	//create variable to catch function status for error handling.
	status_t status = VGA_SUCCESS;

	//initialize array of position structures for the polygon vertices.
	sPosition_t sPos1[4] = {
						  {35,15}
						, {310,15}
						, {310,100}
						, {35,100}
						};

	//draw figures and catch the status of the operation.
	status = VGA_P_drawPolygon(sPos1, 4, VGA_COL_CYAN, VGA_COL_BLUE, 4);
	if (status != VGA_SUCCESS)
			return status;

	//initialize array of position structures for the polygon vertices.
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

	//draw figures and catch the status of the operation.
	status = VGA_P_drawPolygon(sPos2, 8, VGA_COL_CYAN, VGA_COL_MAGENTA, 1);
	if (status != VGA_SUCCESS)
			return status;

	//initialize structure for the radius of the width and length of the primitive figure.
	sRadii_t rot = {60, 20};

	//initialize structure for the position of the primitive figure.
	sPosition_t sPos3 = {160, 200};

	//draw figure and catch the status of the operation.
	status = VGA_P_drawPrimitive(&sPos3, &rot, 0, VGA_COL_YELLOW, VGA_COL_GREEN, 5, VGA_ELLIPSE);
	if (status != VGA_SUCCESS)
			return status;

	//initialize array of structures for the endpoints of the line.
	sPosition_t endPos[2] = {
			{20, 110},
			{300, 220},
	};

	//draw the line and catch the status of the operation.
	status = VGA_P_drawLine(endPos, VGA_COL_RED, 5);
	if (status != VGA_SUCCESS)
			return status;

	//initialize structure for the center position of the primitive shape.
	sPosition_t sPos4 = {300, 150};

	//initialize structure for the radius of the width and length of the figure.
	sRadii_t radii = {100, 30};

	//draw the figure and catch the status of the operation.
	status = VGA_P_drawPrimitive(&sPos4, &radii, 10, VGA_COL_GREEN, VGA_COL_TRANSPARENT, 10, VGA_PENTAGON);
	if (status != VGA_SUCCESS)
			return status;


	return status;
}

/* End of file demo.c */
