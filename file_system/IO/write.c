#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE     4096

int main(void){
    int fd,n;
    char buffer[BUFFER_SIZE];

    fd = open("new.txt",O_WRONLY);
    if(fd == -1){
        puts("Error:open()");
        exit(EXIT_FAILURE);
    }

   puts("------Enter text (to stop press ctrl + d)--------------"); //ctrl + d to stop
   while((n = read(STDIN_FILENO,buffer,BUFFER_SIZE)) > 0)
       write(fd,buffer,n);

   if(n < 0){
       puts("Error:read()");
       exit(EXIT_FAILURE);
   }

   close(fd);
   exit(EXIT_SUCCESS);
}
