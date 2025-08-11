#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char* argv[]){
    if(argc != 2){
        puts("Arguments should be 2");
        exit(EXIT_FAILURE);
    }

    if((unlink(argv[1])) < 0){
        perror("unlink()");
        exit(EXIT_FAILURE);
    }

    printf("%s file unlinked successfully.\n",argv[1]);
    exit(EXIT_SUCCESS);
}
// execute command as follows
//                  ./a.out unlink_file_name
