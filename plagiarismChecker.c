/*

Grace Cochran
COS 135 - Final Project
main file of plagiarism checker

*/

#include "plagiarismFuncts.h"

int main(){
    
    
    
   
    printf("Welcome to the Plagiarism Checker! Please enter the name of the first file you want to compare: ");
    char nameBuffer[1024];
    char* nameTrim;
    FILE *filePtr1 = NULL;
    while(filePtr1 == NULL){
        fgets(nameBuffer, sizeof(nameBuffer), stdin);
        nameTrim = trimBuffer(nameBuffer);
        
        filePtr1 = fopen(nameTrim, "r"); 
        if (filePtr1 == NULL){
         printf("Couldn't open file. Please try putting in the file name again, as it may have been typed in incorrectly:\n");
        }
    }
    
    printf("File name sucessfully entered! Now, please enter the name of the second file you want to compare: ");
    char nameBuffer2[1024];
    char* nameTrim2;
    FILE *filePtr2 = NULL;
    while(filePtr2 == NULL){
        fgets(nameBuffer2, sizeof(nameBuffer2), stdin);
        nameTrim2 = trimBuffer(nameBuffer2);
        
        filePtr2 = fopen(nameTrim2, "r"); 
        if (filePtr2 == NULL){
         printf("Couldn't open file. Please try putting in the file name again, as it may have been typed in incorrectly:\n");
        }
    }
    
    
    FileStruct *firstFile = createFileData(nameTrim);
    printf("File 1 sucessfully created.\n");
    FileStruct *secondFile = createFileData(nameTrim2);
    printf("File 2 sucessfully created.\n");
    
    compileFileData(filePtr1, firstFile);
    printf("File 1 sucessfully compiled.\n");
    printf("===============================================\n");
    compileFileData(filePtr2, secondFile);
    printf("File 2 sucessfully compiled.\n");
    
    fclose(filePtr1);
    fclose(filePtr2);
    
    printf("===============================================\n");
    /*
    for(int i = 0; i < firstFile->num_lines; i++){
        printf("%s\n", firstFile->data_array[i]); 
    }
    */
    
    freeCompiledFile(firstFile);
    firstFile = NULL;
    freeCompiledFile(secondFile);
    secondFile = NULL;
    
    return 0;
}
