#include "BD.h"
int main()
{   
    tables tabelas[200];
    tables *index =& tabelas[0];  
    veri_index(index);
    int i=0;
    char select[256];
    char creat[256]= "creat_table";
    char list[256]= "list_table";
    while(1){
        scanf("%s",select);
        getchar();
        if (strcmp(select,creat)==0){
            creat_table(index);
        }
        else if (strcmp(select,list)==0){
            veri_index(index);
            
            while(strcmp(((index+i)->name),"")!= 0 ){
                printf("Tabela:%s\n",(index+i)->name);
            i++;
            }
            i=0;
        }
        else{
            break;
        }
        
    }
    return 0;
}
