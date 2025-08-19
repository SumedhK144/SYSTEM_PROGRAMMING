#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc,char* argv[]){
    DIR *dp = NULL;
    struct dirent *dip = NULL;

    for(int i = 1; i < argc; i++){
        printf("----------------------DIR NAME: %s------------------\n",argv[i]);
        
        if((dp = opendir(argv[i])) == NULL){
            perror("opendir()");
            exit(EXIT_FAILURE);
        }

        while((dip = readdir(dp)) != NULL)
            printf("entry name:%-30sinode no:%-10d\n",dip->d_name,dip->d_ino);

        closedir(dp);
    }

    exit(EXIT_SUCCESS);

}
