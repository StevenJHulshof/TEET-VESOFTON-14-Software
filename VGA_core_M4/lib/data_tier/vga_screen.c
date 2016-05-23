/*******************************************************************************
 * Begin of file vga_screen.c
 *
 * @author: -
 * @revised: Steven Hulshof
 * Created: 21/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief 	VGA-out through GPIO. PB11 (HSYNC), PB12 (VSYNC), PE8+PE9 (BLUE),
 * 			PE10-PE12 (GREEN), PE13-PE15 (RED).
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "vga_screen.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
 * @brief	Initialize VGA screen.
 */
void VGA_screenInit(void) {

	uint16_t xp,yp;

	VGA.hsync_cnt=0;
	VGA.start_adr=0;
	VGA.dma2_cr_reg=0;

	// RAM init total black
	for(yp=0;yp<VGA_DISPLAY_Y;yp++) {
		for(xp=0;xp<(VGA_DISPLAY_X+1);xp++) {
			VGA_RAM1[(yp*(VGA_DISPLAY_X+1))+xp]=0;
		}
	}

	// init IO-Pins
	VGA_initGpio();
	// init Timer
	VGA_initTimers();
	// init DMA
	VGA_initDma();
	// init Interrupts
	VGA_initInterrupts();

	//-----------------------
	// Register swap and safe
	//-----------------------
	// content of CR-Register read and save
	VGA.dma2_cr_reg=DMA2_Stream5->CR;
}

/**
 * @brief	Initializes GPIO used for VGA output.
 */
void VGA_initGpio(void) {

	GPIO_InitTypeDef  GPIO_InitStructure;

	//---------------------------------------------
	// init RGB-Pins (PE8 - PE15)
	// as normal GPIOs
	//---------------------------------------------

	// Clock Enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	// Config as Digital output
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 |
								GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	GPIOE->BSRRH = VGA_GPIO_HINIBBLE;

	//---------------------------------------------
	// init of the H-Sync Pin (PB11)
	// using Timer2 and CH4
	//---------------------------------------------

	// Clock Enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	// Config Pins as Digital-out
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	// alternative function connect with IO
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_TIM2);

	//---------------------------------------------
	// init of V-Sync Pin (PB12)
	// using GPIO
	//---------------------------------------------

	// Clock Enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	// Config of the Pins as Digital out
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIOB->BSRRL = GPIO_Pin_12;
}

/**
 * @brief	Initializes VGA timers.
 */
void VGA_initTimers(void) {

	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	//---------------------------------------------
	// init of Timer1 for
	// Pixeldata via DMA
	//---------------------------------------------

	// Clock enable
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

	// Timer1 init
	TIM_TimeBaseStructure.TIM_Period =  VGA_TIM1_PERIODE;
	TIM_TimeBaseStructure.TIM_Prescaler = VGA_TIM1_PRESCALE;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

	//---------------------------------------------
	// init Timer2
	// CH4 for HSYNC-Signal
	// CH3 for DMA Trigger start
	//---------------------------------------------

	// Clock enable
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	// Timer2 init
	TIM_TimeBaseStructure.TIM_Period = VGA_TIM2_HSYNC_PERIODE;
	TIM_TimeBaseStructure.TIM_Prescaler = VGA_TIM2_HSYNC_PRESCALE;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	// Timer2 Channel 3 ( for DMA Trigger start)
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = VGA_TIM2_HTRIGGER_START-VGA_TIM2_DMA_DELAY;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);

	// Timer2 Channel 4 (for HSYNC)
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = VGA_TIM2_HSYNC_IMP;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);

	//---------------------------------------------
	// enable all Timers
	//---------------------------------------------

	// Timer1 enable
	TIM_ARRPreloadConfig(TIM1, ENABLE);

	// Timer2 enable
	TIM_ARRPreloadConfig(TIM2, ENABLE);
	TIM_Cmd(TIM2, ENABLE);

}

/**
 * @brief	Initializes VGA interrupts.
 */
void VGA_initInterrupts(void) {

	NVIC_InitTypeDef NVIC_InitStructure;

	//---------------------------------------------
	// init from DMA Interrupt
	// for TransferComplete Interrupt
	// DMA2, Stream5, Channel6
	//---------------------------------------------

	DMA_ITConfig(DMA2_Stream5, DMA_IT_TC, ENABLE);

	// NVIC config
	NVIC_InitStructure.NVIC_IRQChannel = DMA2_Stream5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	//---------------------------------------------
	// init of Timer2 Interrupt
	// for HSync-Counter using Update
	// for DMA Trigger START using CH3
	//---------------------------------------------

	TIM_ITConfig(TIM2,TIM_IT_CC3,ENABLE);

	// NVIC config
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

/**
 * @brief	Initializes VGA DMA.
 */
void VGA_initDma(void) {

	DMA_InitTypeDef DMA_InitStructure;

	//---------------------------------------------
	// DMA of Timer1 Update
	// (look at page 217 of the Ref Manual)
	// DMA=2, Channel=6, Stream=5
	//---------------------------------------------

	// Clock Enable (DMA)
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);

	// DMA init (DMA2, Channel6, Stream5)
	DMA_Cmd(DMA2_Stream5, DISABLE);
	DMA_DeInit(DMA2_Stream5);
	DMA_InitStructure.DMA_Channel = DMA_Channel_6;
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)VGA_GPIOE_ODR_ADDRESS;
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&VGA_RAM1;
	DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
	DMA_InitStructure.DMA_BufferSize = VGA_DISPLAY_X+1;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
	DMA_Init(DMA2_Stream5, &DMA_InitStructure);

	// DMA-Timer1 enable
	TIM_DMACmd(TIM1,TIM_DMA_Update,ENABLE);
}

/**
 * @brief 	Timer 2 Interrupt. CC3-Interrupt -> starts from DMA.
 *
 * @note	Higher trough put when interrupt flag is left alone
 */
void TIM2_IRQHandler(void) {


  	// Interrupt of Timer2 CH3 occurred (for Trigger start)
	TIM_ClearITPendingBit(TIM2, TIM_IT_CC3);


	VGA.hsync_cnt++;
	if(VGA.hsync_cnt>=VGA_VSYNC_PERIODE) {
		// -----------
		VGA.hsync_cnt=0;
		// Adresspointer first dot
		VGA.start_adr=(uint32_t)(&VGA_RAM1[0]);
	}

	// HSync-Pixel
	if(VGA.hsync_cnt<VGA_VSYNC_IMP) {
		// HSync low
		GPIOB->BSRRH = GPIO_Pin_12;
	}
	else {
		// HSync High
		GPIOB->BSRRL = GPIO_Pin_12;
	}

	// Test for DMA start
	if((VGA.hsync_cnt>=VGA_VSYNC_BILD_START) && (VGA.hsync_cnt<=VGA_VSYNC_BILD_STOP)) {
		// after FP start => DMA Transfer

		// DMA2 init
		DMA2_Stream5->CR=VGA.dma2_cr_reg;
		// set adress
		DMA2_Stream5->M0AR=VGA.start_adr;
		// Timer1 start
		TIM1->CR1|=TIM_CR1_CEN;
		// DMA2 enable
		DMA2_Stream5->CR|=DMA_SxCR_EN;

		// Test Adrespointer for high
    	if((VGA.hsync_cnt & 0x01)!=0) {
    		// inc after Hsync
    		VGA.start_adr+=(VGA_DISPLAY_X+1);
    	}
  	}


}

/**
 * @brief 	DMA interrupt ISR.
 *
 * @note	After TransferCompleteInterrupt -> stop DMA. Still a bit buggy.
 */
void DMA2_Stream5_IRQHandler(void) {

	//VGA_lockFlag = 1;
	if(DMA_GetITStatus(DMA2_Stream5, DMA_IT_TCIF5)) {

		// Disable function calculations
		//VGA_lockFlag = 1;

		// TransferInterruptComplete Interrupt from DMA2
		DMA_ClearITPendingBit(DMA2_Stream5, DMA_IT_TCIF5);
		// stop after all pixels => DMA Transfer stop

		// Timer1 stop
		TIM1->CR1&=~TIM_CR1_CEN;
		// DMA2 disable
		DMA2_Stream5->CR=0;
		// switch on black
		GPIOE->BSRRH = VGA_GPIO_HINIBBLE;


		// Enable function calculations
	}
	//VGA_lockFlag = 0;
}
/* End of file vga_screen.c */
