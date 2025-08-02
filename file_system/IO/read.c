#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE     4096

int main(void){
    int fd,n;
    char buffer[BUFFER_SIZE];

    if((fd = open("demo.txt",O_RDONLY)) == -1){
        puts("Error:open()");
        exit(EXIT_FAILURE);
    }
        
    while((n = read(fd,buffer,BUFFER_SIZE)) > 0){
            buffer[n] = '\0';
            puts(buffer);
    }

    if(n < 0){
        puts("Error:read()");
        exit(EXIT_FAILURE);
    }

    close(fd);
    exit(EXIT_SUCCESS);

}
