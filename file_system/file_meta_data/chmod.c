#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char*argv[]){
    if(argc != 2){
        puts("Arguments should be 2");
        exit(EXIT_FAILURE);
    }

    printf("File name: %s\n",argv[1]);
    if((chmod(argv[1],S_IRUSR | S_IWUSR)) < 0){
        perror("chmode()");
        exit(EXIT_FAILURE);
    }    
    puts("File permission changed to Read and write for USR ONLY");
    exit(EXIT_SUCCESS);
}