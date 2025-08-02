#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE     4096

char buffer[BUFFER_SIZE];


void display_contents(int);
void write_contents(int);

int main(void){
    int fd;
                        
    if((fd = open("demo.txt",O_RDWR)) == -1){
        perror("open()");
        exit(EXIT_FAILURE);
    }
    
    puts("-----Initail File contents-------");
    display_contents(fd);

    write_contents(fd);

    puts("------After writting -----------");
    display_contents(fd);
    
    close(fd);
    exit(EXIT_SUCCESS);
}


void display_contents(int fd){
    int n;
    off_t temp_offset = 0;

    while((n = pread(fd,buffer,BUFFER_SIZE,temp_offset)) >0){
        temp_offset += n;
        if(n < BUFFER_SIZE)
            buffer[n] = '\0';
        else
        buffer[BUFFER_SIZE - 1] = '\0';
        puts(buffer);
    }

    if(n < 0){
        perror("read()");
        exit(EXIT_FAILURE);
    }
}

void write_contents(int fd){
    off_t offset = lseek(fd,0,SEEK_END);
    int n,check;
    
    puts("--------Enter data in file(for stop press ctrl + d)-------");
    
    while((n = read(STDIN_FILENO,buffer,BUFFER_SIZE)) > 0){
        check = pwrite(fd,buffer,n,offset);
        if(check == -1){
            perror("pwrite()");
            exit(EXIT_FAILURE);
        }
        offset += n;
    }

    if(n < 0){
        perror("read()");
        exit(EXIT_FAILURE);
    }
}

