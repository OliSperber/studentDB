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
    printf("\n");
    printf("3. Insert Student\n");
    printf("4. Update Student\n");
    printf("5. Get Single Student\n");
    printf("6. Delete Student\n");
    printf("7. Get All Students\n");
    printf("\n");
    printf("8. Insert grade\n");
    printf("9. Delete Grade\n");
    printf("10. Get Single Grade\n");
    printf("11. Get Grades Of Student\n");
    printf("12. Get All Grades\n");
    printf("\n");
    printf("13. Exit.\n");
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
            InsertStudent();
            break;
        case 4:
            UpdateStudent();
            break;
        case 5:
            GetStudent();
            break;
        case 6:
            DeleteStudent();
            break;
        case 7:
            GetAllStudents();
            break;
        case 8:
            InsertGrade();
            break;
        case 9:
            DeleteGrade();
            break;
        case 10:
            GetGrade();
            break;
        case 11:
            GetGradeOfStudent();
            break;
        case 12:
            GetAllGrades();
            break;
        case 13:
            leaveProgram = true;
            break;
        default:
            printf("No such command is found.");
            break;
    }

    return 0;
}

