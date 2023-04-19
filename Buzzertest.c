///*
// * File:   Buzzertest.c
// * Author: benny
// *
// * Created on May 11, 2021, 8:57 PM
// */
//
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
//
///*This will sound the buzzer at a frequency of 4kHz using a square wave
// The output will be toggled on and off*/
//void buzzer(void) {
//    for(int cnt = 2000; cnt > 0 ; cnt--){
//        LATBbits.LATB5 = 1;
//        __delay_ms(0.125);
//        LATBbits.LATB5 = 0;
//        __delay_ms(0.125);
//    }
//}
//
///*ALL sound patterns last for 2 seconds, each buzz/blank lasts for 500ms*/
//
///*Function will buzz,blank,buzz,blank for dry moisture level*/
//void sound_dry(void) {
//    buzzer();
//    __delay_ms(500);
//    buzzer();
//    __delay_ms(500);
//}
//
///*Function will buzz,blank,blank,blank for ok moisture level*/
//void sound_ok(void){
//    buzzer();
//    __delay_ms(1500);
//    
//}
//
///*Function will buzz,buzz,blank,blank for wet moisture level*/
//void sound_wet(void){
//    buzzer();
//    buzzer();
//    __delay_ms(1000);
//    
//}
//
///*Function will buzz continuously if a system error occurs*/
//void sound_error(void){
//    buzzer();
//    buzzer();
//    buzzer();
//    buzzer();
//    }
//
//
//
//void main(void) {
//    init();
//    __delay_ms(1000);
//    while(1){
//        printf("Dry moisture level sound pattern \n");
//        sound_dry();
//        __delay_ms(3000);
//        printf("Okay moisture level sound pattern \n");
//        sound_ok();
//        __delay_ms(3000);
//        printf("Wet moisture level sound pattern \n");
//        sound_wet();
//        __delay_ms(3000);
//        printf("System error sound pattern \n");
//        sound_error();
//        __delay_ms(3000);
//    }
//}
