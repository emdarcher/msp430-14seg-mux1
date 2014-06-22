

//includes 
#include <msp430.h>
#include <stdint.h>
#include "iee3785_mux.h"


//must edit this from wiring
/*
void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)
{
        uint8_t i;

        for (i = 0; i < 8; i++)  {
                if (bitOrder == LSBFIRST)
                        digitalWrite(dataPin, !!(val & (1 << i)));
                else    
                        digitalWrite(dataPin, !!(val & (1 << (7 - i))));
                        
                digitalWrite(clockPin, HIGH);
                digitalWrite(clockPin, LOW);            
        }
}
*/
