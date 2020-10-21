/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V02								*/
/* 	Date: 11 August 2020						*/
/************************************************/
#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H


typedef struct{
	volatile u32 CR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 APB2RSTR;
    volatile u32 APB1RSTR;
    volatile u32 AHBENR;
    volatile u32 APB2ENR;
    volatile u32 APB1ENR;
    volatile u32 BDCR;
    volatile u32 CSR;
}RCC_Type_def;

#define RCC 		((volatile RCC_Type_def*)0x40021000)

/* Private functions */

/***************************************************/
/* HSITRIM_RESET --> Resets HSITRIM value to 10000 */
/* I/P:- void                                      */
/* O/P:- void (Resets HSITRIM value)			   */
/***************************************************/
void HSITRIM_RESET(void);

/***************************************************/
/* HSITRIM_CLR --> Clears HSITRIM value to 00000   */
/* I/P:- void                                      */
/* O/P:- void (Clears HSITRIM value)			   */
/***************************************************/
void HSITRIM_CLR(void);

#endif
