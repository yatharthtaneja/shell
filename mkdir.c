#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    int result;
    if(argc==2){
        result=mkdir(argv[1],0777);
        if (result==-1)
        {
            // printf("Error failed to create directory\n");
            perror("Error");
            /* code */
        }
    }
    else if(argc==3){
        if (strcmp(argv[1],"-p")==0)
        {   
            char *arg= strtok(argv[2],"/");
            int p=0;
            char cwd[2056];
            char *argc[256];
            while (arg!=NULL)
            {
                argc[p] = arg;
                arg= strtok(NULL,"/");
                p++;
                /* code */
            }
            for(int j=0;j<p;j++){
                result=mkdir(argc[j],0777);
                if(result==-1){
            // printf("Error failed to create directory\n");
            perror("Unable to open file ");
            /* code */
                }
            chdir(argc[j]);

            }
        }
         else if (strcmp(argv[1],"-v")==0){
            
               result=mkdir(argv[2],0777);
                if (result==-1)
                {
                    printf("Error Directory already exists\n");
                    /* code */
                }
                else
                {
                    printf("mkdir: Created directory '%s'\n",argv[2]);
                }
        
         }
         else if(mkdir(argv[1],0777)!=-1){
             result=mkdir(argv[2],0777);
                if (result==-1)
                {
            // printf("Error failed to create directory\n");
                perror("Unable to open file ");
            /* code */
                }
         }
        else
        {
            printf("Invalid options use only -v and -p \n");

        }    
    }
    else if(argc==1){

        printf("mkdir: missing operand\n");
    }
    else
    {
        if(strcmp(argv[1],"-v")==0 || strcmp(argv[1],"-p")==0){
            if(strcmp(argv[1],"-v")==0 )
            {
                for(int k=2;k<argc;k++){

                   result=mkdir(argv[k],0777);
                if (result==-1)
                {
                    printf("Error Directory already exists\n");
                    /* code */
                }
                else
                {
                    printf("mkdir: Created directory '%s'\n",argv[k]);
                } 

                }
            }
            if(strcmp(argv[1],"-p")==0){
                for(int k=2;k<argc;k++){
                    char *arg= strtok(argv[k],"/");
            int p=0;
            char cwd[2056];
            char *argc[256];
            while (arg!=NULL)
            {
                argc[p] = arg;
                arg= strtok(NULL,"/");
                p++;
                /* code */
            }
            for(int j=0;j<p;j++){
                result=mkdir(argc[j],0777);
                if(result==-1){
            // printf("Error failed to create directory\n");
            perror("mkdir: ");
            /* code */
                }
            chdir(argc[j]);

            }
                }

            }  

        }
        else
        {
     
        for(int k=1;k<argc;k++){

        result=mkdir(argv[k],0777);
        if (result==-1)
        {
            // printf("Error failed to create directory\n");
            perror("Error");
            /* code */
        }

            }
        }
    }
    

return(0);
}