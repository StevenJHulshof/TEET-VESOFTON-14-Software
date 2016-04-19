/******************************************************************************
 * Begin of file header_example.h
 * @author: Steven Hulshof
 * @version: 1.0
 * Created: 19/04/2016 
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
 /** @file
 * @brief Contains example layout for header files.
 * 
 ******************************************************************************/

#ifndef HEADER_EXAMPLE_H_
#define HEADER_EXAMPLE_H_

/*******************************************************************************
 * Defines
 ******************************************************************************/
/** @brief Oscillator Clock frequency */
#define FOSC 16000000UL

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdint.h>

/*******************************************************************************
 * Enumerators
 ******************************************************************************/
/** @brief Specifies clock rate of SPI */
typedef enum {
	SPI_FOSC_DIV_4 = 0x00,
	SPI_FOSC_DIV_16 = 0x01,
	SPI_FOSC_DIV_64 = 0x02,
	SPI_FOSC_DIV_128 = 0x03,
	SPI_FOSC_DIV2_2 = 0x04,
	SPI_FOSC_DIV2_8 = 0x05,
	SPI_FOSC_DIV2_32 = 0x06,
	SPI_FOSC_DIV2_64 = 0x07
} spiClockSelect_t;

/*******************************************************************************
 * Data structures
 ******************************************************************************/
/** @brief Structure containing data for configuring SPI */
typedef struct SPI_INITSTRUCTURE {
	
	/** @brief Enable/disable bit */
	spiEnableDisable_t enableDisable;
	
    /** @brief Data order */
    spiDataOrder_t dataOrder;

	/** @brief Master/slave mode */
	spiMasterSlaveMode_t masterSlaveMode;
	
	/** @brief Clock polarity */
	spiClockPolarity_t clockPolarity;
	
	/** @brief Clock selection */
	spiClockSelect_t clockSelect;
} SPI_InitStructure;

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
* @brief Initialize the SPI module
*
* @note Example note, use this if you want to describe something the user
*		needs to take into account (e.g. This function only works when,
*		F_CPU is defined). 
*
* @param *spiInitStructure Initialization structure for SPI module.
*/
void SPI_config(SPI_InitStructure *spiInitStructure);

#endif /* HEADER_EXAMPLE_H_ */
/* End of file header_example.h */
