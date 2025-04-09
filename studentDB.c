// To include logic for basic table modification
#include "tableMod.h"
#include "StudentLogic.h"
#include "gradeLogic.h"
#include "TablePaths.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>




int main()
{
    system("cls");
    int command;

    printf("1. Read table raw\n");
    printf("2. Last Id From Table:\n");
    printf("\n15. Exit.\n");
    printf("Enter command:\n");
    scanf("%d", &command);

    bool leaveProgram = false;

    switch (command)
    {
        case 1:
            ReadTableRaw(AskWhatTable() ? STUDENTTABLE : GRADETABLE);
            break;
        case 2:
            LastIdFromTable(AskWhatTable() ? STUDENTTABLE : GRADETABLE);
            break;
        case 3:
            break;
        case 15:
            leaveProgram = true;
            break;
        default:
            printf("No such command is found.");
            break;
    }

    return 0;
}

