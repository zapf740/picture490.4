#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "translate6.h"
#include "size.h"
#include "rgbarray.h"




int main(int argc, char *argv[])
{
//verallgemeinerung
int auflosungsbreite=1080;
int auflosungshohe=1080;
int blockbreite=8;

// argc → number of arguments
// argv → array of arguments
// argv1 ist dateiname, argv2 ist ausgabeformat
int a=(auflosungsbreite/blockbreite)*(auflosungshohe/blockbreite);
// bei 1080x1080 135x135=a

long dateiLange = size(argv[1]);

uint8_t byteDaten[dateiLange];//genau so lang wie datei

if(argc > 3){
printf("\nToo many arguments");
return -1;
}

FILE *fp = fopen(argv[1], "rb");

if(fp == NULL){
printf("\n\nfehler mit %s\n",argv[1]);
perror( argv[1] );
return 1;
}


uint6_t datenArray[dateiLange];

for(long i =0;i<dateiLange;i++){

printf("\n\n%d",fread(&byteDaten[i], 1,1, fp));

datenArray[i]=translate(byteDaten[i]);

printf("\n\n%X %X",byteDaten[i], datenArray[i]);
}

Rgbarray rgbarr[a];

int zahl = 0;

while(zahl+1<a){
rgbarr[zahl]=rgbarray6(datenArray[zahl],datenArray[zahl+1]);
zahl++;
}
if(zahl<a){
uint6_t nix=0;

rgbarr[zahl]=rgbarray6(datenArray[zahl],nix);
}

//compress()//zlib
3bytestoblocks(1080,1080,rgbarr);
//arrToPic(rgbarr,argv[2]);//stb_image_write.h oder stbi_write_func wenn man die werte im ram laden will um es einem wrapper zurückzugeben


fclose(fp);
return 0;
}

//wir lesen datei ein in binär und wandeln jeden buchstaben in 0-9 a-z um. A wird zu a. 8 bits werden zu 6