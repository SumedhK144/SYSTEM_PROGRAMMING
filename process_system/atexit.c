#include <stdio.h>
#include <stdlib.h>

void func1(void);       //exit handler 1
void func2(void);       //exit handler 2

//atexit() is used to register exit handlers if exit() called
//all exit handler registered will exicute as the sequence have registered.

int main(void){
    if((atexit(func1)) < 0)
        perror("atexit");

    if((atexit(func2)) < 0)
        perror("atexit");

    if((atexit(func1)) < 0)
        perror("atexit");

    puts("Lets see how the exit handlers executes");
    exit(EXIT_SUCCESS);
}

void func1(void){
    puts("THIS IS FUNCTION 1");
}

void func2(void){
    puts("THIS IS FUNCTION 2");
}