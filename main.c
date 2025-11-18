#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char* command;
    while(1)
    {  
        scanf("%99s",command);
        if(strcmp(command,"exit") == 0)
        {
            exit(-1);
        }
    }
}