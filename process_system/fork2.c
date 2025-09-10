//this code is for understanding how the copies of parent proccess shared to child
//hence fork() it create the copies of data,stack,heap and share to child
//so changes made inside the child process variable dosen't reflect in parent process variable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int gvar = 99;

int main(void){
    pid_t pid;
    int lvar;

    lvar = 9;
    if((pid = fork()) < 0){
        perror("fork()");
        exit(EXIT_FAILURE);
    }else if(pid == 0){
        gvar++;
        lvar++;
    }
    
  
    printf("pid = %-10ld gvar = %-10d lvar = %-15d\n",pid,gvar,lvar);

    
    exit(EXIT_SUCCESS);
}
