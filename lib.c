#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FileEntity* cargaArchivo(char* name){

    FileEntity *fileEntity;
    fileEntity = (FileEntity*)malloc(sizeof(FileEntity));
    fileEntity->name = strdup(name);
    fileEntity->file = fopen(fileEntity->name,"r");

    fseek(fileEntity->file,0,SEEK_END);
    fileEntity->size = ftell(fileEntity->file);
    fseek(fileEntity->file,0,SEEK_SET);

    fileEntity->buffer =(char*)malloc(fileEntity->size + 1);
    if(fileEntity->buffer == NULL){
        fprintf(stderr,"Error: No se pudo reservar memoria");
    }
    fread(fileEntity->buffer,1,fileEntity->size,fileEntity->file);

    fileEntity->buffer[fileEntity->size] = '\0';

    fclose(fileEntity->file);

    return fileEntity;
}
