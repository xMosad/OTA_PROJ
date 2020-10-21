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

void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId){
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

void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId){
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

void RCC_voidInitSysClock(void){

	SET_BIT( RCC->CR,0 );											// Sets Bit 0 of RCC_CR (Clock control register) to enable HSI(Internal high-speed clock).
	while( !(GET_BIT( RCC->CR , 1)) );
	RCC->CFGR = 0x00000000;											// Resets RCC_CFGR (Clock configuration register).

	#if (HSITRIM_SIGN == HSITRIM_NOTRIM)
		HSITRIM_RESET();											// Resets the value of Bits 3 : 7 of RCC_CR to 10000 reset HSI trimming to no trimming state.
	#elif (HSITRIM_SIGN == HSITRIM_POSITIVE)
		HSITRIM_CLR();												// Clears the value of Bits 3 : 7 of RCC_CR to 00000.
		if (HSITRIM_STEPS > 0 && HSITRIM_STEPS < 16){				// Checks if number of steps of trimming is in the valid range.
			RCC_CR |= ((10000 + HSITRIM_STEPS) << 3);				// Sets the value of Bits 3 : 7 of RCC_CR to gain the wanted Trimming.
		}
		else{
			// Return Error 
		}
	#elif (HSITRIM_SIGN == HSITRIM_NEGATIVE)
		HSITRIM_CLR();												// Clears the value of Bits 3 : 7 of RCC_CR to 00000.
		if (HSITRIM_STEPS > 0 && HSITRIM_STEPS <= 16){				// Checks if number of steps of trimming is in the valid range.
			RCC_CR |= ((10000 - HSITRIM_STEPS) << 3);				// Sets the value of Bits 3 : 7 of RCC_CR to gain the wanted Trimming.
		}
		else{
			// Return Error 
		}
	#endif

}

void RCC_voidResetRegisters(void){

	RCC->CR 		= 0x00000083;									// Resets Clock control register value
	RCC->CFGR 		= 0x00000000;									// Resets Clock configuration register value
	RCC->CIR 		= 0x00000000;									// Resets Clock interrupt register value
	RCC->APB2RSTR 	= 0x00000000;									// Resets APB2 peripheral reset register value
	RCC->APB1RSTR 	= 0x00000000;									// Resets APB1 peripheral reset register value
	RCC->AHBENR 	= 0x00000014;									// Resets AHB peripheral clock enable register value, disabling all AHB peripheral clocks
	RCC->APB2ENR 	= 0x00000000;									// Resets APB2 peripheral clock enable register value, disabling all APB2 peripheral clocks
	RCC->APB1ENR	= 0x00000000;									// Resets APB1 peripheral clock enable register value, disabling all APB1 peripheral clocks
	RCC->BDCR 		= 0x00000000;									// Resets Backup domain control register value
	RCC->CSR 		= 0x0C000000;									// Resets Control/status register value
	//RCC->APB2RSTR 	= 0x0038FFFF;									// Resets APB2 peripherals
	//RCC->APB1RSTR 	= 0x3AFEC9FF;									// Resets APB1 peripherals

}

u8 RCC_u8SWS(void){
	u8 Loc_u8SWS_Val = (RCC->CFGR>>2) & ~(3);
	return Loc_u8SWS_Val;
}

void HSITRIM_RESET(void){														// Resets value of Bits 3 : 7 of RCC_CR to 10000
	SET_BIT(RCC->CR,7);
	CLR_BIT(RCC->CR,6);
	CLR_BIT(RCC->CR,5);
	CLR_BIT(RCC->CR,4);
	CLR_BIT(RCC->CR,3);
}
void HSITRIM_CLR(void){															// Clears value of Bits 3 : 7 of RCC_CR to 00000
	CLR_BIT(RCC->CR,7);
	CLR_BIT(RCC->CR,6);
	CLR_BIT(RCC->CR,5);
	CLR_BIT(RCC->CR,4);
	CLR_BIT(RCC->CR,3);
}
