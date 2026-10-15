#include "size.h"
#include <stdio.h>

long size(char datei[]){
FILE *fp = fopen(datei,"rb");
fseek(fp,0,SEEK_END);
int a = ftell(fp);
fclose(fp);
return a;
}
