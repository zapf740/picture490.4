#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "size.h"


int main(int argc, char *argv[])
{
// aus eingabe einnehmen, was für dimensionen benutzt wurden
int auflosungshohe=1080; // später von eingabefoto berechnen
int auflosungsbreite=1080;
int blockhohe=8;
int blockbreite =8;
uint16_t pixeldata;
uint8_t data[(auflosungshohe/blockhohe)*(auflosungsbreite/blockbreite)*3]={0};
uint16_t filedata[(auflosungshohe/blockhohe)*(auflosungsbreite/blockbreite)*2]={0};
data=pngtoarray();
//erstes argument eingabefoto 2.:ausgabedatei 3.: blockhohe 4.:blockbreite
int a =0;
int zahl=0;
for(int i=1;i<=(auflosungshohe/blockhohe);i++){
a=a+(auflosungsbreite*(blockhohe/2));

for(int j =0; j<(auflosungsbreite/blockbreite);j++){
pixeldata=rgbtodata(data[a+(blockbreite*j)+(blockbreite/2)],data[a+(blockbreite*j)+(blockbreite/2)+1],data[a+(blockbreite*j)+(blockbreite/2)+2]);//returns uint16 with only uint12 filled
filedata[zahl++]=rgbtobyte(pixeldata); // konvertiert 12 bits in 2 bytes an utf8 daten mit custom mapping
}
//write filedata into file in binary.
}
return 0;
}
