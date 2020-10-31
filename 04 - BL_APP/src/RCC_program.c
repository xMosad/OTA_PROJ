/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V02								*/
/* 	Date: 11 August 2020						*/
/************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void MRCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId){
	if (Copy_u8PerId <=31)														// Checks if Peripheral is in the valid range		
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC->AHBENR ,Copy_u8PerId);  break;			// Enables the clock of the required peripheral on AHB
			case RCC_APB1 : SET_BIT(RCC->APB1ENR ,Copy_u8PerId); break;			// Enables the clock of the required peripheral on APB1
			case RCC_APB2 : SET_BIT(RCC->APB2ENR ,Copy_u8PerId); break;			// Enables the clock of the required peripheral on APB2
		}
	}
	
	else																		
	{
			/* Return Error */
	}

}

void MRCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId){
	if (Copy_u8PerId <=31)														// Checks if Peripheral is in the valid range
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC->AHBENR ,Copy_u8PerId);  break;			// Disables the clock of the required peripheral on AHB
			case RCC_APB1 : CLR_BIT(RCC->APB1ENR ,Copy_u8PerId); break;         // Disables the clock of the required peripheral on APB1
			case RCC_APB2 : CLR_BIT(RCC->APB2ENR ,Copy_u8PerId); break;         // Disables the clock of the required peripheral on APB2
		}
	}
	
	else
	{
			/* Return Error */
	}

}

void MRCC_voidInitSysClock(void){

	// Sets Bit 0 of RCC_CR (Clock control register) to enable HSI(Internal high-speed clock).
	SET_BIT( RCC->CR,0 );

	// Wait until HSI is stable(ready).
	while( !(GET_BIT( RCC->CR , 1)) );

	// Resets RCC_CFGR (Clock configuration register) & Selects HSI as System clock.
	RCC->CFGR = RCC_CFGR_RESET;
}

void MRCC_voidResetRegisters(void){

	RCC->CR 		= RCC_CR_RESET 		;									// Resets Clock control register value
	RCC->CFGR 		= RCC_CFGR_RESET 		;									// Resets Clock configuration register value
	RCC->CIR 		= RCC_CIR_RESET 		;									// Resets Clock interrupt register value
	RCC->APB2RSTR 	= RCC_APB2RSTR_RESET 	;									// Resets APB2 peripheral reset register value
	RCC->APB1RSTR 	= RCC_APB1RSTR_RESET 	;									// Resets APB1 peripheral reset register value
	RCC->AHBENR 	= RCC_AHBENR_RESET 	;									// Resets AHB peripheral clock enable register value, disabling all AHB peripheral clocks
	RCC->APB2ENR 	= RCC_APB2ENR_RESET 	;									// Resets APB2 peripheral clock enable register value, disabling all APB2 peripheral clocks
	RCC->APB1ENR	= RCC_APB1ENR_RESET	;									// Resets APB1 peripheral clock enable register value, disabling all APB1 peripheral clocks
	RCC->BDCR 		= RCC_BDCR_RESET 		;									// Resets Backup domain control register value
	RCC->CSR 		= RCC_CSR_RESET 		;									// Resets Control/status register value

}
