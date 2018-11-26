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
    if(veri_table(tabelas,name)){
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
    printf("Digte o nome da chave primária> ");
    fscanf(stdin,"%[^\n]",key);
    getchar();
    fprintf(table,"int ;%s\n",key);
    do{
        printf("Digite o tipo da coluna que deseja ou 0> ");
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
    
    do {
        if (indi->name==NULL) break;
        fscanf(index,"Nome : %s\n",indi->name);
        fscanf(index,"Chave : %s\n",indi->key);
        strcpy((tabelas+i)->name,indi->name);
        strcpy((tabelas+i)->key,indi->key);
        //printf("primeira->%s  segunda->%s\n",(tabelas+i)->name,(tabelas+i)->key);
        if (indi->key==NULL) break;
        i++;
    } while(!feof(index));    

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

tables* get_table(tables *index,char nome[256]) {
    int i = 0;
    while(strcmp(((index+i)->name),"") != 0){    
        if (strcmp((index+i)->name, nome) == 0){
            return (index+i);
        }
        i++;
    }
    return NULL;
}

void insert_data(tables *index) {
    char nome[256];
    printf("Nome da tabela: ");
    scanf("%s", nome);

    tables *table = get_table(index, nome);

    if(table == NULL) {
        printf("Tabela não encontrada!\n");
    } else {
        char local[200]="dbs/"; 
        char info[200];

        strcat(local, nome);
        strcat(local, "/");
        strcat(local, nome);
        strcpy(info, local);

        strcat(local, ".txt");
        strcat(info, ".data");

        FILE * columns;
        FILE * data;

        columns = fopen(local, "r");
        data = fopen(info, "a");

        char row[2000] = "";

        int isPK = 1;
        do {
            char value[256];

            char type[30];
            char column[30];

            getchar();
            fscanf(columns, "%s ;%s\n", type, column);

            printf("Valor de |%s| (%s): ", column, type);
            fscanf(stdin, "%[^\n]", value);
            
            if(isPK == 1) {
                if(veri_key(info,local,value)){
                    printf("Chave primária já existe!\n");
                    return;
                }
                isPK = 0;
            }
            
            strcat(row, value);
            strcat(row, " ;");
        } while(!feof(columns));

        strcat(row, "\n");
        fprintf(data, "%s", row);

        fclose(data);
        fclose(columns);

        printf("Dados inseridos na tabela!\n");
    }
}

void list_table(tables* index){
    int i = 0;
    veri_index(index);
    
    while(strcmp(((index+i)->name),"") != 0){
        printf("Tabela: %s\n",(index+i)->name);
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
    printf("Digite nome da tabela> ");
    scanf("%s",name);
    if (veri_table(index,name)!= 1) {
        printf("Tabela não existe\n");
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
    
    while(!feof(format)) {
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
int veri_key(char local_dados[],char local_format[],char chave[]){
    FILE *dados= fopen(local_dados,"r+");
    FILE *formato= fopen(local_format,"r+");
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
    // printf("valor de aux %d\n", aux);
    while (!feof(dados))
    {
        for (int i = 0; i < aux - 1; i++)
        {
            fscanf(dados, "%s ;", lixo);
            if ((i == 0) && (strcmp(lixo, chave) == 0))
            {
                return 1;
            }
        }
    }
    fclose(formato);
    fclose(dados);
    return 0;
}
void remove_data(tables * index){
    FILE *format;
    FILE *data;
    FILE *newData;
    char desp[50];
    char name [256];
    char dados [40];
    char dat [20]=".data";
    char csv[20]=".txt";
    char local[200]="dbs/";
    char new_data[256];
    char lixo[256];
    char chave [256];
    int aux = 0;
    int aux2=0;
    printf("Digite nome da tabela\n");
    scanf("%s",name);
    if (veri_table(index,name)!= 1) {
        printf("Tabela Não existe\n");
        return;
    }
    printf("Digite a chave primaria\n");
    scanf("%s",chave);
    strcat(local,name);
    strcat(local,"/");
    strcat(local,name);
    strcpy(dados,local);
    strcpy(new_data,local);
    strcat(local,csv);
    strcat(dados,dat);
    strcat(new_data,".alterado");
    format = fopen(local,"r+");
    data = fopen(dados,"r+");
    newData=fopen(new_data,"w");
    while (!feof(format))
    {
        fgets(lixo, 256, format);
        if (lixo == NULL)
            break;
        aux++;
    }
    while (!feof(data))
    {
        fgets(lixo, 256, data);
        if (lixo == NULL)
            break;
        aux2++;
    }
    fseek(data,0,SEEK_SET);
    for (int k =0;k<aux2-1;k++)
    {
        for (int i = 0; i < aux - 1; i++)
        {
            fscanf(data, "%s ;", lixo);
            if ((i == 0) && (strcmp(lixo, chave) == 0))
            {
                // printf("data deletados:\n");
                // fgets(lixo, 256, data);
                for(int j =0;j<aux-2;j++){
                fscanf(data, "%s ;", lixo);
                // printf("%s||",lixo); 
                }
                break;
            }
            else if (i==aux-2){
                fprintf(newData,"%s ;\n",lixo);
            }
            else{
                fprintf(newData,"%s ;",lixo);
            }
        }
    }
    remove(dados);
    rename(new_data,dados);
    fclose(format);
    fclose(data);
    fclose(newData);
    return ;
}
void delete_table(tables *index){
    FILE *tabelas;
    FILE *newTable;
    int aux=0;
    char accumulator[256];
    char accumulator2[256];
    char name[256];
    char local[200]="dbs/";
    char dados[200];
    char formato[200];
    printf("Digite nome da tabela\n");
    scanf("%s",name);
    if (veri_table(index,name)!= 1) {
        printf("Tabela Não existe\n");
        return;
    }
    tabelas = fopen("index.txt","r+");
    newTable = fopen("index.alterado","w+");
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
    fclose(tabelas);
    fclose(newTable);
    remove("index.txt");
    rename("index.alterado","index.txt");
    strcat(local,name);
    strcpy(dados,local);
    strcat(dados,"/");
    strcat(dados,name);
    strcpy(formato,dados);
    strcat(dados,".data");
    strcat(formato,".txt");
    remove(dados);
    remove(formato);
    remove(local);
    return;
}

void search_data(tables *index) {
    FILE * format;
    FILE * data;

    int count = 0;
    
    string columns[10];
    string *columnName = &columns[0];
    string typeColumns[10];
    string *columnType = &typeColumns[0];
    string base[20][20];
    string *datas = &base[0][0];
    
    char name[256];
    char dados[40];
    char dat[20]=".data";
    char csv[20]=".txt";
    char local[200]="dbs/";
    printf("Digite o nome da tabela> ");
    scanf("%s",name);

    char selectedColumn[100];

    printf("Digite o nome da coluna> ");
    scanf("%s", selectedColumn);

    if(veri_table(index,name)!= 1) {
        printf("Tabela não existe\n");
        return;
    }

    int option = 0;

    print_search_options();
    scanf("%d", &option);

    strcat(local,name);
    strcat(local,"/");
    strcat(local,name);
    strcpy(dados,local);
    strcat(local,csv);
    strcat(dados,dat);
    
    format = fopen(local, "r+");
    data = fopen(dados, "r+");
    
    while(!feof(format)){    
        fscanf(format,"%s ;%s",(columnType+count)->string,(columnName+count)->string);
        fgetc(format);
        count++;    
    }

    int count2 = 0;
    int columnIndex = 0;

    char selectedType[256];

    for(int i = 0; i < count-1; i++){
        if(strcmp(columns[i].string, selectedColumn) == 0) {
            strcpy(selectedType, typeColumns[i].string);
            break;
        }
        columnIndex++;
    }   

    int intSearchTerm;
    char charSearchTerm[256];
    float floatSearchTerm;
    printf("Digite o termo de busca> ");
    if(strcmp(selectedType, "int") == 0) {
        scanf("%d", &intSearchTerm);
    } else if(strcmp(selectedType, "char[256]") == 0 || strcmp(selectedType, "char") == 0) {
        scanf("%s", &charSearchTerm);
    } else if(strcmp(selectedType, "float") == 0) {
        scanf("%f", &floatSearchTerm);
    }

    while(!feof(data)) {
        int columnCount = 0;
        while(1) {
            if(columnCount == columnIndex) {
                break;
            }
            string trash;
            fscanf(data, "%s ;", trash.string);
            columnCount++;
        }

        if(strcmp(selectedType, "int") == 0) {
            int value = 0;
            fscanf(data, "%d ;", &value);

            switch(option) {
                case 1: 
                if(value > intSearchTerm) {
                    printf("%d\n", value);
                }
                break;
                case 2:
                if(value >= intSearchTerm) {
                    printf("%d\n", value);
                }
                break;
                case 3:
                if(value == intSearchTerm) {
                    printf("%d\n", value);
                }
                break;
                case 4:
                if(value < intSearchTerm) {
                    printf("%d\n", value);
                }
                break;
                case 5:
                if(value <= intSearchTerm) {
                    printf("%d\n", value);
                }
                break;
                default:
                break;
            }

        } else if(strcmp(selectedType, "char[256]") == 0 || strcmp(selectedType, "char") == 0) {
            char value[256];
            fscanf(data, "%s ;", value);

            if(strstr(value, charSearchTerm)) {
                printf("%s\n", value);
            }

        } else if(strcmp(selectedType, "float") == 0) {
            float value;
            fscanf(data, "%f ;", value);

            switch(option) {
                case 1: 
                if(value > floatSearchTerm) {
                    printf("%f\n", value);
                }
                break;
                case 2:
                if(value >= floatSearchTerm) {
                    printf("%f\n", value);
                }
                break;
                case 3:
                if(value == floatSearchTerm) {
                    printf("%f\n", value);
                }
                break;
                case 4:
                if(value < floatSearchTerm) {
                    printf("%f\n", value);
                }
                break;
                case 5:
                if(value <= floatSearchTerm) {
                    printf("%f\n", value);
                }
                break;
                default:
                break;
            }
        }

        if(columnCount == count-2) {
            string trash;
            fscanf(data, "\n", trash.string);
        }

        while(columnCount < count-2) {
            if(columnCount == count-3) {
                string trash;
                fscanf(data, "%s ;\n", trash.string);
            } else {
                string trash;
                fscanf(data, "%s ;", trash.string);
            }
            columnCount++;
        }
        
    }

    

}