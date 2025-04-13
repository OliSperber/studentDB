#include "StudentLogic.h"
#include "gradeLogic.h"
#include "tableMod.h"
#include "TablePaths.h"

#include <stdio.h>


void InsertGrade(){
    // Generating new unique ID
    grade g = {
        .id = LastIdFromTable(GRADETABLE) + 1
    };

    // Asking for student Data
    printf("Enter grade data:\n<studentId> <Grade>\n");
    scanf("%d %f", &g.studentId , &g.grade);


    FILE* filePtr = fopen(GRADETABLE, "a");
    if(!filePtr){
        printf("Error opening file");
        return;
    }


    // inserting Data into Table
    fprintf(filePtr, "%d %f %d\n", g.id, g.grade, g.studentId);
    fclose(filePtr);

    // Updating lastId
    SetLastId(GRADETABLE, g.id);


    // Updating students AvgGrade
    UpdateStudentGrade(g.studentId, GetAvgGrade(g.studentId));
    
    // Returning the new student data
    printf("(New Grade)\nId:\t%d\ngrade:\t%f\nStudentId:\t%d", g.id, g.grade, g.studentId);

}

void DeleteGrade(){
    grade g;
    int IdToDelete;
    int sId;

    // Asking for student Id
    printf("Enter grade Id:\n<Id>\n");
    scanf("%d", &IdToDelete);


    FILE* filePtr = fopen(GRADETABLE, "r");
    FILE* tempFile = fopen("tempFile.txt", "w");
    if(!filePtr || !tempFile){
        printf("Error opening file");
        return;
    }

    // To skip the first line
    char buffer[256];
    fgets(buffer, sizeof(buffer), filePtr);
    fputs(buffer, tempFile);


    while(fscanf(filePtr, "%d %f %d", &g.id, &g.grade, &g.studentId) == 3){
        if (g.id != IdToDelete) fprintf(tempFile, "%d %f %d\n", g.id, g.grade, g.studentId);
        else sId = g.studentId;
    }

    fclose(filePtr);
    fclose(tempFile);

    remove(GRADETABLE);
    rename("tempFile.txt", GRADETABLE);
    
    UpdateStudentGrade(sId , GetAvgGrade(sId));

    printf("Succesfully deleted grade");
}

void GetGrade(){
    grade g;
    int id;

    // Asking for grade Id
    printf("Enter grade Id:\n<Id>\n");
    scanf("%d", &id);


    FILE* filePtr = fopen(GRADETABLE, "r");
    if(!filePtr){
        printf("Error opening file");
        return;
    }

    // To skip the first line
    char buffer[256];
    fgets(buffer, sizeof(buffer), filePtr);

    while(fscanf(filePtr, "%d %f %d", &g.id, &g.grade, &g.studentId) == 3){
        if(g.id == id)
            printf("-------------\nId:\t%d\nGrade:\t%f\nStudentId\t%d\n", g.id, g.grade, g.studentId);
    }

    fclose(filePtr);
}

void GetGradeOfStudent(){
    grade g;
    int id;

    // Asking for student Id
    printf("Enter student Id:\n<Id>\n");
    scanf("%d", &id);


    FILE* filePtr = fopen(GRADETABLE, "r");
    if(!filePtr){
        printf("Error opening file");
        return;
    }

    // To skip the first line
    char buffer[256];
    fgets(buffer, sizeof(buffer), filePtr);

    while(fscanf(filePtr, "%d %f %d", &g.id, &g.grade, &g.studentId) == 3){
        if(g.studentId == id)
            printf("-------------\nId:\t%d\nGrade:\t%f\nStudentId\t%d\n", g.id, g.grade, g.studentId);
    }

    fclose(filePtr);
}


void GetAllGrades(){
    grade g;

    FILE* filePtr = fopen(GRADETABLE, "r");
    if(!filePtr){
        printf("Error opening file");
        return;
    }
    // To skip the first line
    char buffer[256];
    fgets(buffer, sizeof(buffer), filePtr);

    while(fscanf(filePtr, "%d %f %d", &g.id, &g.grade, &g.studentId) == 3){
        printf("-------------\nId:\t%d\nGrade:\t%f\nStudentId\t%d\n", g.id, g.grade, g.studentId);
    }

    fclose(filePtr);
}

float GetAvgGrade(int studentId){
    grade g;
    float totalGrade = 0.0;
    int amountOfGrades = 0;

    FILE* filePtr = fopen(GRADETABLE, "r");
    if(!filePtr){
        printf("Error opening file");
        return 0.0;
    }

    // To skip the first line
    char buffer[256];
    fgets(buffer, sizeof(buffer), filePtr);

    while(fscanf(filePtr, "%d %f %d", &g.id, &g.grade, &g.studentId) == 3){
        if(g.studentId == studentId){
            amountOfGrades++;
            totalGrade += g.grade;
        }
    }

    fclose(filePtr);

    if(amountOfGrades == 0)
        return 0.0;

    return totalGrade / amountOfGrades;
}
