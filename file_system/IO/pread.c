#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE     4096

int main(void){
    int fd,n;
    char buffer[BUFFER_SIZE];
    off_t offset = 500;

    if((fd = open("/etc/passwd",O_RDONLY)) == -1){
        perror("open()");
        exit(EXIT_FAILURE);
    }

    while((n = pread(fd,buffer,BUFFER_SIZE,offset)) > 0){
            buffer[n] = '\0';
            puts(buffer);
            offset += n;
    }

    if(n < 0){
        perror("pread()");
        exit(EXIT_FAILURE);
    }

    close(fd);
    exit(EXIT_SUCCESS);
}
