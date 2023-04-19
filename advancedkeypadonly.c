/////*
//// * File:   keypadonly.c
//// * Author: Benny
//// *
//// * Created on May 11, 2021, 11:56 PM
//// */
////
////
////#include "CONFIG.h"
////#include <stdio.h>
////#include <stdint.h>
////#include <stdbool.h>
////#include <stdlib.h>
////#include <string.h>
////
////#define _XTAL_FREQ 2000000       // 2MHz oscillator 
////void init(void){
/////*Configuring the EUSART transmitter in asynchronous mode*/
////    TX1STAbits.TXEN = 1;         //page 546
////    TX1STAbits.SYNC = 0;
////    RC1STAbits.SPEN = 1;
/////*Configuring for a Baud Rate of 9600*/
////    BAUD1CONbits.BRG16 = 0;      //page 565, 8 bit asynchronous mode
////    TX1STAbits.BRGH = 1;
////    SP1BRGL = 12;
////    SP1BRGH = 0;
//// /*Configuring the EUSART receiver in asynchronous mode*/
////    RC1STAbits.CREN = 1;        // page 548 
////    TX1STAbits.SYNC = 0;
////    RC1STAbits.SPEN = 1;
//// /*Configuring pin RA0 to be an analog input*/
////    TRISAbits.TRISA0 = 1;       // configured as input
////    ANSELAbits.ANSA0 = 1;       //analog I/O pin
//// /*Configuring the ADC Module*/     
////    ADCON0bits.ADON = 1;        // turns on module
////    ADCON0bits.ADFRM0 = 1;      // right justification 
////    ADREFbits.ADPREF = 0;       // Vref+ of ADC is connected to Vdd
////    ADREFbits.ADNREF = 0;       // Vref- of ADC is connected to Vss
////    ADCON1 = 0b11100000;        // could try 0b01100000 if not working
////    ADPCH =  0b00000000;        // Selects ANA0 as channel
////  /*Configuring the rest of pins*/
////    TRISB = 0x0F;               // configures pins RB0-RB03 as inputs (keypad)
////    TRISD = 0x00;                            // and RD4 - RD7 as outputs
////    ANSELD = 0x00;              // sets RD4-RD7 to digital I/O pins
////    ANSELB = 0x00;              // sets RB0-RB3 to digital I/O pins 
////    WPUB = 0x0F;                // enables pull-ups for RB0-RB3
////    TRISBbits.TRISB5 = 0;       // configures pin RB5 as output (buzzer)
////    ANSELBbits.ANSB5 = 0;       // sets RB5 as digital I/O pin
////    TRISCbits.TRISC0 = 0;       // configures pin RB5 as output (fan)
////    ANSELCbits.ANSC0 = 0;       // sets RB5 as digital I/O pin
////    LATCbits.LATC0 = 0;         // ensures fan is off at initialization
////    TRISCbits.TRISC6 = 0;       // Sets pic transmitter pin as output
////    ANSELCbits.ANSC6 = 0;       // ensures transmitter pin is digital i/o
////    RC6PPS = 0x10;              // configures RC6 as serial transmitter
////}
////
/////*When printf is used, it will also be transmitted to the EUSART*/
////void putch(unsigned char data)
////{
////    while(TX1STAbits.TRMT == 0);
////    TXREG = data;
////}
////
////
/////*Updates input string to the number the user input(until enter is pressed)*/
////int keypad_press (void) {
////    
////    int num;
////    // checking for row1
////    LATD4 = 0; LATD5 = 1; LATD6 = 1; LATD7 = 1;
////    // column1
////    if (RB0 == 0) {
////        __delay_ms(100);
////        while(RB0 == 0){
////            num = 1;
////            return num;
////        }
////    }
////    //column2
////    if (RB1 == 0) {
////        __delay_ms(100);
////        while(RB1 == 0){
////            num = 2;
////            return num;
////        }
////    }
////    //column3
////    if (RB2 == 0) {
////        __delay_ms(100);
////        while(RB2 == 0){
////        num = 3;
////        return num  ;
////        }
////    }
////    
////    /*Checking for Row2*/
////    LATD4 = 1; LATD5 = 0; LATD6 = 1; LATD7 = 1;
////    //column1
////    if (RB0 == 0) {
////        __delay_ms(100);
////        if(RB0 == 0){
////            num = 4;
////            return num;    
////        }
////    }
////    //column 2
////    if (RB1 == 0) {
////        __delay_ms(100);
////        while(RB1 == 0){
////            num = 5;
////        return num;
////        }
////    }
////    //column 3
////    if (RB2 == 0) {
////        __delay_ms(100);
////        while(RB2 == 0){
////            num = 6;
////        return num;        
////        }
////    }
////    
////    /*Checking for Row3*/
////    LATD4 = 1; LATD5 = 1; LATD6 = 0; LATD7 = 1;
////    //column1
////    if (RB0 == 0) {
////        __delay_ms(100);
////        while(RB0 == 0){
////            num = 7;
////        return num;      
////    }
////    }
////    //column2
////    if (RB1 == 0) {
////        __delay_ms(100);
////        while(RB1 == 0){
////            num = 8;
////        return num; 
////        }
////    }
////    //column3
////    if (RB2 == 0) {
////        __delay_ms(100);
////        while(RB2 == 0){
////            num = 9;
////        return num;   
////        }
////    }    
////    
////    /*Checking for Row4*/
////    LATD4 = 1; LATD5 = 1; LATD6 = 1; LATD7 = 0;
////    //column1
////    if (RB0 == 0) {
////        __delay_ms(100);
////        while(RB0 == 0){
////            num = 10;
////        return num;
////        }
////    }
////    //column2
////    if (RB1 == 0) {
////        __delay_ms(100);
////        while(RB1 == 0){
////            num = 0;
////        return num;       
////        }
////    }
////    //column4
////    if (RB3 == 0) {
////        __delay_ms(100);
////        while(RB3 == 0){
////        num = 11;
////        return num;
////        }   
////    }
////    return 12;
////}
////    
////int get_input(void)                       
////{
////            int number = 0;
////            int key = 12;              // char key is used to tell if key is pressed
////            int enter = 0;
////            /*While enter is not pressed*/
////            while(enter == 0) {
////                printf("Getting input... \n");
////            while(key==12){              // Wait until a key is pressed
////            key = keypad_press();   // Scan the keys again and again
////            if (key == 10){ // If "clear" was pressed
////                number = 0; // clears the input number
////                key = 12;
////            }
////            else if (key == 11){
////                enter = 1;
////            }
////            else{
////                number = key;
////                number = (number*10) + number;
////                key = 12;
////            }
////            }
////        }
////            return number;                  //when key pressed then return its value
////}
////
////void main(void) {
////    init();
////    __delay_ms(1000);
////    printf("Please enter number on keypad and press enter\n");
////    int temp = 0;
////    temp = get_input();             // get first input from keypad
////    printf("First number entered is %d \n",temp);
////    int lower_lim;      
////    
////    temp = 0;
////    printf("Please enter second number on keypad and press enter\n");
////    temp = get_input();             // get second input from keypad
////    printf("Second number entered is %d \n",temp); 
////    int upper_lim;                  
////    
////    temp = 0;
////}
//
//
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
//    int prev_state[12];
//    for (int i = 0; i < 12 ; i++){
//        prev_state[i] = 1;
//    }
//    while(1){
//    
//    // checking for row1
//    RD4 = 0; RD5 = 1; RD6 = 1; RD7 = 1;
//    // column1
//    if(RB0 != prev_state[0] ){
//        
//    if (RB0 == 0) {
//        __delay_ms(100);
//        if(RB0 == 0){
//        strncat(input,"1",1);
//        }
//    }
//    prev_state[0] = RB0;
//    }
//    
//    //column2
//    if(RB1 != prev_state[1]){
//    if (RB1 == 0) {
//        __delay_ms(100);
//        if(RB1 == 0){
//        strncat(input,"2",1);
//        }
//    }
//    prev_state[1] = RB1;
//    }
//    //column3
//    if(RB2 != prev_state[2]){
//    if (RB2 == 0) {
//        __delay_ms(100);
//        if(RB2 == 0){
//        strncat(input,"3",1);       
//        }
//    }
//    prev_state[2] = RB2;
//    }
//    __delay_ms(1);
//    /*Checking for Row2*/
//    RD4 = 1; RD5 = 0; RD6 = 1; RD7 = 1;
//    //column1
//    if (RB0 != prev_state[3]){
//    if (RB0 == 0) {
//        __delay_ms(100);
//        if(RB0 == 0){
//        strncat(input,"4",1);        
//        }
//    }
//    prev_state[3] = RB0;
//    }
//    //column 2
//    if ( RB1 != prev_state[4] ){
//    if (RB1 == 0) {
//        __delay_ms(100);
//        if(RB1 == 0){
//        strncat(input,"5",1);       
//        }
//    }
//    prev_state[4] = RB1;
//    }
//    //column 3
//    if (RB2 != prev_state[5]){
//    if (RB2 == 0) {
//        __delay_ms(100);
//        if(RB2 == 0){
//        strncat(input,"6",1);        
//        }
//    }
//    prev_state[5] = RB2;
//    }
//    __delay_ms(1);
//    /*Checking for Row3*/
//    RD4 = 1; RD5 = 1; RD6 = 0; RD7 = 1;
//    //column1
//    if(RB0 != prev_state[6]){
//    if (RB0 == 0) {
//        __delay_ms(100);
//        if(RB0 == 0){
//        strncat(input,"7",1);       
//    }
//    }
//    prev_state[6] = RB0;
//    }
//    //column2
//    if(RB1 != prev_state[7]){
//    if (RB1 == 0) {
//        __delay_ms(100);
//        if(RB1 == 0){
//        strncat(input,"8",1);        
//        }
//    }
//    prev_state[7] = RB1;
//    }
//    //column3
//    if(RB2 != prev_state[8]){
//    if (RB2 == 0) {
//        __delay_ms(100);
//        if(RB2 == 0){
//        strncat(input,"9",1);       
//        }
//    }
//    prev_state[8] = RB2;
//    }    
//    __delay_ms(1);
//    /*Checking for Row4*/
//    RD4 = 1; RD5 = 1; RD6 = 1; RD7 = 0;
//    //column1
//    if (RB0 != prev_state[9]){
//    if (RB0 == 0) {
//        __delay_ms(100);
//        if(RB0 == 0){
//        memset(input,0,strlen(input)); // clears the string         
//        }
//    }
//    prev_state[9] = RB0;
//    }
//    //column2
//    if(RB1 != prev_state[10]){
//    if (RB1 == 0) {
//        __delay_ms(100);
//        if(RB1 == 0){
//        strncat(input,"0",1);        
//        }
//    }
//    prev_state[10] = RB1;
//    }
//    //column4
//    if(RB3 != prev_state[11]){
//        
//    if (RB3 == 0) {
//        __delay_ms(100);
//        if(RB3 == 0){
//        break;     
//        }  
//    }
//    }
//    __delay_ms(1);
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