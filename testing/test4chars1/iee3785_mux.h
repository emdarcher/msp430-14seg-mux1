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

#endif
