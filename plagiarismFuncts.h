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
//#include<windows.h>

#define ANSWER_SIZE 2
#define MAX_FILENAME_LENGTH 255

#define RED "\033[31m"
#define GREEN "\033[92m"
#define YELLOW "\033[93m"
#define BLUE "\033[94m"
#define PINK "\033[95m"
#define WHITE "\033[0m"

typedef struct FileStruct{
    int max_size;
    int num_lines;
    char name[MAX_FILENAME_LENGTH];
    char** data_array;
}FileStruct;

FileStruct* createFileData(char *fileName);

char* trimBuffer(char* buffer);

int compileFileData(FILE *filePtr, FileStruct *file);

int testPlagiarism(FileStruct *file1, FileStruct *file2);

void freeCompiledFile(FileStruct *file);

#endif
