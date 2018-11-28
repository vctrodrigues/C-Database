#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct
{
    char string[256];
} string;
typedef struct
{
    char name[256];
    char key[256];
} tables;
int isIntValue(char valor[]){
    for(int i = 0; i < sizeof(valor); i++) {
        if((valor[i] < 48 || valor[i] > 57) && !(valor[i] == 0)) {
            return 0;           
        }
    }
    return 1;
}

int isFloatValue(char valor[]){
    for(int i = 0; i < sizeof(valor); i++) {
        if((valor[i] < 48 || valor[i] > 57) && !(valor[i] == 0)) {
            if(valor[i] != 46) return 0;           
        }
    }
    return 1;
}
int main(void)
{
    FILE *tabelas;
    FILE *newTable;
    int aux=0;
    int select =0 ;
    char accumulator[256];
    char accumulator2[256];
    char name[256];
    // printf("Digite nome da tabela\n");
    // scanf("%s",name);
    // if (veri_table(index,name)!= 1) {
    //     printf("Tabela Não existe\n");
    //     return;
    // }
    scanf("%d",&select);
    scanf("%s",name);
    tabelas = fopen("dbs/equipe/equipe.txt","r+");
    do
    {   
        aux++;
        fscanf(tabelas,"%s ;%s",accumulator,accumulator2);
        fgetc(tabelas);
    }while (aux<select+1);
    printf("%s %s\n",accumulator,accumulator2);
    if((strcmp(accumulator,"int")==0) &&(isIntValue(name))){
        printf("interio vdd");
        return 0;
    }
    else if((strcmp(accumulator,"float")==0) &&(isFloatValue(name))){
        printf("é float vdd");
    }
    else if((strcmp(accumulator,"char")==0) &&(isIntValue(name)==0)&&(isFloatValue(name)==0)){
        printf("é char vdd");
        return 0;
    }
    printf("EROOOU");
    
    return 0;
}