//faccessat is same as access but instaed of pathname we give fd
//for open file it is used.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define TRUE    1

void check_existance(char* file_name);
void check_read(char* file_name);
void check_write(char* file_name);
void check_execute(char* file_name);

void (*ptr[4])(char*);

//How To Optimize this code
//I mean how should i minimize this code
//I will Imporve in further codes

int main(int argc,char* argv[]){
    if(argc != 2){
        puts("Arguments should be 2");
        exit(EXIT_FAILURE);
    }
    
    int response;
    ptr[0] = check_existance;
    ptr[1] = check_read;
    ptr[2] = check_write;
    ptr[3] = check_execute;

    while(TRUE){
        printf("File Name: %s\n",argv[1]);
        puts("1->Existance\n2->Read\n3->Write\n4->Execute\n5->EXIT");
        printf("Enter Your Response for File Check: ");
        scanf("%d",&response);

        if(response == 5){
            puts("---PROGRAMME TERMINATED SUCCESSFULLY---");
            exit(EXIT_SUCCESS);
        }else if(response >= 1 & response <= 4)
                ptr[response - 1](argv[1]);
        else
            puts("Invalid Choice. Try again");
    }

    return 0;
}

void check_existance(char* file_name){
    if((access(file_name,F_OK)) < 0)
        puts("File doesn't Exists");
    else
        puts("File EXISTS!!");
}

void check_read(char* file_name){
    if((access(file_name,R_OK)) < 0)
        puts("Unable to READ");
    else
        puts("Able to READ");
}

void check_write(char* file_name){
    if((access(file_name,W_OK)) < 0)
        puts("Unable to WRITE");
    else
        puts("Able to WRITE");
}

void check_execute(char* file_name){
    if((access(file_name,X_OK)) < 0)
        puts("Unable to Execute");
    else
        puts("Able to Execute");
}