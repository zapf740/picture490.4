#include <stdint.h>

#include "translate6.h"
#include <stdio.h>

uint6_t translate(uint8_t file){

uint6_t final;

if(file>=48 && file<=57){
final.data=(file-48);
printf("\nprint1: %X\n",final.data);
return final;
}
if(file>=97&&file<=122){
final.data=(file-87);
printf("\nprint2: %X\n",final.data);
return final;
}
final.data=63;
printf("\nprint3: %X\n",final.data);
return final;
}