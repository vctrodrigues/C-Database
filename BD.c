#include "BD.h"
void creat_table(tables *tabelas){
    char name[256];
    char key [256];
    char* type =(char*) malloc(256*sizeof(char));
    char columns[256];
    char fim[30]= "0";
    char txt[20]=".txt";
    char point[30];
    printf("nome da tabela\n");
    fscanf(stdin,"%[^\n]",name);
    getchar();
    if(veri_table ( tabelas,name)){
        printf("Tabela ja existe\n");
        return;
    }
    strcpy(point,name);
    strcat(point,txt);
    FILE *table = fopen(point,"w+");
    fprintf(table,"name : %s\n",name);
    fprintf(table,"#Format#\n");
    printf("digte o nome da chave primaria\n");
    fscanf(stdin,"%[^\n]",key);
    getchar();
    fprintf(table,"int %s\n",key);
    do{
        printf("Digite o tipo da coluna que deseja ou 0 \n");
        scanf("%s",type);
        strcpy(type ,type_def(type));
        if (strcmp(type,fim)==0) break;
        printf("digite o nome da coluna\n");
        scanf("%s",columns);
        fprintf(table,"%s %s\n",type,columns);
    }while (strcmp(type,fim)!= 0);
    fprintf(table,"#Date#");
    FILE *index=fopen("index.txt","a+");
    fprintf(index,"Nome : %s\nChave : %s\n",name,key);
    fclose(index);
    fclose(table);     
}
char * type_def(char*type){
    char inteiro[30]= "int";
    char str[30] = "string";
    char chr[30]= "char";
    char flt[30] = "float";
    if (strcmp(type,inteiro)== 0) return "int";
    else if (strcmp(type,str)== 0) return "char[256]";
    else if (strcmp(type,chr)== 0) return "char";
    else if (strcmp(type,flt)== 0) return "float";
    else{
        printf("type não def\nfinalizar criação\n");
        return "0";
    }
}
void veri_index(tables *tabelas){
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
    //printf("primeira->%s  segunda->%s\n",(tabelas+i)->name,(tabelas+i)->key);
    if (indi->key==NULL) break;
    i++;
    }while(!feof(index));    
    fclose(index);
}
int veri_table ( tables *index,char nome[]){
    int i =0;
    while(strcmp(((index+i)->name),"")!= 0 ){    
        if (strcmp((index+i)->name,nome)==0){
            return 1 ;
        }
        i++;
    }
    return 0;
}