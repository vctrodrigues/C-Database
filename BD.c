#include "BD.h"
void create_table(tables *tabelas){
    char dat [20]=".data";
    char csv[20]=".txt";
    char local[200]="dbs/"; 
    char name[256];
    char key [256];
    char* type =(char*) malloc(256*sizeof(char));
    char columns[256];
    char fim[30]= "0";
    char dados [40];
    printf("nome da tabela\n");
    fscanf(stdin,"%[^\n]",name);
    getchar();
    if(veri_table ( tabelas,name)){
        printf("Tabela ja existe\n");
        return;
    }
    mkdir(strcat(local,name), 0777);
    strcat(local,"/");
    strcat(local,name);
    strcpy(dados,local);
    strcat(local,csv);
    strcat(dados,dat);
    // printf("%s\n%s\n",local,dados);
    FILE *table = fopen(local,"w+");
    if (table==NULL){
        printf("falha na abertura");
    }
    FILE *data = fopen(dados,"w+");
    if (data==NULL){
        printf("falha na abertura");
    }
    printf("digte o nome da chave primaria\n");
    fscanf(stdin,"%[^\n]",key);
    getchar();
    fprintf(table,"int ;%s\n",key);
    do{
        printf("Digite o tipo da coluna que deseja ou 0 \n");
        scanf("%s",type);
        strcpy(type ,type_def(type));
        if (strcmp(type,fim)==0) break;
        printf("digite o nome da coluna\n");
        scanf("%s",columns);
        fprintf(table,"%s ;%s\n",type,columns);
    }while (strcmp(type,fim)!= 0);
    FILE *index=fopen("index.txt","a+");
    fprintf(index,"Nome : %s\nChave : %s\n",name,key);
    fclose(index);
    fclose(table);
    fclose(data);     
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
void list_table(tables* index){
    int i =0;
    veri_index(index);
    while(strcmp(((index+i)->name),"")!= 0 ){
    printf("Tabela:%s\n",(index+i)->name);
    i++;
    }
    i=0;
}
void list_data(tables * index){
    FILE * format;
    FILE * data;
    int aux =0;
    int aux1=0;
    string colunas[10];
    string *coll=&colunas[0];
    string base [20][20];
    string *datas= &base[0][0];
    char desp[50];
    char name [256];
    char dados [40];
    char dat [20]=".data";
    char csv[20]=".txt";
    char local[200]="dbs/";
    printf("Digite nome da tabela\n");
    scanf("%s",name);
    if (veri_table(index,name)!= 1) {
        printf("Tabela Não existe\n");
        return;
    }
    strcat(local,name);
    strcat(local,"/");
    strcat(local,name);
    strcpy(dados,local);
    strcat(local,csv);
    strcat(dados,dat);
    format = fopen(local,"r+");
    data = fopen(dados,"r+");
    while(!feof(format)){
        if (colunas==NULL) break;
        fscanf(format,"%s ;%s",desp,(coll+aux)->string);
        fgetc(format);
        if (colunas==NULL) break;
        aux++;    
    }
    for(int i =0;i<aux-1;i++){
        printf("%s |",colunas[i].string);
    }
    printf("\n");
    do{
        for(int i = 0;i<aux-1;i++){
            fscanf(data,"%s ;",base[aux1][i].string);
        }
        aux1++;
    }while(!feof(data));
    for(int i =0;i< aux1-1;i++){
        for(int j =0;j<aux-1;j++){
          printf("%s |",base[i][j].string);  
        }
        printf("\n");
    }
    fclose(data);
    fclose(format);
    return;
}