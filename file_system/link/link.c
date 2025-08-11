#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char* argv[]){
    if(argc != 3){
        puts("Arguments should be 3");
        exit(EXIT_FAILURE);
    }

    if((link(argv[1],argv[2])) < 0){
        perror("link()");
        exit(EXIT_FAILURE);
    }

    printf("links created successfully %s -> %s\n",argv[2],argv[1]);
    exit(EXIT_SUCCESS);
}
//execute command as follow
//      ./a.out existing_path new_path
