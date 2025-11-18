#include <stdio.h>
#include <stdlib.h>
#ifndef LIB_H
#define LIB_H

char* capturaCommand(char* command);
FILE* cargaArchivo(FILE* file);
int gestionCommand(char* command);

#endif /* LIB_H */