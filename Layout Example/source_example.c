 /*******************************************************************************
 * Begin of file source_example.c
 * @author: Steven Hulshof
 * @version: 1.0
 * Created: 19/04/2016 
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Contains example layout for source files.
 * 
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "header_example.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
void SPI_config(SPI_InitStructure *spiInitStructure) 
{       
	// Random variable 1
	uint8_t		exampleOne = 0x00;
	
	// Random variable 2
	uint16_t	exampleTwo = 0x0000;
	
	// Random variable 3
	char*		exampleThree;
	
	// Reset SPI registers
    SPCR = 0x00;    // Control register
    SPSR = 0x00;    // Status register
    SPDR = 0x00;    // Data register
    
	// Configurate SPI registers
    SPCR |= (spiInitStructure->dataOrder << DORD)                   |
                (spiInitStructure->masterSlaveMode << MSTR)         |
                (spiInitStructure->clockPolarity << CPOL)           |
                ((spiInitStructure->clockSelect & 0x03) << SPR0);

    SPSR |= ((spiInitStructure->clockSelect & 0x04) << SPI2X);

    // Enable/disable the SPI module
    SPCR |= (spiInitStructure->enableDisable << SPE);
}
/* End of file source_example.c */
