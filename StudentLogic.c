#include "StudentLogic.h"
#include "tableMod.h"
#include "TablePaths.h"

#include <stdio.h>

void InsertStudent(){
    // Generating new unique ID
    student newStudent = {
        .id = LastIdFromTable(STUDENTTABLE) + 1
    };

    // Asking for student Data
    printf("Enter student data:\n<Name> <Age>");
    scanf("%s %d", newStudent.name, &newStudent.age);

    // Opening table file
    FILE* filePtr = fopen(STUDENTTABLE, "a");
    if(filePtr == NULL){
        perror("error opening file");
        return;
    }

    // inserting Data into Table
    fprintf(filePtr, "%d %s %d %f", newStudent.id, newStudent.name, newStudent.age, 0.0);
    fclose(filePtr);

    // Updating lastId
    SetLastId(STUDENTTABLE, newStudent.id);
    
    // Returning the new student data
    printf("(New Student)\nId:\t%d\nName:\t%s\nAge:\t%d", newStudent.id, newStudent.name, newStudent.age);

}

void UpdateStudent(){

    int IdToDelete;
    student s;
    student sInput;

    // Asking for student Data
    printf("Enter student data:\n<Name> <Age>");
    scanf("%d, %s %d", &sInput.id, sInput.name, &sInput.age);

    // Opening table file
    FILE* filePtr = fopen(STUDENTTABLE, "r");
    FILE* tempFile = fopen("tempFile.txt", "w");
    if(!filePtr || !tempFile){
        perror("error opening file");
        return;
    }

    // To skip the first line
    char buffer[256];
    fgets(buffer, sizeof(buffer), filePtr);
    fputs(buffer, tempFile);

    //scanning for student with given id
    while(fscanf(filePtr, "%d %s %d %f", &s.id, s.name, &s.age, &s.gradeAvg) == 4){
        if(s.id != sInput.id)
            fprintf(tempFile, "%d %s %d %f\n", s.id, s.name, s.age, s.gradeAvg);
        else
            fprintf(tempFile, "%d %s %d %f\n", s.id, sInput.name, sInput.age, s.gradeAvg);
    }
    
    fclose(filePtr);
    fclose(tempFile);

    remove(STUDENTTABLE);
    rename("tempFile.txt", STUDENTTABLE);
}

void GetStudent(){
    int id;
    student studentSearch;

    // Asking for student Id
    printf("Enter student Id:\n<Id>");
    scanf("%d", &id);

    // Opening table file
    FILE* filePtr = fopen(STUDENTTABLE, "r");
    if(!filePtr){
        perror("error opening file");
        return;
    }

    // To skip the first line
    char buffer[256];
    fgets(buffer, sizeof(buffer), filePtr);

    //scanning for student with given id
    while(fscanf(filePtr, "%d %s %d %f", &studentSearch.id, studentSearch.name, &studentSearch.age, &studentSearch.gradeAvg) == 4){
        if(studentSearch.id == id){
            printf("(New Student)\nId:\t%d\nName:\t%s\nAge:\t%d\nGradeAvg:\t%f", studentSearch.id, studentSearch.name, studentSearch.age, studentSearch.gradeAvg);
            fclose(filePtr);
            return;
        }
    }
    fclose(filePtr);

    //This code reaches if student with id is not found
    printf("No student with a id of '%d' is found", id);
}

void DeleteStudent(){
    int IdToDelete;
    student s;

    // Asking for student Id
    printf("Enter student Id:\n<Id>");
    scanf("%d", &IdToDelete);

    // Opening table file
    FILE* filePtr = fopen(STUDENTTABLE, "r");
    FILE* tempFile = fopen("tempFile.txt", "w");
    if(!filePtr || !tempFile){
        perror("error opening file");
        return;
    }

    // To skip the first line
    char buffer[256];
    fgets(buffer, sizeof(buffer), filePtr);
    fputs(buffer, tempFile);

    //scanning for student with given id
    while(fscanf(filePtr, "%d %s %d %f", &s.id, s.name, &s.age, &s.gradeAvg) == 4){
        if(s.id != IdToDelete)
            fprintf(tempFile, "%d %s %d %f\n", s.id, s.name, s.age, s.gradeAvg);
    }
    
    fclose(filePtr);
    fclose(tempFile);

    remove(STUDENTTABLE);
    rename("tempFile.txt", STUDENTTABLE);

}

void GetAllStudents(){
    student s;

    // Opening table file
    FILE* filePtr = fopen(STUDENTTABLE, "r");
    if(!filePtr){
        perror("error opening file");
        return;
    }

    // To skip the first line
    char buffer[256];
    fgets(buffer, sizeof(buffer), filePtr);

    //scanning for student with given id
    while(fscanf(filePtr, "%d %s %d %f", &s.id, s.name, &s.age, &s.gradeAvg) == 4){
        printf("---------------------------------\nId:\t%d\nName:\t%s\nAge:\t%d\nGradeAvg:\t%f\n", s.id, s.name, s.age, s.gradeAvg);
    }
    
    fclose(filePtr);

}

