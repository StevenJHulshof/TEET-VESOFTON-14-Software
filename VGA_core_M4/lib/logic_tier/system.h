/******************************************************************************
 * Begin of file system.h
 *
 * @author: Steven Hulshof
 * Created: 10/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
 /** @file
 * @brief Defines and enumerations for the VGA-lib.
 *
 ******************************************************************************/

#ifndef SYSTEM_H_
#define SYSTEM_H_

/*******************************************************************************
 * Defines
 ******************************************************************************/
/**	@brief Number of samples used to plot the ellipse. */
#define MAX_SAMPLES			50

#define LINE_WEIGHT_SAMPLES	20
#define LINE_WEIGHT_RESOLUTION	2 * M_PI / LINE_WEIGHT_SAMPLES

/**	@brief Number of samples used to plot the ellipse. */
#define ELLIPSE_SAMPLES		20

/** @brief Determines ellipse draw resolution. */
#define ELLIPSE_RESOLUTION	2 * M_PI / ELLIPSE_SAMPLES

/** @brief Macro defining infinity. */
#define INF	9999

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "stm32_ub_vga_screen.h"
#include "fontlibrary.h"
#include "fonts_display.h"

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

	VGA_SUCCESS,
	VGA_PIXEL_NOT_SET,
	VGA_ERROR_ARGUMENT_OUT_OF_BOUNDS
} status_t;

/** @brief Default color scheme. */
typedef enum {

	VGA_COL_BLACK = 0x00,
	VGA_COL_BLUE = 0x03,
	VGA_COL_GREEN = 0x1C,
	VGA_COL_RED = 0xE0,
	VGA_COL_WHITE = 0xFF,
	VGA_COL_CYAN = 0x1F,
	VGA_COL_MAGENTA = 0xE3,
	VGA_COL_YELLOW = 0xFC,
	VGA_COL_TRANSPARENT = -0x01
} color_t;

typedef enum {

	VGA_TRIANGLE = 0x03,
	VGA_SQUARE,
	VGA_PENTAGON,
	VGA_HEXAGON,
	VGA_HEPTAGON,
	VGA_OCTAGON,
	VGA_NONAGON,
	VGA_DECAGON,
	VGA_ELLIPSE = 0x25
} sampleSize_t;

#endif /* SYSTEM_H_ */
/* End of file system.h */
