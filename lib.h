#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LIB_H
#define LIB_H

typedef struct Entity{
    FILE* file;
    char* name;
    char* buffer;
    size_t size;
} FileEntity;

char* capturaCommand(char* command);
FileEntity* cargaArchivo(char* name);
int commandHandler(char* command);

#endif