#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE     4096

int main(void){
    int src_fd,dest_fd;
    int n;
    char buffer[BUFFER_SIZE];

    if((src_fd = open("demo.txt",O_RDONLY)) == -1){
        puts("error:src open()");
        exit(EXIT_FAILURE);
    }

    if((dest_fd = open("dest.txt",O_WRONLY)) == -1){
        puts("error:dest open()");
        exit(EXIT_FAILURE);
    }

    while((n = read(src_fd,buffer,BUFFER_SIZE)) > 0)
        write(dest_fd,buffer,n);

    if(n < 0){
        puts("error:src read()");
        exit(EXIT_FAILURE);
    }

    puts("----FILES COPIED SUCCESSFULLY-------");
    close(src_fd);
    close(dest_fd);

    exit(EXIT_SUCCESS);
}
