/*
Grace Cochran
COS 135 - Final Project
the declaration of my project's functions
*/

#ifndef PLAGIARISM_FUNCTIONS_H
#define PLAGIARISM_FUNCTIONS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define ANSWER_SIZE 2
#define MAX_FILENAME_LENGTH 255

typedef struct FileStruct{
    int max_size;
    int num_lines;
    char name[MAX_FILENAME_LENGTH];
    char** data_array;
}FileStruct;

FileStruct* createFileData(char *fileName);

char* trimBuffer(char* buffer);

int compileFileData(FILE *filePtr, FileStruct *file);

void freeCompiledFile(FileStruct *file);

#endif
