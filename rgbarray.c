#include <stdint.h>
#include "translate6.h"

Rgbarray rgbarray6(uint6_t erst, uint6_t zweit){
Rgbarray rgbarray;

rgbarray.r=((erst.data&60)>>2)*16-8+16;//ERST&0x3c nimm die ersten 4bits und multipliziere mit 16... um den gewünschten 8 bit wert zu erhalten
rgbarray.g=((erst.data&3)<<2)+(zweit.data&48))*16-8+16;//0x30 = 0011 0000 also erste 2 bits von den 6 bits werden genommen und zu 00000011 umgewandelt
rgbarray.b=(zweit.data&15)*16-8+16;//15=0000 1111 letzten 4 bits
return rgbarray;
}