#include <stdint.h>

#include "translate6.h"
#include <stdio.h>

uint6_t translate(uint8_t file){
//turning the most used characters into 6 bits from utf 8 and giving up on 192 characters
uint6_t final;

if(file>=0x21 && file<=0x5f){
final.data=(file-33);
//printf("\nprint1: %X\n",final.data);
return final;
}
final.data=63;
//printf("\nprint3: %X\n",final.data);
return final;
}