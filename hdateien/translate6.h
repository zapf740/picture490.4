#ifndef TRANSLATE6_H
#define TRANSLATE6_H
#include <stdint.h>


typedef struct{

uint8_t data:6;
}uint6_t;
uint6_t translate(uint8_t file);

#endif