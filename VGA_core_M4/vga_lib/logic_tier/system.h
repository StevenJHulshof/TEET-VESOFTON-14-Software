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
#define MAX_SAMPLES	50

/** @brief Macro defining infinity. */
#define INF	9999

/** @brief VGA display width. */
#define VGA_DISPLAY_X 320

/** @brief VGA display height. */
#define VGA_DISPLAY_Y 240

/** @brief VGA Timer 1 periode. */
#define VGA_TIM1_PERIODE 11

/** @brief VGA Timer 1 prescaler. */
#define VGA_TIM1_PRESCALE 0

/** @brief VGA Timer 2 HSync periode. */
#define VGA_TIM2_HSYNC_PERIODE 2667

/** @brief VGA Timer 2 HSync prescaler. */
#define VGA_TIM2_HSYNC_PRESCALE	0

/** @brief VGA Timer 2 HSync - length (3.81 us). */
#define VGA_TIM2_HSYNC_IMP 320

/** @brief VGA Timer 2 HSync + Backporch (5.71 us). */
#define VGA_TIM2_HTRIGGER_START 480

/** @brief VGA Timer 2 DMA delay. */
#define VGA_TIM2_DMA_DELAY 60

/** @brief VGA VSync periode. */
#define VGA_VSYNC_PERIODE 525

/** @brief VGA VSync IMP. */
#define VGA_VSYNC_IMP 2

/** @brief VGA VSync BILD start. */
#define VGA_VSYNC_BILD_START 36

/** @brief VGA VSync BILD stop (16.38 ms). */
#define VGA_VSYNC_BILD_STOP 514

/** @brief VGA GPIO E address. */
#define VGA_GPIOE_BASE_ADR ((uint32_t)0x40021000)

/** @brief VGA GPIO ODR address. */
#define VGA_GPIO_ODR_OFFSET ((uint32_t)0x00000014)

/** @brief VGA GPIO data byte. */
#define VGA_GPIO_BYTE_OFFSET ((uint32_t)0x00000001)

/** @brief VGA GPIO E ODR address. */
#define VGA_GPIOE_ODR_ADDRESS (VGA_GPIOE_BASE_ADR | VGA_GPIO_ODR_OFFSET | VGA_GPIO_BYTE_OFFSET)

/** @brief VGA GPIO high nibble (GP8 to GP15). */
#define VGA_GPIO_HINIBBLE ((uint16_t)0xFF00)

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "misc.h"
#include "stm32f4xx_dma.h"

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

/** @brief VGA data structure. */
typedef struct {

	/** @brief HSync counter. */
	uint16_t hSyncCnt;

	/** @brief Starting address. */
	uint32_t startAdr;

	/** @brief Register constant CR-Register. */
	uint32_t dma2CrReg;
} VGA_t;

/** @brief Struct for fontstyle in sram*/
typedef struct {

	/**@brief Number of glyphs in style. **/
	uint8_t glyphCount;

	/**@brief Decimal value of first ASCII char **/
    uint8_t firstAsciiCode;

    /**@brief Horizontal number of bytes. **/
    uint8_t glyphBytesWidth;

    /**@brief Vertical number of bytes (also pixel height). **/
    uint8_t glyphHeight;

    /**@brief Fixed width, 0 if variable. **/
    uint8_t fixedWidth;

    /**@brief Array with pixelwidth per glyph. **/
    uint8_t const *glyphWidth;

    /**@brief Array with bitmaps for style.**/
    uint8_t const *glyphBitmaps;
} fontStyle_t;

/** @brief Retreived character structure. */
typedef struct {

	/** @brief Pointer to the first byte with pixels. */
	uint8_t* firstByte;

	/** @brief Total width of bytes for bitmap. */
	uint8_t byteWidth;

	/** @brief Pixel width of retreived char. */
	uint8_t charWidth;

	/** @brief Pixel height of retrieved char. */
	uint8_t charHeight;
} sBitmap_t;

/*******************************************************************************
 * Enumerators
 ******************************************************************************/
/** @brief Image border minimum and maximum. */
enum {
	MIN,
	MAX
};

/** @brief Status codes. */
typedef enum {

	VGA_SUCCESS						= 0x00,
	VGA_PIXEL_NOT_SET				= 0x01,
	VGA_LINE_COL_OUT_OF_BOUNDS		= 0x02,
	VGA_FILL_COL_OUT_OF_BOUNDS		= 0x03,
	VGA_LINE_WEIGHT_OUT_OF_BOUNDS	= 0x04,
	VGA_RADII_OUT_OF_BOUNDS			= 0x05,
	VGA_PIXEL_OUT_OF_SCREEN			= 0x06,
	VGA_STRING_INVALID_FONTSTYLE	= 0x07,
	VGA_STRING_INVALID_FONTSIZE		= 0x08,
	VGA_STRING_COL_OUT_OF_BOUNDS	= 0x09,
	VGA_BLOOM_INT_OUT_OF_BOUNDS		= 0x0A
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
	VGA_DECAGON		= 0x0A,
	VGA_ELLIPSE 	= 0x19
} primitiveShape_t;

/** @brief Usable bloom intensities. */
typedef enum {

	VGA_BLOOM_INT_1 = 0x01,
	VGA_BLOOM_INT_2 = 0x02,
	VGA_BLOOM_INT_3 = 0x03,
	VGA_BLOOM_INT_4 = 0x04,
	VGA_BLOOM_INT_5 = 0x05,
	VGA_BLOOM_INT_6 = 0x06,
	VGA_BLOOM_INT_7 = 0x07,
} bloomIntensity_t;

/** @brief Enum for sizes. */
 typedef enum {
	SIZE_18,
	SIZE_12,
	SIZE_24
} charSize_t;

/** @brief Enum for styles. */
 typedef enum {
	REGULAR,
	BOLD,
	EMOJI
} charStyle_t;

#endif /* SYSTEM_H_ */
/* End of file system.h */
