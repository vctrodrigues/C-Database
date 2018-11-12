#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct{
    char name[256];
    char key[256];
}tables;
int main (void){
    tables tab [200];
    tables* tabelas = tab;
    tables lixo ;
    tables * indi = &lixo;
    FILE * index = fopen("index.txt","r+");
    int i = 0 ;
    do{
    if (indi->name==NULL) break;
    fscanf(index,"Nome : %s\n",indi->name);
    fscanf(index,"Chave : %s\n",indi->key);
    strcpy((tabelas+i)->name,indi->name);
    strcpy((tabelas+i)->key,indi->key);
    printf("primeira->%s  segunda->%s\n",(tabelas+i)->name,(tabelas+i)->key);
    if (indi->key==NULL) break;
    i++;
    }while(!feof(index));    
    fclose(index);
}