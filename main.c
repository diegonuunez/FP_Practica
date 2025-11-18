#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"

int main() {
    char command[100];
    char prompt[200] = ":>> ";
    
    FileEntity *fileEntity = cargaArchivo("archivo.txt");
    

    if (fileEntity == NULL) {
        fprintf(stderr, "Error: No se pudo cargar el archivo.\n");
        return 1; 
    }

    if (fileEntity->name != NULL) {
        char temp[200];
        sprintf(temp, "[:%s:] ", fileEntity->name);  
        strcat(prompt, temp);
    }

    while (1) {
        printf("%s", prompt);
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "exit", 4) == 0) {
            break;
        }
    }

    free(fileEntity->name);
    free(fileEntity->buffer);
    free(fileEntity);

    return 0;
}
