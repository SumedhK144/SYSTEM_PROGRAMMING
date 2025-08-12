#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char*argv[]){
    if(argc != 3){
        puts("Arguments should be 3");
        exit(EXIT_FAILURE);
    }

    if((symlink(argv[1],argv[2])) < 0){
        perror("symlink()");
        exit(EXIT_FAILURE);
    }

    printf("%s is linked symbolically to %s\n",argv[2],argv[1]);
    exit(EXIT_SUCCESS);

}
