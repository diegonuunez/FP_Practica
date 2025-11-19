#include "lib.h"
#include <string.h>

int main() {
    char prompt[100] = ":>>";
    char command[200];

    printStudentInfo();
    int runConst = 1;
    while (runConst)
    {
        printf("%s%s ",COLOR_GREEN,prompt);
        printf("%s",COLOR_WHITE);
        fgets(command, sizeof(command), stdin);
        commandHandler(command);
        
    }

}