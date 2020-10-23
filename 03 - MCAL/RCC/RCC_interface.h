/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 8 August 2020							*/
/************************************************/
#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

/**************************************************          Macros          ************************************************************/

// Bus Id

#define MRCC_AHB			  	0
#define MRCC_APB2		  		2
#define MRCC_APB1		  		1

//peripheral id bits for AHB
#define MRCC_DMA1_PERIPHERAL     0
#define MRCC_DMA2_PERIPHERAL     1
#define MRCC_SRAM_PERIPHERAL     2
#define MRCC_FLITF_PERIPHERAL    4
#define MRCC_CRCE_PERIPHERAL     6
#define MRCC_FSMC_PERIPHERAL     8
#define MRCC_SDIO_PERIPHERAL     10

//peripheral id bits for APB2
#define MRCC_AFIO_PERIPHERAL     0
#define MRCC_IOPA_PERIPHERAL     2
#define MRCC_IOPB_PERIPHERAL     3
#define MRCC_IOPC_PERIPHERAL     4
#define MRCC_IOPD_PERIPHERAL     5
#define MRCC_IOPE_PERIPHERAL     6
#define MRCC_IOPF_PERIPHERAL     7
#define MRCC_IOPG_PERIPHERAL     8
#define MRCC_ADC1_PERIPHERAL     9
#define MRCC_ADC2_PERIPHERAL     10
#define MRCC_TIM1_PERIPHERAL     11
#define MRCC_SPI1_PERIPHERAL     12
#define MRCC_TIM8_PERIPHERAL     13
#define MRCC_USART1_PERIPHERAL   14
#define MRCC_ADC3_PERIPHERAL     15
#define MRCC_TIM9_PERIPHERAL     19
#define MRCC_TIM10_PERIPHERAL    20
#define MRCC_TIM11_PERIPHERAL    21

//peripheral id bits for APB1
#define MRCC_TIM2_PERIPHERAL     0
#define MRCC_TIM3_PERIPHERAL     1
#define MRCC_TIM4_PERIPHERAL     2
#define MRCC_TIM5_PERIPHERAL     3
#define MRCC_TIM6_PERIPHERAL     4
#define MRCC_TIM7_PERIPHERAL     5
#define MRCC_TIM12_PERIPHERAL    6
#define MRCC_TIM13_PERIPHERAL    7
#define MRCC_TIM14_PERIPHERAL    8
#define MRCC_WWD_PERIPHERAL      11
#define MRCC_SPI2_PERIPHERAL     14
#define MRCC_SPI3_PERIPHERAL     15
#define MRCC_USART2_PERIPHERAL   17
#define MRCC_USART3_PERIPHERAL   18
#define MRCC_USART4_PERIPHERAL   19
#define MRCC_USART5_PERIPHERAL   20
#define MRCC_I2C1_PERIPHERAL     21
#define MRCC_I2C2_PERIPHERAL     22
#define MRCC_USB_PERIPHERAL      23
#define MRCC_CAN_PERIPHERAL      25
#define MRCC_BKP_PERIPHERAL      27
#define MRCC_PWR_PERIPHERAL      28
#define MRCC_DAC_PERIPHERAL      29



/****************************************************************************************************************************************/

/*************************************************          Functions          **********************************************************/

/****************************************************************************************************************************************/
/* MRCC_voidInitSysClock --> Initializes SYSCLK, Enabling and selecting the needed SYSCLK source and selecting the value of PLL if used.	*/
/* I/P:- void (Takes the wanted values from RCC_config file).																			*/
/* O/P:- void (Initializes SYSCLK).																										*/
void MRCC_voidInitSysClock(void);
/****************************************************************************************************************************************/

/********************************************************************/
/* MRCC_voidEnableClock --> Enables Clock for a certain peripheral 	*/
/* I/P:-  
	Copy_u8BusId:- Id of the bus on which the peripheral is
	Copy_u8PerId:- Id of the peripheral							  	*/
/* O/P:- void(Enables Clock for a certain peripheral) 			  	*/
void MRCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);
/********************************************************************/

/********************************************************************/
/* MRCC_voidDisableClock --> Disables Clock for a certain peripheral	*/
/* I/P:-  
	Copy_u8BusId:- Id of the bus on which the peripheral is
	Copy_u8PerId:- Id of the peripheral							  	*/
/* O/P:- void(Disables Clock for a certain peripheral) 			  	*/
void MRCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);
/********************************************************************/

/********************************************************************/
/* MRCC_voidResetRegisters --> Disables clock for all peripherals & Resets all RCC registers	*/
/* I/P:- void													  							*/
/* O/P:- void 			  																	*/
void MRCC_voidResetRegisters(void);
/********************************************************************************************/

/****************************************************************************************************************************************/


#endif
