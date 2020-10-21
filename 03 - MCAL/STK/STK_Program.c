/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:26/8/2020***********************************/
/***********version:2***************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "STK_Interface.h"
#include "STK_Config.h"
#include "STK_Private.h"

/* Define Callback Global Variable */
static void(*MSTK_CallBack)(void);

/************************************************************************************

*Name       :   MSTK_voidInit

*Description: * Function to Set STK config
              * Disable STK Enable
              * Disable STK Interrupt 
              * Set input Clk of STK  
							
*Pre-Cond   :	None				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void MSTK_voidInit(void)
{               
  
   STK->CTRL = STK_Init ; //Disable STK , Disable STK Interrupt , Set Clock to AHB/8
	
}
/****************************************************************************************

*Name       :   MSTK_voidSetIntervalSingle

*Description: * Function to cause interrupt for once
              * Load Counter By Ticks number in micro Second 
              * Start Counter 
              * Save Call Back address to pionter 
              * Enable STK interrrupt
							
*Pre-Cond   :	* Callback function should be in main				
							* Create Void Pionter to save callback fun address
              * Copy_u32Ticks must be in micro seconds

*pos-Cond   :   None

*Input      :   Ticks number to counter in micro , address of call back function

*Output     :   void

*Return     :   void

*******************************************************************************************/

 void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
 { 
	 																	 
	STK -> LOAD = Copy_u32Ticks;           //Load counter register by input ticks
																			 
	SET_BIT(STK -> CTRL , EN);           // Start count
	
	MSTK_CallBack = Copy_ptr;            // Save call back address 
		
	SET_BIT(STK -> CTRL , INT_EN);          //Enable STK interrupt 
} 
/************************************************************************************

*Name       :   STK_voidStopInterval

*Description: * Fiction to Stop interval period
              * Disable STK Interrupt
              * Stop timer 
              * Clear LOAD,VAL Register   
							
*Pre-Cond   :	  None				
							
*pos-Cond   :   None

*Input      :   void

*Output     :   void

*Return     :   void

****************************************************************************************/
void MSTK_voidStopInterval(void)          
{
	
	CLR_BIT( STK -> CTRL , INT_EN);      // Disable STK Interrupt
	
	CLR_BIT( STK -> CTRL , EN);         // Stop timer
	
	STK -> LOAD   = 0;             // Clear loaded register
	STK -> VAL  = 0;             // Clear value register
}
/************************************************************************************

*Name       :   SysTick_Handler

*Description: * Handle STK ISR
              * Stop timer 
              * Clear LOAD,VAL Register  
              * Notify call back
							
*Pre-Cond   :	 Value register must reach to zero			
							
*pos-Cond   :  Callback notification

*Input      :   void

*Output     :   void

*Return     :   void

****************************************************************************************/

void SysTick_Handler(void)  	
{
	 	
		CLR_BIT( STK -> CTRL , INT_EN);    //Disable interrupt
	
		SET_BIT( STK -> CTRL , EN);         //Stop timer
			                       
		STK -> LOAD = 0;                  // Clear loaded register
		STK -> VAL  = 0;                // Clear value register
 		
	
		MSTK_CallBack();                 // Notify call back function
	
}
