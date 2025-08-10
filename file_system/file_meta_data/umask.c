#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MODE    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

int main(void){
    
    int fd1,fd2;
    
    umask(0);
    if((fd1 = open("neo.txt",O_CREAT | O_RDWR | O_TRUNC,MODE)) < 0){
        perror("open()");
        exit(EXIT_FAILURE);
    }

    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if((fd2 = open("lee.txt",O_CREAT | O_RDWR | O_TRUNC,MODE)) < 0){
        perror("open():lee");
        exit(EXIT_FAILURE);
    }
    
    puts("Both Files created Successfully check their permissions using ls -l command");
    close(fd1);
    close(fd2);
    
    exit(EXIT_SUCCESS);
    
}
