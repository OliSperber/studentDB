// To include logic for basic table modification
#include "tableMod.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

const char STUDENTTABLE[] = "student.txt";
const char GRADETABLE[] = "grade.txt";

typedef struct Student
{
    int id;
    char name[50];
    int age;
    float gradeAvg;
} student;

typedef struct Grade
{
    int id;
    int studentId;
    float grade;
} grade;

// ALl methods to modify and read student table
student InsertStudent(student newStudent);
student UpdateStudent(student updatedStudent);
student GetStudent(int studentId);
void DeleteStudent(int studentId);
student *GetAllStudents(int size);

// All methods to modidy and read grade table
void InsertGrade(int studentId, float gradeId);
void DeleteGrade(int gradeId);
grade GetGrade(int gradeId);
grade *GetAllGrades(int size);

int main()
{

    system("cls");
    int command;

    printf("1. Read table raw\n");
    printf("2. Last Id From Table:\n");
    printf("Enter command:\n");
    scanf("%d", &command);

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
    default:
        printf("No such command is found.");
        break;
    }

    return 0;
}
