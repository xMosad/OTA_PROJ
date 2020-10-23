/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V02								*/
/* 	Date: 11 August 2020						*/
/************************************************/
#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H


typedef struct{
	volatile u32 CR;		            // Clock control register.
    volatile u32 CFGR;                  // Clock configuration register.
    volatile u32 CIR;                   // Clock interrupt register.
    volatile u32 APB2RSTR;              // APB2 peripheral reset register.
    volatile u32 APB1RSTR;              // APB1 peripheral reset register.
    volatile u32 AHBENR;                // AHB peripheral clock enable register.
    volatile u32 APB2ENR;               // APB2 peripheral clock enable register.
    volatile u32 APB1ENR;               // APB1 peripheral clock enable register.
    volatile u32 BDCR;                  // Backup domain control register.
    volatile u32 CSR;                   // Control/status register.
}RCC_Type_def;

#define RCC 		((volatile RCC_Type_def*)0x40021000)

/* Registers reset value Macros */
#define RCC_CR_RESET 			0x00000083
#define RCC_CFGR_RESET 			0x00000000
#define RCC_CIR_RESET 		 	0x00000000
#define RCC_APB2RSTR_RESET 		0x00000000
#define RCC_APB1RSTR_RESET 		0x00000000
#define RCC_AHBENR_RESET 		0x00000014
#define RCC_APB2ENR_RESET 	 	0x00000000
#define RCC_APB1ENR_RESET		0x00000000
#define RCC_BDCR_RESET 			0x00000000
#define RCC_CSR_RESET 		 	0x0C000000
/********************************/

#endif
