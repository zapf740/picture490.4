#include <stdint.h>
#include "translate6.h"

Rgbarray rgbarray6(uint6_t erst, uint6_t zweit){
Rgbarray rgbarray;

rgbarray.r=((erst.data&60)>>2)*16-8+16;//ERST&0x3c nimm die ersten 4bits und multipliziere mit 16... um den gewünschten 8 bit wert zu erhalten
rgbarray.g=((erst.data&3)<<2)+(zweit.data&48))*16-8+16;//0x30 = 0011 0000 also erste 2 bits von den 6 bits werden genommen und zu 00000011 umgewandelt
rgbarray.b=(zweit.data&15)*16-8+16;//15=0000 1111 letzten 4 bits
return rgbarray;
}

int[] 3bytestoblocks(int blockbreite,int blockhohe, Rgbarray* array, int arraybreite,int arrayhohe){//arrayhohe bedeutet wie viele blöcke das übergebene array
                                                                                                    //im bild einnimmt und arraybreite bedeutet wie viele blöcke in einer höhe im bild sind

uint8_t neuarray[blockbreite*blockhohe*arraybreite*arrayhohe];// 135*135*64=1080x1080
int zahl=0;
for(int a=0;a<arrayhohe;a++){//für jede blockzeile
for(int b=0;b<blockhohe;b++){//soll so oft die zeile wiederholt geschrieben werden
for(int c=0;c<arraybreite;c++){//so viele blöcke sollen geschrieben werden (blöcke pro zeile)
for(int d=0;d<blockbreite;d++){//wie viele pixel breit das block ist
neuarray[zahl++]=array[c+(a*arraybreite)].r;
neuarray[zahl++]=array[c+(a*arraybreite)].g;
neuarray[zahl++]=array[c+(a*arraybreite)].b;
}
}
}
}
}
}