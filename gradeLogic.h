#ifndef GRADELOGIC_H
#define GRADELOGIC_H

typedef struct Grade
{
    int id;
    int studentId;
    float grade;
} grade;


// All methods to modidy and read grade table
void InsertGrade(int studentId, float gradeId);
void DeleteGrade(int gradeId);
grade GetGrade(int gradeId);
grade *GetAllGrades(int size);

#endif
