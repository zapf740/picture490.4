#ifndef RGBARRAY_H
#define RGBARRAY_H
#include <stdint.h>
#include "translate6.h"

typedef struct{
uint8_t r;
uint8_t g;
uint8_t b;
} Rgbarray;


Rgbarray rgbarray6(uint6_t erst, uint6_t zweit);

#endif