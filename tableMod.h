#ifndef TABLEMOD_H
#define TABLEMOD_H

#include <stdbool.h>

void ReadTableRaw(const char table[]);

int LastIdFromTable(const char table[]);

void SetLastId(const char table[], int id);

bool AskWhatTable();

#endif