#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int main(void){
    FILE* fp = NULL;
    char buffer[BUFFER_SIZE];

    if((fp = fopen("output.txt","w")) == NULL){
        perror("fopen()");
        exit(EXIT_FAILURE);
    }

    puts("------------ENTER DATA HERE---------");
    while((fgets(buffer,BUFFER_SIZE,stdin)) != NULL)
        fputs(buffer,fp);           //while dealing with fgets and fputs 
                                    // we have to be concern about newline character
                                    //both functions doesn't add newline character at the end
                                    //of the file

    if(ferror(stdin)){
        perror("ferror()");
        exit(EXIT_FAILURE);
    }

    puts("----------DATA WRITTEN SUCCESSFULLY----------");
    fclose(fp);

    exit(EXIT_SUCCESS);
}