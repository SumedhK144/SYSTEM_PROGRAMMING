#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    pid_t child_pid;

    if((child_pid = fork()) < 0){
        perror("fork()");
        exit(EXIT_FAILURE);
    }else if(child_pid == 0){
        printf("HEY I AM CHILD PROCESS MY PID: %d\tMy Parent PID: %d\n",getpid(),getppid());
    }
    else
        printf("I AM PARENT HA HA HA PID: %d\n",getpid());
    
    exit(EXIT_SUCCESS);
}
