#ifndef BD_h
#define BD_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct{
    char name[256];
    char key[256];
}tables;
void creat_table(tables *tabelas);
char * type_def(char*type);
void veri_index(tables *point);
int veri_table ( tables *index,char nome[]);
#endif