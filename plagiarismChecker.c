/*

Grace Cochran
COS 135 - Final Project
main file of plagiarism checker

*/

#include "plagiarismFuncts.h"

int main(){
    
    
   
    printf("Ok! Please enter the name of the first file you want to compare: ");
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
    
    printf("\n");
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
    
    printf("\n");
    FileStruct *firstFile = createFileData(nameTrim);
    printf("File 1 sucessfully created.\n");
    FileStruct *secondFile = createFileData(nameTrim2);
    printf("File 2 sucessfully created.\n\n");
    
    printf("File 1 contains:\n");
    compileFileData(filePtr1, firstFile);
    printf("File 1 data successfully stored.\n\n");
    printf("===============================================\n\n");
    printf("File 2 contains:\n");
    compileFileData(filePtr2, secondFile);
    printf("File 2 data successfully stored.\n\n");
    
    fclose(filePtr1);
    fclose(filePtr2);
    
    printf("===============================================\n\n");
    printf("Testing for plagiarism...\n");
    
    int result = testPlagiarism(firstFile, secondFile);
    if(result == 0){
        printf("No matching lines were found! Your files look plagiarism-free.\n");
    } else if(result == 1){
        printf("%d matching line was found. Please consider reexamining your files, as there may be some plagiarism in your work.\n", result);
    } else {
        printf("%d matching lines were found. Please consider reexamining your files, as there may be some plagiarism in your work.\n", result);
    }
    
    freeCompiledFile(firstFile);
    firstFile = NULL;
    freeCompiledFile(secondFile);
    secondFile = NULL;
    
    return 0;
}
