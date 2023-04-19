///*
// * File:   keypadonly.c
// * Author: Benny
// *
// * Created on May 11, 2021, 11:56 PM
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
///*Updates input string to the number the user input(until enter is pressed)*/
//void keypad_input (char *input) {
//    printf("Getting input... \n");
//   
//    while(1){
//    // LAT = R 
//    // checking for row1
//    RD4 = 0; RD5 = 1; RD6 = 1; RD7 = 1;
//    // column1
//    if (RB0 == 0) {
//        __delay_ms(100);
//        if(RB0 == 0){
//        strncat(input,"1",1);
//        }
//    }
//    //column2
//    if (RB1 == 0) {
//        __delay_ms(100);
//        if(RB1 == 0){
//        strncat(input,"2",1);
//        }
//    }
//    //column3
//    if (RB2 == 0) {
//        __delay_ms(100);
//        if(RB2 == 0){
//        strncat(input,"3",1);       
//        }
//    }
//    __delay_ms(25);
//    /*Checking for Row2*/
//    RD4 = 1; RD5 = 0; RD6 = 1; RD7 = 1;
//    //column1
//    if (RB0 == 0) {
//        __delay_ms(100);
//        if(RB0 == 0){
//        strncat(input,"4",1);        
//        }
//    }
//    //column 2
//    if (RB1 == 0) {
//        __delay_ms(100);
//        if(RB1 == 0){
//        strncat(input,"5",1);       
//        }
//    }
//    //column 3
//    if (RB2 == 0) {
//        __delay_ms(100);
//        if(RB2 == 0){
//        strncat(input,"6",1);        
//        }
//    }
//    __delay_ms(25);
//    /*Checking for Row3*/
//    RD4 = 1; RD5 = 1; RD6 = 0; RD7 = 1;
//    //column1
//    if (RB0 == 0) {
//        __delay_ms(100);
//        if(RB0 == 0){
//        strncat(input,"7",1);       
//    }
//    }
//    //column2
//    if (RB1 == 0) {
//        __delay_ms(100);
//        if(RB1 == 0){
//        strncat(input,"8",1);        
//        }
//    }
//    //column3
//    if (RB2 == 0) {
//        __delay_ms(100);
//        if(RB2 == 0){
//        strncat(input,"9",1);       
//        }
//    }    
//    __delay_ms(25);
//    /*Checking for Row4*/
//    RD4 = 1; RD5 = 1; RD6 = 1; RD7 = 0;
//    //column1
//    if (RB0 == 0) {
//        __delay_ms(100);
//        if(RB0 == 0){
//        memset(input,0,strlen(input)); // clears the string         
//        }
//    }
//    //column2
//    if (RB1 == 0) {
//        __delay_ms(100);
//        if(RB1 == 0){
//        strncat(input,"0",1);        
//        }
//    }
//    //column4
//    if (RB3 == 0) {
//        __delay_ms(100);
//        if(RB3 == 0){
//        break;     
//        }   
//    }
//    __delay_ms(25);
//}
//    return;
//}
//
//void main(void) {
//    init();
//    __delay_ms(1000);
//    printf("Please enter number on keypad and press enter\n");
//    char temp[5] = "";              // holds 4 elements in string
//    keypad_input(temp);             // get first input from keypad
//    printf("First number entered is %s \n",temp);
//    int lower_lim;      
//    lower_lim = atoi(temp);         // store input as lower limit
//    memset(temp,'\0',sizeof(temp)); // clear string
//    printf("Please enter second number on keypad and press enter\n");
//    keypad_input(temp);             // get second input from keypad
//    printf("Second number entered is %s \n",temp); 
//    int upper_lim;                  
//    upper_lim = atoi(temp);         //store input as upper limit
//    temp[0] = '\0';                 // clear string
//}