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
    // char chave[50];
    // printf("chave :");
    // scanf("%s", chave);
    // FILE *dados = fopen("dbs/itp/itp.data", "r+");
    // FILE *formato = fopen("dbs/itp/itp.txt", "r+");
    // FILE *dados2 = fopen("dbs/itp/itp.alterado", "w");
    // if (formato == NULL)
    // {
    //     printf("arquivo não foi aberto\n");
    // }
    // char lixo[256];
    // int aux = 0;
    // int aux2=0;
    // while (!feof(formato))
    // {
    //     fgets(lixo, 256, formato);
    //     if (lixo == NULL)
    //         break;
    //     aux++;
    // }
    // while (!feof(dados))
    // {
    //     fgets(lixo, 256, dados);
    //     if (lixo == NULL)
    //         break;
    //     aux2++;
    // }
    // printf("valor de aux %d\n", aux);
    // printf("valor de aux2 %d\n", aux2);
    // fseek(dados,0,SEEK_SET);
    // for (int k =0;k<aux2-1;k++)
    // {
    //     for (int i = 0; i < aux - 1; i++)
    //     {
    //         fscanf(dados, "%s ;", lixo);
    //         if ((i == 0) && (strcmp(lixo, chave) == 0))
    //         {
    //             printf("Dados deletados:\n");
    //             // fgets(lixo, 256, dados);
    //             for(int j =0;j<aux-2;j++){
    //             fscanf(dados, "%s ;", lixo);
    //             printf("%s||",lixo); 
    //             }
    //             break;
    //         }
    //         else if (i==aux-2){
    //             fprintf(dados2,"%s ;\n",lixo);
    //         }
    //         else{
    //             fprintf(dados2,"%s ;",lixo);
    //         }
    //     }
    // }
    // remove("dbs/itp/itp.data");
    // rename("dbs/itp/itp.alterado","dbs/itp/itp.data");
    // fclose(formato);
    // fclose(dados);
    // fclose(dados2);
    FILE *tabelas;
    FILE *newTable;
    int aux;
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
    remove("index.txt");
    rename("index.alterado","index.txt");
    fclose(tabelas);
    fclose(newTable);
    delete_pasta(name);
    return 0;
}