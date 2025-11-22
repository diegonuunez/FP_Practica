#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printStudentInfo(){
    printf("%s Diego Nunez Conejo - diego.nunez@goumh.umh.es \n",COLOR_YELLOW);
}

char** commandClient(char* command, int* size){
    char** tokenVector;
    int tokenCount = 0;
    int index = 0;

    for(int i = 0; i < strlen(command); i++){
        if(command[i] == ' '){
            tokenCount++;
        }
    }

    tokenVector = (char**)malloc(sizeof(char*) * (tokenCount+1));

    char* token = strtok(command," \n");


    for(int i = 0 ; i < strlen(token); i++){
        token[i] = tolower(token[i]);
    }

    tokenVector[index] = token;
    
    while(token!=NULL){

        token = strtok(NULL," ");
        if(token!=NULL){
            index++;
            tokenVector[index] = token;
            printf("%s",tokenVector[index]);
        }
    }
    *size = index;

    return tokenVector;
  
}


void commandManager(char* command){
    int size;
    char** tokenVector = commandHandler(command,&size);

    if(strcmp(tokenVector[0], "salir") == 0){
        printf("%s FIN... %s\n", COLOR_GREEN, COLOR_RESET);
        exit(0);
    } else if(strcmp(tokenVector[0], "cargar\0") == 0){
        
        printf("%scargar%s - Load a file\n", COLOR_YELLOW, COLOR_RESET);
        
    } else {
        printf("%sUnknown command: %s%s\n", COLOR_RED, tokenVector[0], COLOR_RESET);
    }


    for(int i = 0; i < size; i++){
        free(tokenVector[i]);
    }
    free(tokenVector);
}





