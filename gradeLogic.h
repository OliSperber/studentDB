#ifndef GRADELOGIC_H
#define GRADELOGIC_H

typedef struct Grade
{
    int id;
    int studentId;
    float grade;
} grade;


// All methods to modidy and read grade table
void InsertGrade();
void DeleteGrade();
void GetGrade();
void GetGradeOfStudent();
void GetAllGrades();
float GetAvgGrade(int studentId);

#endif
