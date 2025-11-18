#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char command[100];
    
    char* buffer = cargaArchivo("archivo.txt");

    printf("Contenido del archivo:\n\n%s\n", buffer);

    free(buffer); 
    return 0;
}
