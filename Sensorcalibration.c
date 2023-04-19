///*
// * File:   Sensorcalibration.c
// * Author: benny
// *
// * Created on May 11, 2021, 9:04 PM
// */
//
//
//#include "CONFIG.h"
//#include <stdio.h>
//#include <stdint.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define _XTAL_FREQ 2000000       // 2MHz oscillator 
//void init(void){
///*Configuring the EUSART transmitter in asynchronous mode*/
//    TX1STAbits.TXEN = 1;         //page 546
//    TX1STAbits.SYNC = 0;
//    RC1STAbits.SPEN = 1;
///*Configuring for a Baud Rate of 9600*/
//    BAUD1CONbits.BRG16 = 0;      //page 565, 8 bit asynchronous mode
//    TX1STAbits.BRGH = 1;
//    SP1BRGL = 12;
//    SP1BRGH = 0;
// /*Configuring the EUSART receiver in asynchronous mode*/
//    RC1STAbits.CREN = 1;        // page 548 
//    TX1STAbits.SYNC = 0;
//    RC1STAbits.SPEN = 1;
// /*Configuring pin RA0 to be an analog input*/
//    TRISAbits.TRISA0 = 1;       // configured as input
//    ANSELAbits.ANSA0 = 1;       //analog I/O pin
// /*Configuring the ADC Module*/     
//    ADCON0bits.ADON = 1;        // turns on module
//    ADCON0bits.ADFRM0 = 1;      // right justification 
//    ADREFbits.ADPREF = 0;       // Vref+ of ADC is connected to Vdd
//    ADREFbits.ADNREF = 0;       // Vref- of ADC is connected to Vss
//    ADCON1 = 0b11100000;        // could try 0b01100000 if not working
//    ADPCH =  0b00000000;        // Selects ANA0 as channel
//  /*Configuring the rest of pins*/
//    TRISB = 0x0F;               // configures pins RB0-RB03 as inputs (keypad)
//    TRISD = 0x00;                            // and RD4 - RD7 as outputs
//    ANSELD = 0x00;              // sets RD4-RD7 to digital I/O pins
//    ANSELB = 0x00;              // sets RB0-RB3 to digital I/O pins 
//    WPUB = 0x0F;                // enables pull-ups for RB0-RB3
//    TRISBbits.TRISB5 = 0;       // configures pin RB5 as output (buzzer)
//    ANSELBbits.ANSB5 = 0;       // sets RB5 as digital I/O pin
//    TRISCbits.TRISC0 = 0;       // configures pin RB5 as output (fan)
//    ANSELCbits.ANSC0 = 0;       // sets RB5 as digital I/O pin
//    LATCbits.LATC0 = 0;         // ensures fan is off at initialization
//    TRISCbits.TRISC6 = 0;       // Sets pic transmitter pin as output
//    ANSELCbits.ANSC6 = 0;       // ensures transmitter pin is digital i/o
//    RC6PPS = 0x10;              // configures RC6 as serial transmitter
//}
//
///*When printf is used, it will also be transmitted to the EUSART*/
//void putch(unsigned char data)
//{
//    while(TX1STAbits.TRMT == 0);
//    TXREG = data;
//}
//void main(void) {
//    init();
//    __delay_ms(1000);
//    printf("Initialized! \n");
//    int adc_result;
//    /*Start an ADC conversion*/
//    while(1){
//        ADCON0bits.ADGO = 1;
//        __delay_us(50);
//        
//        adc_result = (ADRESH<<8) + ADRESL;
//        printf("ADC value of soil sample : %d \n",adc_result);
//        __delay_ms(2000);
//        
//    }
//}
