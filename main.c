#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "translate6.h"
#include "size.h"
#include "rgbarray.h"




int main(int argc, char *argv[])
{

int auflosungsbreite=1080;
int auflosungshohe=1080;
int blockbreite=8;

// argc → number of arguments
// argv → array of arguments

int a=(auflosungsbreite/blockbreite)*(auflosungshohe/blockbreite);


uint8_t byteDaten[a];
if(argc > 3){
printf("\nToo many arguments");
return -1;
}
FILE *fp = fopen(argv[1], "rb");

if(fp == NULL){
printf("\n\nError with %s",argv[1]);
perror( argv[1] );
return 1;
}
long dateiLange = size(argv[1]);

uint6_t datenArray[dateiLange];

for(long i =0;i<datei;i++){

printf("\n\n%d",fread(&byteDaten[i], 1,1, fp));

datenArray[i]=translate(byteDaten[i]);

printf("\n\n%X %X",byteDaten[i], datenArray[i]);
}

uint8_t rgbarr[size*3];

long a = 0;
while(a+1<dateiLange){

}
if(a<dateiLange){
writeToRgb(datenArray[a],000000);
}



fclose(fp);
return 0;
}

//wir lesen datei ein in binär und wandeln jeden buchstaben in 0-9 a-z um. A wird zu a. 8 bits werden zu 6