/*
Grace Cochran
COS 135 - Final Project
the defining of my project's functions
*/

#include "plagiarismFuncts.h"


// Given the name of the file, this method creates and allocates space for the data of the file.
FileStruct* createFileData(char *fileName){
    FileStruct *n = malloc(sizeof(FileStruct));
    
    n->max_size = ANSWER_SIZE;
    n->num_lines = 0;
    strcpy(n->name, fileName);
    n->data_array = malloc(sizeof(char*)*n->max_size);
}


// trims the end and beginning of a given buffer and returns a pointer to the trimmed buffer.
char* trimBuffer(char* buffr){
    // ending trim
    char *trimPtr = buffr + strlen(buffr)-1;
        while(isspace(*trimPtr)){ 
            trimPtr --;
        }
        *(trimPtr + 1) = 0;
        // beginning trim
        trimPtr = buffr; 
        while(isspace(*trimPtr)){ 
            trimPtr ++;
        }
    return trimPtr;
}


// takes the data of a given FILE pointer and puts it into a given FileStruct. Recompiles as necessary.
int compileFileData(FILE *filePtr, FileStruct *file){
    char buffer[1024];
    file->num_lines = 0;
    
    while(fgets(buffer, sizeof(buffer), filePtr) != NULL){
    // reallocation check:
        if (file->num_lines >= file->max_size){
    
            file->max_size *= 2;
            char** tempRe = realloc(file->data_array, sizeof(char*)*file->max_size);
            if (tempRe != NULL){ 
                file->data_array = tempRe;
            } else {
                printf("hey, reallocation failed");
                return 0;
           }
        } 
    // adding the actual line into the fileStruct's data:
    
        char* trimmed = trimBuffer(buffer);
        // test print of a line in file
        printf("The file contains: %s\n", trimmed);
        
        file->data_array[file->num_lines] = malloc(sizeof(buffer));
        strcpy(file->data_array[file->num_lines], trimmed);
        file->num_lines ++;
    }
    return 1;
}


// frees up the space of a given fileStruct
void freeCompiledFile(FileStruct *file){
    for(int i = 0; i < file->num_lines; i++){
        free(file->data_array[i]);
    }
    free(file->data_array);
    free(file);
}
