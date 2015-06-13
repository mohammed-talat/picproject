/* 
 * File:   main.c
 * Author: mohammed
 *
 * Created on June 5, 2015, 2:23 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
// BEGIN CONFIG
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = ON // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
//END CONFIG
#define _XTAL_FREQ 8000000
/*
 *  interrupt example
 */
Timer1_init()                      /*timer interrupt frequency
                                   * f=__XTAL_FREQ /(4 * prescaler *2^(16) )*/
{

                                  //timer 1 prescaller 1/8
    T1CONbits.T1CKPS1=1;
    T1CONbits.T1CKPS0=1;
    //timer 1 interrups enable
    PIE1bits.TMR1IE=1;
    //timer 1 on
    T1CONbits.TMR1ON=1;

}


int main(int argc, char** argv)
{
Timer1_init();   
//unsigned char a=0;
//a++;

// what on the earth am i doing
    //setup io pins
 TRISBbits.TRISB7=0;
 PORTBbits.RB7=1;
 TRISB6=0;
 RB6=1;
 INTCONbits.GIE=1;
 INTCONbits.PEIE=1;
 

    return (EXIT_SUCCESS);
}

void interrupt ISR(void)
{
    if(PIR1bits.TMR1IF==1)
{
        PORTBbits.RB7 ^=1;
        PIR1bits.TMR1IF=0;
    }

}

