#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printStudentInfo(){
    printf("%s Diego Nuñez Conejo - diego.nunez@goumh.umh.es \n",COLOR_YELLOW);
}

char* commandHandler(char* command){
    char* trimmedCommand = (char*)malloc(strlen(command)+1);
    for(int i = 0; command[i]; i++){
        trimmedCommand[i] = tolower(command[i]);
    }
    char* firstPartCommand = strtok(trimmedCommand, " ");
    
    char* secondPartCommand = strtok(NULL, " \n");

    free(trimmedCommand);
    return firstPartCommand, secondPartCommand;
}


