#include "BD.h"

int main()
{   
    system("clear");
    mkdir("dbs", 0777);
    tables tabelas[200];
    tables *index =& tabelas[0];  
    veri_index(index);
    char select[256];
    char create[256]= "create_table";
    char list[256]= "list_table";
    char insert[256]= "insert_data";
    char listData[256]="list_data";
    char removeData[256]="remove_data";
    char deleteTable[256]="delete_table";
    char searchData[256]="search_data";
    char alteraDado[256]="change_data";
    char saida[50]="exit";
    char clear[50]="clear";
    char help[50]="help";
    print_menu();
    while(1){
        scanf("%s",select);
        getchar();
        print_separator();
        veri_index(index);
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
        else if (strcmp(select,removeData)==0){
            remove_data(index);
        }
        else if (strcmp(select,deleteTable)==0){
            delete_table(index);
        } else if (strcmp(select,searchData) == 0) {
            search_data(index);
        }
        else if (strcmp(select,alteraDado)==0){
            change_data(index);
        } else if (strcmp(select,help)==0){
            print_commands(index);
        }
        else if (strcmp(select,saida)==0){
            break;
        }
        else if (strcmp(select,clear)==0){
            system(clear);
            print_menu_header();
        }
        else{
            print_err("Comando não reconhecido");
        }
        print_separator();
        print_receive_command();
    }
    return 0;
}
