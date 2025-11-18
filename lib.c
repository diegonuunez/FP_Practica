#include "lib.h"
#include <stdio.h>
#include <stdlib.h>


char* cargaArchivo(char* name){
    long size = 0;
    char* buffer;
    size_t bytes = 0;

    FILE* file = fopen(name, "r");
    if (file == NULL){
        fprintf(stderr, "Error: No se ha podido abrir archivo %s\n", name);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = (char*)malloc(size + 1);
    if (buffer == NULL){
        fprintf(stderr, "Error: no se pudo reservar memoria.\n");
        fclose(file);
        exit(1);
    }

    bytes = fread(buffer, 1, size, file);
    buffer[bytes] = '\0'; 

    fclose(file); 

    return buffer;
}
