/*

Grace Cochran
COS 135 - Final Project
main file of plagiarism checker

*/

#include "plagiarismFuncts.h"

int main(){
    
    char* input;
    char inputBuffer[255] = "bluh";
    input = inputBuffer;
    char* goAgain;
    char againBuffer[255] = "pluh";
    goAgain = againBuffer;

    while(input[0] != '0' && goAgain[0] != 'n'){
    
        printf("\n");
        printf(YELLOW "Welcome to the Plagiarism Checker!\n");
        printf(WHITE "Enter " YELLOW "1" WHITE " to compare two files, or enter " YELLOW "0" WHITE " to quit the program.\n");
        printf("> ");
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
        input = trimBuffer(inputBuffer);

        // inputting 0 doesnt quit program plz help
        switch(input[0]){
            case '0':
                printf(YELLOW "Goodbye then! " WHITE "Closing program...\n");
                break;
            case '1':
                printf("Ok! Please enter the name of the first file you want to compare: ");
                char nameBuffer[1024];
                char* nameTrim;
                FILE *filePtr1 = NULL;
                while(filePtr1 == NULL){
                    fgets(nameBuffer, sizeof(nameBuffer), stdin);
                    nameTrim = trimBuffer(nameBuffer);
                    
                    filePtr1 = fopen(nameTrim, "r"); 
                    if (filePtr1 == NULL){
                    printf(RED "\nCouldn't open file. " WHITE "Please try putting in the file name again, as it may have been typed in incorrectly: ");
                    }
                }
                
                printf("\n");
                printf(GREEN "File name sucessfully entered!" WHITE " Now, please enter the name of the second file you want to compare: ");
                char nameBuffer2[1024];
                char* nameTrim2;
                FILE *filePtr2 = NULL;
                while(filePtr2 == NULL){
                    fgets(nameBuffer2, sizeof(nameBuffer2), stdin);
                    nameTrim2 = trimBuffer(nameBuffer2);
                    
                    filePtr2 = fopen(nameTrim2, "r"); 
                    if (filePtr2 == NULL){
                    printf(RED "\nCouldn't open file. " WHITE "Please try putting in the file name again, as it may have been typed in incorrectly: ");
                    }
                }
                
                printf("\n");
                FileStruct *firstFile = createFileData(nameTrim);
                printf(GREEN "File 1 sucessfully created.\n");
                FileStruct *secondFile = createFileData(nameTrim2);
                printf("File 2 sucessfully created.\n\n");
                
                printf(YELLOW "File 1 contains:" WHITE "\n");
                compileFileData(filePtr1, firstFile);
                printf("\n");
                printf(GREEN "File 1 data successfully stored." WHITE "\n");
                printf("===============================================\n\n");
                printf(YELLOW "File 2 contains:" WHITE "\n");
                compileFileData(filePtr2, secondFile);
                printf("\n");
                printf(GREEN "File 2 data successfully stored.\n");
                
                fclose(filePtr1);
                fclose(filePtr2);
                
                printf(WHITE"===============================================\n\n");
                printf(YELLOW "Testing for plagiarism...\n");
                
                int result = testPlagiarism(firstFile, secondFile);
                if(result == 0){
                    printf(GREEN "No matching lines were found!" WHITE " Your files look plagiarism-free.\n\n");
                } else if(result == 1){
                    printf(RED "%d matching line was found." WHITE " Please consider reexamining your files, as there may be some plagiarism in your work.\n\n", result);
                } else {
                    printf(RED "%d matching lines were found." WHITE " Please consider reexamining your files, as there may be some plagiarism in your work.\n\n", result);
                }
                
                freeCompiledFile(firstFile);
                firstFile = NULL;
                freeCompiledFile(secondFile);
                secondFile = NULL;

                printf("Do you want to run the program again? y/n\n");
                printf(YELLOW "Note: Please enter your input in lowercase\n");
                printf(WHITE "> ");
                fgets(againBuffer, sizeof(againBuffer), stdin);
                goAgain = trimBuffer(againBuffer);
                

                switch(goAgain[0]){
                    case 'n':
                        printf(YELLOW "Goodbye then! " WHITE "Closing program...\n");
                }
        }
    }

    return 0;
}
