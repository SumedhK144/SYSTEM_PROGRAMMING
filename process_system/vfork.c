//vfork is the funciton same as a fork and it is used to exec a new program
//in vfork the child process runs in parent address space so that's why
//changes made in child variables also reflects in parent varaibles

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int gvar = 99;

int main(void){
    pid_t pid;
    int lvar;

    lvar = 9;
    if((pid = vfork()) < 0){
        perror("vfork()");
        exit(EXIT_FAILURE);
    }else if(pid == 0){
        lvar++;
        gvar++;
        _exit(0);
    }

    printf("pid = %-10ld gvar = %-10d lvar = %-15d\n",pid,gvar,lvar);
    exit(EXIT_SUCCESS);
}