//header file for iee3685 library

/*

letters that correspond to segments
 ---A---
|\  |  /|
F H I J B
|_Ga|Gb_|
|  /|\  |
E M L K C
|/  |  \|  _
 ---D---  |_|-dp

*/
/*
pinout
# on package

IEE3785R
8504   3
           ____________
Gb_A/Ga_B -1         18-   J_A/H_B
empty     -2 ------- 17-   L_A/I_B
K_A/M_B   -3 digit 1 16-   empty
C_A/E_B   -4 ------- 15-   GND1_B
GND1_A    -5 o       14-   B_A/F_B
dp1_A     -6 ------- 13-   empty
empty     -7 digit 0 12-   D_A/A_B
GND0_B    -8 ------- 11-   empty
dp0_A     -9 o       10-   GND0_A
           ------------
*/

#ifndef iee3785_mux

#define iee3785_mux

//includes
#include <msp430.h>
#include <stdint.h>

//shift register daisy chain CS/SS pin
#define SR_DC_SS BIT4
//other SPI pins
#define MOSI BIT6
#define SCLK BIT5

//segment shift register
#define SEG_SR_SS SR_DC_SS

//pin values
#define QA  BIT0
#define QB  BIT1
#define QC  BIT2
#define QD  BIT3
#define QE  BIT4
#define QF  BIT5
#define QG  BIT6
#define QH  BIT7
//corresponding segment connections
//A connections
#define B_A QA
#define C_A QB
#define D_A QC
#define L_A QD
#define J_A QE
#define Gb_A QF
#define K_A QG
#define dp_A QH

//B connections
#define E_B C_A
#define F_B B_A
#define A_B D_A
#define I_B L_A
#define M_B K_A
#define Ga_B Gb_A
#define H_B J_A
//dp is shared

//1st GND shift reg (TPIC6B595)
#define DIGIT03_SR_SS SR_DC_SS

//for digits 0-3 GNDS
#define GND0_A  BIT0
#define GND0_B  BIT1
#define GND1_A  BIT2
#define GND1_B  BIT3
#define GND2_A  BIT4
#define GND2_B  BIT5
#define GND3_A  BIT6
#define GND3_B  BIT7


//global variables
const uint8_t   a_gnd_bits[] =  {GND0_A,GND1_A,GND2_A,GND3_A};
const uint8_t   b_gnd_bits[] =  {GND0_B,GND1_B,GND2_B,GND3_B};
const uint8_t   num_digits  =   sizeof(a_gnd_bits);

//splitting word into bytes link:
// https://answers.yahoo.com/question/index?qid=20100414100402AATfyLJ
const uint16_t  char_segs[] =   {
//            p b    
//  A:        dKGJLDCB
//  B:^HGMIAFE
//      a             
    0b0000000000000000; //space
    0b0000000010000011; //'!'
    0b0000101000000000; //'"'
    0b1111111101111111; //'#'
    0b0010111000101110; //'$'
    0b0111001001110010; //'%'
    0b0101010001010100; //'&'
    0b0000000000010000; //'''
    0b0000000001010000; //'('
    0b0101000000000000; //')'
    0b0111100001111000; //'*'
    0b0010100000101000; //'+'
    0b0001000000000000; //','
    0b0010000000100000; //'-'
    0b0000000010000000; //'.'
    0b0001000000010000; //'/'
    0b0001011100010111; //'0'
    0b0000000000010011; //'1'
    0b0001010000100101; //'2'
    0b0000010000100111; //'3'
    0b0010001000100011; //'4'
    0b0010011001000111; //'5'
    0b0010011100100110; //'6'
    0b0001010000010000; //'7'
    0b0010011100100111; //'8'
    0b0100010000100111; //'9'
    0b0000100000001000; //':'
    0b0001100000000000; //';'
    0b0001000000010100; //'<'
    0b0010000000100100; //'='
    0b0100000001000100; //'>'
    0b0000010000101001; //'?'
}

#endif
