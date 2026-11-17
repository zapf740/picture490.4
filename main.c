#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "translate6.h"
#include "size.h"
#include "rgbarray.h"
#include "stb_image_write.h"
#pragma comment(linker, "/STACK:16777216")
//man muss später checks für dateiinputlänge etc hinzufügen
int main(int argc, char *argv[])
{
//verallgemeinerung später
int auflosungsbreite=1080;
int auflosungshohe=1080;
int blockbreite=1;
int blockhohe=1;
// argc → number of arguments
// argv → array of arguments
// argv1 ist dateiname, argv2 ist ausgabeformat

if(argc!=3){
printf("\nZu wenige argumente!\n");
return 0;
}

int a=(auflosungsbreite/blockbreite)*(auflosungshohe/blockhohe);// bei 1080x1080 un 8x8 = 135x135=a
uint8_t finalRgbArray[auflosungsbreite*auflosungshohe*3];
int64_t dateiLange = size(argv[1]);
int retur=0;
uint8_t byteDaten[dateiLange];//genau so lang wie datei
uint6_t datenArray[dateiLange];
Rgbarray rgbarr[a];
int zahl = 0;
uint6_t null={.data=0};


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




for(long i =0;i<dateiLange;i++){

//printf("\n\n%d",fread(&byteDaten[i], 1,1, fp));
fread(&byteDaten[i], 1,1, fp);
datenArray[i]=translate(byteDaten[i]);

//printf("\n\n%X %X",byteDaten[i], datenArray[i]);
}



while(2*zahl+1<a*2&& 2*zahl+1<dateiLange){
rgbarr[zahl]=rgbarray6(datenArray[2*zahl],datenArray[2*zahl+1]);
zahl++;
//printf("\nrgbarr %d: r: %d g: %d b: %d\n",zahl, rgbarr[zahl-1].r,rgbarr[zahl-1].g,rgbarr[zahl-1].b);
}
if(zahl<a&&zahl<dateiLange){
rgbarr[zahl]=rgbarray6(datenArray[zahl],null);
zahl++;
//printf("\nrgbarr %d: r: %d g: %d b: %d\n",zahl, rgbarr[zahl-1].r,rgbarr[zahl-1].g,rgbarr[zahl-1].b);

}
while (zahl< a) {
rgbarr[zahl]=rgbarray6(null, null);
zahl++;
}



//compress()//zlib für später
dreibytestoblocks(blockbreite,blockhohe,rgbarr,(auflosungsbreite/blockbreite),(auflosungshohe/blockhohe),finalRgbArray);//8x8 block von rgbarray zu einem einzigen array mit rgb daten mit block
//arrToPic(rgbarr,argv[2]);//stb_image_write.h oder stbi_write_func wenn man die werte im ram laden will um es einem wrapper zurückzugeben
retur=stbi_write_png(argv[2],auflosungsbreite, auflosungshohe, 3, finalRgbArray, auflosungsbreite*3);
printf("\n%d\n",retur);



fclose(fp);
return 0;
}

//wir lesen datei ein in binär und wandeln jeden buchstaben in 0-9 a-z um. A wird zu a. 8 bits werden zu 6