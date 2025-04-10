#ifndef STUDENTLOGIC_H
#define STUDENTLOGIC_H

#include <stdbool.h>

typedef struct Student
{
    int id;
    char name[50];
    int age;
    float gradeAvg;
} student;


void InsertStudent();
void UpdateStudent();
void UpdateStudentGrade(int studentId, float newGradeAvg);
void GetStudent();
void DeleteStudent();
void GetAllStudents();


#endif

