#include <stdio.h>
#include <stdlib.h>

int main(int argc,char*argv[]){
    FILE* fp = NULL;

    if((fp = fopen(argv[1],"r")) == NULL){
        perror("fopen()");
        exit(EXIT_FAILURE);
    }

    printf("%s file opened successfully using fopen() at ",argv[1]);
    printf("fd: %d\n",fp->_fileno);

    fclose(fp);
    exit(EXIT_SUCCESS);
}
// ./a.out file_name