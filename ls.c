#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<dirent.h>

int main(int argc, char* argv[]){
    struct dirent** filelist;
    if(argc==1){
        char cwd[2056];
        char result;
        if (getcwd(cwd,sizeof(cwd))==NULL)
        {
            perror("Error ");
            /* code */
            exit(0);
        }
        int totalfiles=scandir(cwd,&filelist,NULL,alphasort);
        for(int i=0;i<totalfiles;i++){
            char *fname= filelist[i]->d_name;
            if (strcmp(filelist[i]->d_name,".")!=0 && strcmp(filelist[i]->d_name,"..")!=0)
            {   
                if(fname[0]!="."){
                    printf("%-2s  ",filelist[i]->d_name);
                }
                /* code */
            }            
        }
        if(totalfiles!=0){
            printf("\n");
        }
        
    }
    else if(argc==2){

        if(strcmp(argv[1],"-a")==0){
        char cwd[2056];
        char result;
        if (getcwd(cwd,sizeof(cwd))==NULL)
        {
            perror("Error ");
            /* code */
            exit(0);
        }
        int totalfiles=scandir(cwd,&filelist,NULL,alphasort);
        for(int i=0;i<totalfiles;i++){
            char *fname= filelist[i]->d_name;
                    printf("%-2s  ",filelist[i]->d_name);
        }
        if(totalfiles!=0){
            printf("\n");
        }

     }
        else if(strcmp(argv[1],"-1")==0){
        char cwd[2056];
        char result;
        if (getcwd(cwd,sizeof(cwd))==NULL)
        {
            perror("Error ");
            /* code */
            exit(0);
        }
        int totalfiles=scandir(cwd,&filelist,NULL,alphasort);
        for(int i=0;i<totalfiles;i++){
                 char *fname= filelist[i]->d_name;
            if (strcmp(filelist[i]->d_name,".")!=0 && strcmp(filelist[i]->d_name,"..")!=0)
            {   
                if(fname[0]!="."){
                    printf("%-2s\n",filelist[i]->d_name);
                }
                /* code */
            }
        }
     }
        else
        {
            if(chdir(argv[1])==0){

        char cwd[2056];
        char result;
        if (getcwd(cwd,sizeof(cwd))==NULL)
        {
            perror("Error ");
            /* code */
            exit(0);
        }
        int totalfiles=scandir(cwd,&filelist,NULL,alphasort);
        for(int i=0;i<totalfiles;i++){
            char *fname= filelist[i]->d_name;
            if (strcmp(filelist[i]->d_name,".")!=0 && strcmp(filelist[i]->d_name,"..")!=0)
            {   
                if(fname[0]!="."){
                    printf("%-2s  ",filelist[i]->d_name);
                }
                /* code */
            }            
        }
        if(totalfiles!=0){
            printf("\n");
        }


            }
            else
            {
                printf("Directory doesn't exist\n");
            }
            
        }
    }
        
    //  ls file
    else if(argc="3"){

        if(strcmp(argv[1],"-a")==0){
            if(chdir(argv[2])==0){
        char cwd[2056];
        char result;
        if (getcwd(cwd,sizeof(cwd))==NULL)
        {
            perror("Error ");
            /* code */
            exit(0);
        }
        int totalfiles=scandir(cwd,&filelist,NULL,alphasort);
        for(int i=0;i<totalfiles;i++){
            char *fname= filelist[i]->d_name;
                    printf("%-2s  ",filelist[i]->d_name);
        }
        if(totalfiles!=0){
            printf("\n");
        }
            }
            else
            {
                printf("Directory doesn't exist\n");
            }
     }
        else if(strcmp(argv[1],"-1")==0){
            if(chdir(argv[2])==0){
        char cwd[2056];
        char result;
        if (getcwd(cwd,sizeof(cwd))==NULL)
        {
            perror("Error ");
            /* code */
            exit(0);
        }
        int totalfiles=scandir(cwd,&filelist,NULL,alphasort);
        for(int i=0;i<totalfiles;i++){
                 char *fname= filelist[i]->d_name;
            if (strcmp(filelist[i]->d_name,".")!=0 && strcmp(filelist[i]->d_name,"..")!=0)
            {   
                if(fname[0]!="."){
                    printf("%-2s\n",filelist[i]->d_name);
                }
                /* code */
            }
        }
        }
        else
            {
                printf("Directory doesn't exist\n");
            }
        }


    }
     

return(0);
}