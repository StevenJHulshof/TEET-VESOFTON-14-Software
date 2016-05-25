/*******************************************************************************
 * Begin of file vga_screen.h
 *
 * @author: -
 * @revised: Steven Hulshof
 * Created: 21/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief VGA-out through GPIO. PB11 (HSYNC), PB12 (VSYNC), PE8+PE9 (BLUE),
 * 			PE10-PE12 (GREEN), PE13-PE15 (RED).
 *
 ******************************************************************************/

#ifndef VGA_SCREEN_H_
#define VGA_SCREEN_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "system.h"

/*******************************************************************************
 * Globals
 ******************************************************************************/
/** @brief Contains VGA screen data. */
uint8_t VGA_RAM1[(VGA_DISPLAY_X+1)*VGA_DISPLAY_Y];

volatile uint8_t V_SYNC_FLAG;

/** @brief VGA data structure. */
VGA_t VGA;

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief	Initialize VGA screen.
 */
void VGA_D_screenInit(void);

/**
 * @brief	Initializes GPIO used for VGA output.
 */
void VGA_D_initGpio(void);

/**
 * @brief	Initializes VGA timers.
 */
void VGA_D_initTimers(void);

/**
 * @brief	Initializes VGA interrupts.
 */
void VGA_D_initInterrupts(void);

/**
 * @brief	Initializes VGA DMA.
 */
void VGA_D_initDma(void);

/**
 * @brief 	Timer 2 Interrupt. CC3-Interrupt -> starts from DMA.
 *
 * @note	Higher trough put when interrupt flag is left alone
 */
void TIM2_IRQHandler(void);

/**
 * @brief 	DMA interrupt ISR.
 *
 * @note	After TransferCompleteInterrupt -> stop DMA. Still a bit buggy.
 */
void DMA2_Stream5_IRQHandler(void);

#endif /* VGA_SCREEN_H_ */
/* End of file vga_screen.h */
