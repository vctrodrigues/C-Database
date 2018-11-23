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
int main(void)
{
    // tables tab [200];
    // tables* tabelas = tab;
    // tables lixo ;
    // tables * indi = &lixo;
    // FILE * index = fopen("index.txt","r+");
    // int i = 0 ;
    // do{
    // if (indi->name==NULL) break;
    // fscanf(index,"Nome : %s\n",indi->name);
    // fscanf(index,"Chave : %s\n",indi->key);
    // strcpy((tabelas+i)->name,indi->name);
    // strcpy((tabelas+i)->key,indi->key);
    // printf("primeira->%s  segunda->%s\n",(tabelas+i)->name,(tabelas+i)->key);
    // if (indi->key==NULL) break;
    // i++;
    // }while(!feof(index));
    // fclose(index);
    // FILE * format;
    // FILE * data;
    // int aux =0;
    // int aux1=0;
    // string colunas[10];
    // string *coll=&colunas[0];
    // string base [20][20];
    // string *datas= &base[0][0];
    // char desp[50];
    // char name [256];
    // char dados [40];
    // char dat [20]=".data";
    // char csv[20]=".txt";
    // char local[200]="dbs/";
    // printf("Digite nome da tabela\n");
    // scanf("%s",name);
    // // veri_index(index);
    // // if (veri_table(index,name)) return;
    // strcat(local,name);
    // strcat(local,"/");
    // strcat(local,name);
    // strcpy(dados,local);
    // strcat(local,csv);
    // strcat(dados,dat);
    // format = fopen(local,"r+");
    // data = fopen(dados,"r+");
    // while(!feof(format)){
    //     if (colunas==NULL) break;
    //     fscanf(format,"%s ;%s",desp,(coll+aux)->string);
    //     fgetc(format);
    //     if (colunas==NULL) break;
    //     aux++;
    // }
    // for(int i =0;i<aux-1;i++){
    //     printf("%s |",colunas[i].string);
    // }
    // printf("\n");
    // printf("valor de aux %d\n", aux);
    // do{
    //     for(int i = 0;i<aux-1;i++){
    //         fscanf(data,"%s ;",base[aux1][i].string);
    //     }
    //     aux1++;
    // }while(!feof(data));
    // for(int i =0;i< aux1-1;i++){
    //     for(int j =0;j<aux-1;j++){
    //       printf("%s |",base[i][j].string);
    //     }
    //     printf("\n");
    // }
    // fclose(data);
    // fclose(format);
    char chave[50];
    printf("chave :");
    scanf("%s", chave);
    FILE *dados = fopen("dbs/itp/itp.data", "r+");
    FILE *formato = fopen("dbs/itp/itp.txt", "r+");
    if (formato == NULL)
    {
        printf("arquivo não foi aberto\n");
    }
    char lixo[256];
    int aux = 0;
    while (!feof(formato))
    {
        fgets(lixo, 256, formato);
        if (lixo == NULL)
            break;
        aux++;
    }
    printf("valor de aux %d\n", aux);
    while (!feof(dados))
    {
        for (int i = 0; i < aux - 1; i++)
        {
            fscanf(dados, "%s ;", lixo);
            if ((i == 0) && (strcmp(lixo, chave) == 0))
            {
                printf("chave primaria ja existe");
                return 0;
            }
        }
    }
    fclose(formato);
    fclose(dados);
    return 0;
}