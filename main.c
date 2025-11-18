#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Reserva obligatoria para evitar segmentation fault
    char command[100];

    // Cargar archivo completo
    char* buffer = cargaArchivo("archivo.txt");

    printf("Contenido del archivo:\n\n%s\n", buffer);

    free(buffer); // Evita fuga de memoria

    return 0;
}
