/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 8 August 2020							*/
/************************************************/
#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

/**************************************************          Macros          ************************************************************/

// Bus Id

#define RCC_AHB			  		0
#define RCC_APB2		  		2
#define RCC_APB1		  		1

//peripheral id bits for AHB
#define RCC_DMA1_PERIPHERAL     0
#define RCC_DMA2_PERIPHERAL     1
#define RCC_SRAM_PERIPHERAL     2
#define RCC_FLITF_PERIPHERAL    4
#define RCC_CRCE_PERIPHERAL     6
#define RCC_FSMC_PERIPHERAL     8
#define RCC_SDIO_PERIPHERAL     10

//peripheral id bits for APB2
#define RCC_AFIO_PERIPHERAL     0
#define RCC_IOPA_PERIPHERAL     2
#define RCC_IOPB_PERIPHERAL     3
#define RCC_IOPC_PERIPHERAL     4
#define RCC_IOPD_PERIPHERAL     5
#define RCC_IOPE_PERIPHERAL     6
#define RCC_IOPF_PERIPHERAL     7
#define RCC_IOPG_PERIPHERAL     8
#define RCC_ADC1_PERIPHERAL     9
#define RCC_ADC2_PERIPHERAL     10
#define RCC_TIM1_PERIPHERAL     11
#define RCC_SPI1_PERIPHERAL     12
#define RCC_TIM8_PERIPHERAL     13
#define RCC_USART1_PERIPHERAL   14
#define RCC_ADC3_PERIPHERAL     15
#define RCC_TIM9_PERIPHERAL     19
#define RCC_TIM10_PERIPHERAL    20
#define RCC_TIM11_PERIPHERAL    21

//peripheral id bits for APB1
#define RCC_TIM2_PERIPHERAL     0
#define RCC_TIM3_PERIPHERAL     1
#define RCC_TIM4_PERIPHERAL     2
#define RCC_TIM5_PERIPHERAL     3
#define RCC_TIM6_PERIPHERAL     4
#define RCC_TIM7_PERIPHERAL     5
#define RCC_TIM12_PERIPHERAL    6
#define RCC_TIM13_PERIPHERAL    7
#define RCC_TIM14_PERIPHERAL    8
#define RCC_WWD_PERIPHERAL      11
#define RCC_SPI2_PERIPHERAL     14
#define RCC_SPI3_PERIPHERAL     15
#define RCC_USART2_PERIPHERAL   17
#define RCC_USART3_PERIPHERAL   18
#define RCC_USART4_PERIPHERAL   19
#define RCC_USART5_PERIPHERAL   20
#define RCC_I2C1_PERIPHERAL     21
#define RCC_I2C2_PERIPHERAL     22
#define RCC_USB_PERIPHERAL      23
#define RCC_CAN_PERIPHERAL      25
#define RCC_BKP_PERIPHERAL      27
#define RCC_PWR_PERIPHERAL      28
#define RCC_DAC_PERIPHERAL      29



/****************************************************************************************************************************************/

/*************************************************          Functions          **********************************************************/

/*****************************************************************************
* Function       : MRCC_voidInitSysClock()
* Description    : Initializes SYSCLK, Enabling and selecting the
				   needed SYSCLK source and selecting the value of PLL if used.
* PRE-CONDITION  : None
* POST-CONDITION : None
* @param [in]    : void
* @return        : void
* Examble        : MRCC_voidInitSysClock();
*****************************************************************************/
void MRCC_voidInitSysClock(void);

/*****************************************************************************
* Function       : MRCC_voidEnableClock()
* Description    : Enables Clock for a certain peripheral.
* PRE-CONDITION  : MRCC_voidInitSysClock() should be called.
* POST-CONDITION : None
* @param [in]    : (u8) Bus Id, (u8) Peripheral Id
* @return        : void
* Examble        : MRCC_voidEnableClock(RCC_APB2, RCC_IOPA_PERIPHERAL);
*****************************************************************************/
void MRCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);

/*****************************************************************************
* Function       : MRCC_voidDisableClock()
* Description    : Disables Clock for a certain peripheral.
* PRE-CONDITION  : None
* POST-CONDITION : None
* @param [in]    : (u8) Bus Id, (u8) Peripheral Id
* @return        : void
* Examble        : MRCC_voidDisableClock(RCC_APB2, RCC_IOPA_PERIPHERAL);
*****************************************************************************/
void MRCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);

/*****************************************************************************
* Function       : MRCC_voidResetRegisters()
* Description    : Disables clock for all peripherals & Resets all RCC registers.
* PRE-CONDITION  : None
* POST-CONDITION : None
* @param [in]    : void
* @return        : void
* Examble        : MRCC_voidResetRegisters();
*****************************************************************************/
void MRCC_voidResetRegisters(void);

/****************************************************************************************************************************************/


#endif
