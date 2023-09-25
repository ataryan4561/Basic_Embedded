/*
 * File:   main.c
 * Author: shubh
 *
 * Created on 18 September, 2023, 1:57 PM
 */
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ  20000000 
#define ON 0
#define OFF 1
//void LED_blink()
//{
//    //    TRISB0 = 0;
////    TRISB1 = 0;
////    TRISB2 = 0;
////    TRISB3 = 0;
////    TRISB4 = 0;
////    TRISB5 = 0;
////    TRISB6 = 0;
////    TRISB7 = 0;
////    we can also do 
//    TRISB = 0x00;
//    while(1)
//    {
////        PORTBbits.RB0=1;
////        PORTBbits.RB1=1;
////        PORTBbits.RB2=1;
////        PORTBbits.RB3=1;
////        PORTBbits.RB4=1;
////        PORTBbits.RB5=1;
////        PORTBbits.RB6=1;
////        PORTBbits.RB7=1;
//          PORTB = 0xFF;
//        __delay_ms(1000);
////        PORTBbits.RB0=0;
////        PORTBbits.RB1=0;
////        PORTBbits.RB2=0;
////        PORTBbits.RB3=0;
////        PORTBbits.RB4=0;
////        PORTBbits.RB5=0;
////        PORTBbits.RB6=0;
////        PORTBbits.RB7=0;
//          PORTB = 0x00;
//        __delay_ms(1000);
//    }
//    return;
//}
//void segment()
//{
//    unsigned char seg[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x6F};
//    TRISB = 0x00;
//    TRISC = 0X00;
//    while(1)
//    {
//        for(int i=0; i<99; i++)
//        {
//            int a = i/10;
//            int b = i%10;
//            PORTCbits.RC0 = ON,PORTCbits.RC1 = OFF;
//            PORTB = seg[a];
//            __delay_ms(100);
//            PORTCbits.RC0 = OFF,PORTCbits.RC1 = ON;
//            PORTB = seg[b];
//            __delay_ms(100);
//        }
//        
//    }
//    return;
//}
//void push_button()
//{
//    TRISB0 = 1;
//    TRISB1 = 0;
//    while(1)
//    {
//        if(PORTBbits.RB0 == 1)
//        {
//            PORTBbits.RB1 = 1;
//        }
//        else
//        {
//            PORTBbits.RB1 = 0;
//        }
//    }
//}
void LCD_data(unsigned char data)
{
    #define RS PORTDbits.RD0
    #define RW PORTDbits.RD1
    #define EN PORTDbits.RD2
    PORTC = data;
    RS = 1;
    RW = 0;
    EN = 1;
    __delay_ms(50);
    EN = 0;
}
void LCD_command(unsigned char cmd)
{
    #define RS PORTDbits.RD0
    #define RW PORTDbits.RD1
    #define EN PORTDbits.RD2
    PORTC = cmd;
    RS = 0;
    RW = 0;
    EN = 1;
    __delay_ms(50);
    EN = 0;
}
void LCD_string(unsigned char *str,unsigned char num)
{
    for(unsigned char i=0; i<num; i++)
    {
        LCD_data(str[i]);
    }
}
void LCD_initialise()
{
    LCD_command(0x38);
    LCD_command(0x06);
    LCD_command(0x0C);
    LCD_command(0x01);
}
void LCD_run()
{
    TRISC = 0x00;
    TRISD = 0x00;
    LCD_initialise();
    while(1)
    {
        LCD_string("ARYAN",5);
        LCD_command(0x81);
        LCD_command(0xC1);
        LCD_string("GUPTA",5);
        break;
    }
}
void main(void) 
{
//    LED_Blink();
//    segment();
//    push_button();
    LCD_run();
    return;
}
