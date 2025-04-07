#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tableMod.h"

void ReadTableRaw(const char table[])
{
    FILE *tablePtr = fopen(table, "r");

    char tableContent[200];

    while (fgets(tableContent, 200, tablePtr))
    {
        printf("%s", tableContent);
    }

    fclose(tablePtr);
}

int LastIdFromTable(const char table[])
{
    FILE *tablePtr = fopen(table, "r");

    int lastId = -1;
    while (fscanf(tablePtr, "%d", lastId) == 1)
        fclose(tablePtr);

    if (lastId == -1)
    {
        SetLastId(table, 0);
        LastIdFromTable(table);
    }

    return lastId;
}

void SetLastId(const char table[], int id)
{
    FILE *tablePtr = fopen(table, "w");

    fprintf(tablePtr, "%d", id);

    fclose(tablePtr);
}

bool AskWhatTable()
{
    system("cls");
    printf("1. student\n2. grade\nSelect a Table:\n");

    int selected = 0;
    scanf("%d", &selected);

    if (selected == 1)
        return true;
    else
        return false;
}