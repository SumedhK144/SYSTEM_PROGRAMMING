#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc,char* argv[]){
    if(argc != 2){
        puts("Enter only 2 arguments(including exe filename");
        exit(EXIT_FAILURE);
    }

    int status;
    struct stat buffer;
    
    status = stat(argv[1],&buffer);
    if(status == -1){
        perror("stat()");
        exit(EXIT_FAILURE);
    }

    printf("User id: %ld\n",buffer.st_uid);
    printf("Permissions: %o\n",buffer.st_mode & 0777);
    printf("Inode: %d\n",buffer.st_ino);

    exit(EXIT_SUCCESS);
}
