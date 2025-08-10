#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(void){    
    if((chown("own.txt",1001,1001)) < 0){   //here 1001 is assigned to another user in my OS
        puts("Error in chown");
        exit(EXIT_FAILURE);
    }

    puts("-----UID and GUID is Changed to anaother user------");
    exit(EXIT_SUCCESS);
}

//run programm using sudo command 
