//int rename(const char* oldname,const char* newname)
//this Fucntion is defined by ISO C

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
    if(argc != 3){
        puts("Arguments should be 3");
        exit(EXIT_FAILURE);
    }

    if((rename(argv[1],argv[2])) < 0){
        perror("rename()");
        exit(EXIT_FAILURE);
    }

    printf("%s is renamed sucessfully to %s.\n",argv[1],argv[2]);
    exit(EXIT_SUCCESS);
}

//execute command as
//      ./a.out old_file_name new_file_name
