#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

const char STUDENTTABLE[] = "student.txt";
const char GRADETABLE[] = "grade.txt";

enum subjects{
    english,
    math,
    science,
    history
};

typedef struct Student{
    int id;
    char name[50];
    int age;
    float gradeAvg;
} student;

typedef struct Grade{
    int id;
    int studentId; 
    float grade;
} grade;

// ALl methods to modify and read student table
student InsertStudent(student newStudent);
student UpdateStudent(student updatedStudent);
student GetStudent(int studentId);
void DeleteStudent(int studentId);
student* GetAllStudents(int size);

// All methods to modidy and read grade table
void InsertGrade(int studentId, float gradeId);
void DeleteGrade(int gradeId);
grade GetGrade(int gradeId);
grade* GetAllGrades(int size);

// General table modification methods
int LastIdFromTable(const char table[]);
void ReadTableRaw(const char table[]);
void SetLastId(const char table[], int id);
bool AskWhatTable(); // For logic questions.

int main(){
    
    system("cls");
    int command;

    printf("1. Read table raw\n");
    printf("2. Last Id From Table:\n");
    printf("Enter command:\n");
    scanf("%d", &command);

    switch(command){
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
    
void ReadTableRaw(const char table[]){
    FILE* tablePtr = fopen(table, "r");

    char tableContent[200];

    while(fgets(tableContent, 200, tablePtr)){
        printf("%s", tableContent);
    }

    fclose(tablePtr);
}

int LastIdFromTable(const char table[]){
    FILE* tablePtr = fopen(table, "r");

    int lastId = -1;
    while(fscanf(tablePtr, "%d", lastId) == 1)
    fclose(tablePtr);

    if(lastId == -1){
        SetLastId(table, 0);
        LastIdFromTable(table);
    }

    return lastId;
}

void SetLastId(const char table[], int id){
    FILE* tablePtr = fopen(table, "w");

    fprintf(tablePtr, "%d", id);

    fclose(tablePtr);
}

bool AskWhatTable(){
    system("cls");
    printf("1. student\n2. grade\nSelect a Table:\n");

    int selected = 0;
    scanf("%d", &selected);

    if(selected == 1)
        return true;
    else
        return false;
}


