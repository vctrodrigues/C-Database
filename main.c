#include "BD.h"
#include "view.h"
int main()
{   
    mkdir("dbs", 0777);
    tables tabelas[200];
    tables *index =& tabelas[0];  
    veri_index(index);
    char select[256];
    char create[256]= "create_table";
    char list[256]= "list_table";
    char insert[256]= "insert_data";
    char listData[256]="list_data";
    print_menu();
    while(1){
        scanf("%s",select);
        getchar();
        print_separator();
        if (strcmp(select,create)==0){
            create_table(index);
        }
        else if (strcmp(select,list)==0){
            list_table(index);
        }
        else if (strcmp(select,insert)==0){
            insert_data(index);
        }
        else if (strcmp(select,listData)==0){
            list_data(index);
        }
        else{
            break;
        }
        
    }
    return 0;
}
