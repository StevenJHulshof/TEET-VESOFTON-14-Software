/******************************************************************************
 * Begin of file system.h
 *
 * @author: Steven Hulshof
 * Created: 10/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
 /** @file
 * @brief Defines, data structures and enumerations for the VGA-lib.
 *
 ******************************************************************************/

#ifndef SYSTEM_H_
#define SYSTEM_H_

/*******************************************************************************
 * Defines
 ******************************************************************************/
/**	@brief Number of samples used to plot the primitive. */
#define MAX_SAMPLES			50

/** @brief Macro defining infinity. */
#define INF	9999

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "stm32_ub_vga_screen.h"

/*******************************************************************************
 * Data structures
 ******************************************************************************/
/** @brief Position structure. */
typedef struct {

	/** @brief X coordinate. */
	int x;

	/** @brief Y coordinate. */
	int y;
} sPosition_t;

/**	@brief Radii structure. */
typedef struct {

	/** @brief Radius x length. */
	float x;

	/** @brief Radius y length. */
	float y;
} sRadii_t;

/*******************************************************************************
 * Enumerators
 ******************************************************************************/
/** @brief Status codes. */
typedef enum {

	VGA_SUCCESS							= 0x00,
	VGA_PIXEL_NOT_SET					= 0x01,
	VGA_ERROR_ARGUMENT_OUT_OF_BOUNDS	= 0x02,
	VGA_ERROR_PIXEL_OUTSIDE_SCREEN		= 0x03
} status_t;

/** @brief Default color scheme. */
typedef enum {

	VGA_COL_BLACK 		= 0x00,
	VGA_COL_BLUE 		= 0x03,
	VGA_COL_GREEN 		= 0x1C,
	VGA_COL_RED 		= 0xE0,
	VGA_COL_WHITE 		= 0xFF,
	VGA_COL_CYAN 		= 0x1F,
	VGA_COL_MAGENTA 	= 0xE3,
	VGA_COL_YELLOW 		= 0xFC,
	VGA_COL_TRANSPARENT = -0x01
} color_t;

/** @brief Default primitive shapes */
typedef enum {

	VGA_TRIANGLE 	= 0x03,
	VGA_SQUARE		= 0x04,
	VGA_PENTAGON	= 0x05,
	VGA_HEXAGON		= 0x06,
	VGA_HEPTAGON	= 0x07,
	VGA_OCTAGON		= 0x08,
	VGA_NONAGON		= 0x09,
	VGA_DECAGON		= 0xA0,
	VGA_ELLIPSE 	= 0x19
} primitiveShape_t;

#endif /* SYSTEM_H_ */
/* End of file system.h */
