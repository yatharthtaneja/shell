#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    if(argc==1){
        while(1){
            char *input;
            gets(input);
            printf("%s\n",input);
        }
    }
    else if (argc==2)
    {
        FILE *fptr;
        char *line =NULL;
        size_t len=0;
        ssize_t read;
        fptr=fopen(argv[1],"r");

        if(fptr==NULL)
        {
            // perror("cat");
            printf("cat: no such file or directory\n");
            exit(EXIT_FAILURE);

        }
        while (read=getline(&line,&len,fptr)!=-1)
        {
            printf("%s",line);
            /* code */
        }
        fclose(fptr);
        if (line){
            free(line);
        }
    }

    else 
    {  int i=1;

        if ((strcmp(argv[1],"-n")==0))
        {
                for(int k=2;k<argc;k++){
        
        FILE *fptr;
        char *line =NULL;
        size_t len=0;
        ssize_t read;
        fptr=fopen(argv[k],"r");

        if(fptr==NULL)
        {
            printf("cat: no such file or directory");
            exit(EXIT_FAILURE);

        }
        
        if(k>2){
            read=getline(&line,&len,fptr);
            printf("%s",line);
        }
        while (read=getline(&line,&len,fptr)!=-1)
        {
            printf("\t%d %s",i++,line);

        }
        fclose(fptr);
        if (line){
            free(line);
        } 
          
        }
    }

        else if ((strcmp(argv[1],"-b")==0))
        {
        for(int k=2;k<argc;k++){
        
        FILE *fptr;
        char *line =NULL;
        size_t len=0;
        ssize_t read;
        fptr=fopen(argv[k],"r");

        if(fptr==NULL)
        {
            // perror("cat");
            printf("cat: no such file or directory\n");
            exit(EXIT_FAILURE);

        }
        if(k>2){
            read=getline(&line,&len,fptr);
            printf("%s",line);
        }
        
        while (read=getline(&line,&len,fptr)!=-1)
        {   
            if(strcmp(line,"\n")==0){
                printf("\n");
            }
            else
            {
                
            
            
            printf("\t%d %s",i++,line);
            }
            /* code */
        }
        fclose(fptr);
        if (line){
            free(line);
        } 
          
        }
    }

        else
        {
        FILE *fptr;
        char *line =NULL;
        size_t len=0;
        ssize_t read;
        fptr=fopen(argv[1],"r");
        i++;

        if(fptr==NULL)
        {
            // perror("cat");
            printf("cat: no such file or directory\n");
            exit(EXIT_FAILURE);

        }
        while (read=getline(&line,&len,fptr)!=-1)
        {
            printf("%s",line);
            /* code */
        }
        fclose(fptr);
        if (line){
            free(line);
        }
        for(int k=2;k<argc;k++){
                    FILE *fptr;
        char *line =NULL;
        size_t len=0;
        ssize_t read;
        fptr=fopen(argv[k],"r");
        i++;

        if(fptr==NULL)
        {
            // perror("cat");
            printf("cat: no such file or directory\n");
            exit(EXIT_FAILURE);

        }
        while (read=getline(&line,&len,fptr)!=-1)
        {
            printf("%s",line);
            /* code */
        }
        fclose(fptr);
        if (line){
            free(line);
        }
        }

        }
   
     }
    return 0;
}
