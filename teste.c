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
void delete_pasta(char name[]){
    char local[200]="dbs/";
    char dados[200];
    char formato[200];
    strcat(local,name);
    strcpy(dados,local);
    strcat(dados,"/");
    strcat(dados,name);
    strcpy(formato,dados);
    strcat(dados,".data");
    strcat(formato,".txt");
    printf("%s\n%s\n%s\n",local,dados,formato);
    remove(dados);
    remove(formato);
    remove(local);
}
int main(void)
{
    FILE *tabelas;
    FILE *newTable;
    int aux=0;
    char accumulator[256];
    char accumulator2[256];
    char name[256];
    printf("Digite nome da tabela\n");
    scanf("%s",name);
    // if (veri_table(index,name)!= 1) {
    //     printf("Tabela Não existe\n");
    //     return;
    // }
    tabelas = fopen("index.txt","r+");
    newTable = fopen("index.alterado","w");
    while (!feof(tabelas))
    {   
        fgets(accumulator,256,tabelas);
        aux++;
    }
    fseek(tabelas,0,SEEK_SET);
    for (int i =0;i<aux-1;i++){
        fscanf(tabelas,"%s : %s",accumulator,accumulator2);
        if((strcmp(accumulator,"Nome")==0)&&(strcmp(accumulator2,name)==0))
        {
            fscanf(tabelas,"%s : %s",accumulator,accumulator2);
            i++;
        }
        else{
            fprintf(newTable,"%s : %s\n",accumulator,accumulator2);
        }
    }
    // remove("index.txt");
    // rename("index.alterado","index.txt");
    fclose(tabelas);
    fclose(newTable);
    // delete_pasta(name);
    char local[200]="dbs/";
    char dados[200];
    char formato[200];
    strcat(local,name);
    strcpy(dados,local);
    strcat(dados,"/");
    strcat(dados,name);
    strcpy(formato,dados);
    strcat(dados,".data");
    strcat(formato,".txt");
    printf("%s\n%s\n%s\n",local,dados,formato);
    remove(dados);
    remove(formato);
    remove(local);
    return 0;
}