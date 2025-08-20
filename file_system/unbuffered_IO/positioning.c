#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int main(void){
    FILE* fp = NULL;
    fpos_t fpos;
    char buffer[BUFFER_SIZE];

    if((fp = fopen("/etc/passwd","r")) == NULL){
        perror("fopen()");
        exit(EXIT_FAILURE);
    }

    fgets(buffer,BUFFER_SIZE,fp);
    fputs(buffer,stdout);
    
    //here i didn't handel error using ferror or feof functions
    fgetpos(fp,&fpos);
    //we can invoke fsetpos to set the fpos offset 
    //but i didn't use here

    printf("now offset is: %02X\n",((unsigned char*)&fpos));
    fclose(fp);
    return 0;
}
