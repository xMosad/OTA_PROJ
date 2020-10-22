/*****************************************************/
 /* Author      : Abdelrhman Mosad                   */
 /* Version     : v01 (Bl)                           */
 /* date        : 21/10/2020                         */
/*****************************************************/
/* Library includes */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/* Driver's includes */
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinMode (u8 copyPortId , u8 copyPinNumber , u8 copyMode  ) 
{
	switch (copyPortId)
	{
		case PORTA : 
			if (copyPinNumber <= 7)
			{
				/* Clear the four bits first */
				GPIOA_CRL &= ~ (CLEAR_VALUE << copyPinNumber * 4 ) ; 
				/* Update with mode value */
				GPIOA_CRL |=   (copyMode    << copyPinNumber * 4 ) ;  
			}
			else if (copyPinNumber <= 15)
			{
				/* To get the right offest */
				copyPinNumber = copyPinNumber - 8 ;
				/* Clear the four bits first */
				GPIOA_CRH &= ~ (CLEAR_VALUE << copyPinNumber * 4 ) ; 
				/* Update with mode value */
				GPIOA_CRH |=   (copyMode    << copyPinNumber * 4 ) ; 
			}
			else
			{
				/* Error code */
			}
			break;
			
		case PORTB : 
			if (copyPinNumber <= 7)
			{
				GPIOB_CRL &= ~ (CLEAR_VALUE << copyPinNumber * 4 ) ; 
				GPIOB_CRL |=   (copyMode    << copyPinNumber * 4 ) ; 
			}
			else if (copyPinNumber <= 15)
			{
				copyPinNumber = copyPinNumber - 8 ;
				GPIOB_CRH &= ~ (CLEAR_VALUE << copyPinNumber * 4 ) ;
				GPIOB_CRH |=   (copyMode    << copyPinNumber * 4 ) ; 
			}
			else 
			{
				/* Error code */
			}
			break;
			
		case PORTC : 
			if (copyPinNumber <= 7)
			{
				GPIOC_CRL &= ~ (CLEAR_VALUE << copyPinNumber * 4 ) ; 
				GPIOC_CRL |=   (copyMode    << copyPinNumber * 4 ) ; 
			}
			else if (copyPinNumber <= 15)
			{
				copyPinNumber = copyPinNumber - 8 ;
				GPIOC_CRH &= ~ (CLEAR_VALUE << copyPinNumber * 4 ) ; 
				GPIOC_CRH |=   (copyMode    << copyPinNumber * 4 ) ; 
			}
			else
			{
				/* Error code */
			}
			break;
			
		default    : /* Error code */  break ;
		
	}
}

void GPIO_voidSetPinValue (u8 copyPortId , u8 copyPinNumber , u8 copy_u8Value){
	switch (copyPortId)
	{
		case PORTA :
			if      (copy_u8Value == GPIO_HIGH)
			{
				/* Set pin value to 1 */
				GPIOA_BSRR = (1 << copyPinNumber);
			}
			else if (copy_u8Value == GPIO_LOW )
			{
				/* Set pin value to 0 */
				GPIOA_BRR =  (1 << copyPinNumber);
			}
			else 
			{
				/* Error code */
			}
			break ;
			
		case PORTB :
			if      (copy_u8Value == GPIO_HIGH)
			{
				GPIOB_BSRR = (1 << copyPinNumber);
			}
			else if (copy_u8Value == GPIO_LOW )
			{
				GPIOB_BRR  = (1 << copyPinNumber);
			}
			else
			{
				/* Error code */
			}
			break ;
			
		case PORTC : 
			if      (copy_u8Value == GPIO_HIGH)
			{
				GPIOC_BSRR = (1 << copyPinNumber);
			}
			else if (copy_u8Value == GPIO_LOW )
			{
				GPIOC_BRR  = (1 << copyPinNumber);
			}
			else 
			{
				/* Error code */
			}
			break ;
			
		default    : /* Error code */ break ;
	}
}


u8 GPIO_u8GetPinValue (u8 copyPortId , u8 copyPinNumber)
{
	/* Local variable To store the value of the bit */
	u8 Local_u8bitValue = 0 ;
	switch (copyPortId) 
	{
		case PORTA :
			/* Get the value of the pin */
			Local_u8bitValue = GET_BIT (GPIOA_IDR , copyPinNumber );
			break ;
			
		case PORTB :
			Local_u8bitValue = GET_BIT (GPIOB_IDR , copyPinNumber );
			break ;
			
		case PORTC : 
			Local_u8bitValue = GET_BIT (GPIOC_IDR , copyPinNumber );
			break ;
			
		default    : /* Error code */ break ;
	}
	
	return Local_u8bitValue ;
}







