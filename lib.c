#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printStudentInfo(){
    printf("%s Diego Nuñez Conejo - diego.nunez@goumh.umh.es \n",COLOR_YELLOW);
    char prompt[100] = ":>>";
    char command[200];

    int runConst = 1;
    while (runConst)
    {
        printf(prompt);
        scanf(command);
        if(strcmp(command,"exit")){
            printf("%s FIN...");
            exit(-1);
        }
    }
    
}