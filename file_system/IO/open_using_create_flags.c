#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE  4096
#define MODE    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

int main(void){
    int fd,n;
    char buffer[BUFFER_SIZE];

    if((fd = open("by_create.txt",O_RDWR | O_CREAT | O_TRUNC, MODE)) == -1){
        perror("open()");
        exit(EXIT_FAILURE);
    }

    puts("-----Enter data to write on file------");
    while((n = read(STDIN_FILENO,buffer,BUFFER_SIZE)) > 0)
        write(fd,buffer,n);
    
    if(n < 0){
        perror("read()");
        exit(EXIT_FAILURE);
    }

    printf("\n");

    lseek(fd,SEEK_SET,0);
    puts("--------------------Data in file is---------------");
    while((n = read(fd,buffer,BUFFER_SIZE)) > 0)
        write(STDOUT_FILENO,buffer,n);
    
    if(n < 0){
        perror("read()");
        exit(EXIT_FAILURE);
    }
    close(fd);
    exit(EXIT_SUCCESS);
    
}
