#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

// Lee el archivo completo y devuelve un buffer con su contenido.
// El llamador debe hacer free(buffer) al finalizar.
char* cargaArchivo(char* name){
    long size = 0;
    char* buffer;
    size_t bytes = 0;

    FILE* file = fopen(name, "r");
    if (file == NULL){
        fprintf(stderr, "Error: No se ha podido abrir archivo %s\n", name);
        exit(1);
    }

    // Ir al final para conocer el tamaño
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Reservar buffer
    buffer = (char*)malloc(size + 1);
    if (buffer == NULL){
        fprintf(stderr, "Error: no se pudo reservar memoria.\n");
        fclose(file);
        exit(1);
    }

    // Leer contenido
    bytes = fread(buffer, 1, size, file);
    buffer[bytes] = '\0'; // Cerrar cadena con NULL

    fclose(file); // Muy importante

    return buffer;
}
