/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 8 August 2020							*/
/************************************************/
#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

/**************************************************          Macros          ************************************************************/

/* Bus Id */
#define RCC_AHB			  0		// AHB Id.
#define RCC_APB1		  1		// APB1 Id.
#define RCC_APB2		  2		// APB2 Id.

/* Internal High-Speed clock */

#define HSITRIM_NOTRIM	  0		// Internal high-speed clock no trimming.
#define HSITRIM_POSITIVE  1		// Internal high-speed clock trimming positive steps.
#define HSITRIM_NEGATIVE  2		// Internal high-speed clock trimming negative steps.

/*****************************/

/****************************************************************************************************************************************/

/*************************************************          Functions          **********************************************************/

/****************************************************************************************************************************************/
/* RCC_voidInitSysClock --> Initializes SYSCLK, Enabling and selecting the needed SYSCLK source and selecting the value of PLL if used.	*/
/* I/P:- void (Takes the wanted values from RCC_config file).																			*/
/* O/P:- void (Initializes SYSCLK).																										*/
void RCC_voidInitSysClock(void);
/****************************************************************************************************************************************/

/********************************************************************/
/* RCC_voidEnableClock --> Enables Clock for a certain peripheral 	*/
/* I/P:-  
	Copy_u8BusId:- Id of the bus on which the peripheral is
	Copy_u8PerId:- Id of the peripheral							  	*/
/* O/P:- void(Enables Clock for a certain peripheral) 			  	*/
void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);
/********************************************************************/

/********************************************************************/
/* RCC_voidDisableClock --> Disables Clock for a certain peripheral	*/
/* I/P:-  
	Copy_u8BusId:- Id of the bus on which the peripheral is
	Copy_u8PerId:- Id of the peripheral							  	*/
/* O/P:- void(Disables Clock for a certain peripheral) 			  	*/
void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);
/********************************************************************/

/********************************************************************/
/* RCC_voidResetRegisters --> Disables clock for all peripherals & Resets all RCC registers	*/
/* I/P:- void													  							*/
/* O/P:- void 			  																	*/
void RCC_voidResetRegisters(void);
/********************************************************************************************/



u8 RCC_u8SWS(void);


/****************************************************************************************************************************************/


#endif
