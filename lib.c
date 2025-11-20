#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printStudentInfo(){
    printf("%s Diego Nunez Conejo - diego.nunez@goumh.umh.es \n",COLOR_YELLOW);
}

void commandHandler(char* command){
    char** tokenVector ;
    int tokenCount = 0;

    for(int i = 0; command[i]; i++){
        command[i] = tolower(command[i]);
        if(command[i] == '\n'){
            command[i] = '\0';
        }
        if(command[i] == ' '){
            tokenCount++;
        }
    }
    tokenVector = (char**) malloc((tokenCount + 1) * sizeof(char*));
    tokenCount = 0;
    char* token = strtok(command, " \0");
    while(token != NULL){
        tokenVector[tokenCount] = (char*) malloc((strlen(token) + 1) * sizeof(char));
        strcpy(tokenVector[tokenCount], token);
        tokenCount++;
        token = strtok(NULL, " \0");
    }
    commandManager(tokenVector, tokenCount);

    for(int i = 0; i < tokenCount; i++){
        free(tokenVector[i]);
    }
    free(tokenVector);
}


void commandManager(char** tokenVector, int tokenCount){

    if(strcmp(tokenVector[0], "salir\0") == 0){
        printf("%s FIN... %s\n", COLOR_GREEN, COLOR_RESET);
        exit(0);
    } else if(strcmp(tokenVector[0], "cargar\0") == 0){
        
        printf("%scargar%s - Load a file\n", COLOR_YELLOW, COLOR_RESET);
    } else {
        printf("%sUnknown command: %s%s\n", COLOR_RED, tokenVector[0], COLOR_RESET);
    }

}


