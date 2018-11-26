#ifndef BD_h
#define BD_h
#include "view.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
typedef struct{
    char name[256];
    char key[256];
}tables;
typedef struct{
    char string[256];
}string;
void create_table(tables *tabelas);
char * type_def(char*type);
void veri_index(tables *point);
int veri_table ( tables *index,char nome[]);
void list_table(tables* index);
void insert_data(tables * index);
void list_data(tables * index);
int veri_key(char local_dados[],char local_format[],char chave[]);
void remove_data(tables * index);
void delete_table(tables *index);
void search_data(tables *index);
void change_data(tables *index);
int isIntValue(char value[]);
int isFloatValue(char value[]);
#endif