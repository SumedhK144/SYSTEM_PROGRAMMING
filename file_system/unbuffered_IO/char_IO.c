#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    FILE *fp = NULL;
    int c;

    fp = fopen(argv[1],"r");
    if(fp == NULL){
        perror("fopen()");
        exit(EXIT_FAILURE);
    }

    while((c = fgetc(fp)) != EOF)
        fputc(c,stdout);

    printf("\n");

    fclose(fp);
    exit(EXIT_SUCCESS);
}

//  ./a.out file_name