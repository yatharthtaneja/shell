#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int is_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int main(int argc, char const *argv[])
{
    if (argc<=1)
    
    {
        printf("rm: missing operand\n");

    }
    else if (argc==2){
        if (strcmp(argv[1],"-d")==0 || strcmp(argv[1],"-i")==0)
        {
        printf("rm: missing operand\n");

        }
        else
        {
            if (is_file(argv[1])==1 && remove(argv[1])==0)
            {   printf("");
                
            }
            else
            {
                printf("Cannot Delete file or directory\n");
            }
            
            
        }
        
        
    }

    else if(argc==3){
        if (strcmp(argv[1],"-d")==0){
             
                if(remove(argv[2])==0){

            }
            else if (!opendir(argv[2]))
            {
                perror("No file or directory\n");
            }
                
            
            else
            {
                // perror("rm");
                printf("Not an empty directory\n");
            }
        
        }
        else if (strcmp(argv[1],"-i")==0){

              if (is_file(argv[2])==1)
                {
                printf("rm: remove regular file '%s'? ",argv[2]);
                char input[10];
                gets(input);
                if(input[0]=='y'|| input[0]=='Y'){

                remove(argv[2]);
                }
            }
                else
            {
                // perror("rm");
                printf("Not an empty directory\n");
            }
                    

            }      
            else
            {
                if (is_file(argv[1])==1 && remove(argv[1])==0)
                    {   printf("");
                        
                    }
                    else
                    {
                        printf("Cannot Delete file or directory\n");
                    }
                if (is_file(argv[2])==1 && remove(argv[2])==0)
            {   printf("");
                
            }
            else
            {
                printf("Cannot Delete file or directory\n");
            }
            }
             
        }             

        else
        {
           if ((strcmp(argv[1],"-d")==0) || (strcmp(argv[1],"-i")==0) ){

               if ((strcmp(argv[1],"-i")==0))
               {
                   for (int k=2;k<argc;k++)
                   {
                        if (is_file(argv[k])==1)
                        {
                        printf("rm: remove regular file '%s'? ",argv[k]);
                        char input[10];
                        gets(input);
                        if(input[0]=='y'|| input[0]=='Y'){

                        remove(argv[k]);
                        }
                        }
                            else
                        {
                            // perror("rm");
                            printf("Not an empty directory\n");
                        } 
                    }  
               }
               if ((strcmp(argv[1],"-d")==0)){
                    for(int k=2;k<argc;k++){
                            if(remove(argv[k])==0){

                            }
                            else if (!opendir(argv[k]))
                            {
                                perror("No file or directory\n");
                            }
                                
                            
                            else
                            {
                                // perror("rm");
                                printf("Not an empty directory\n");
                            }
                    }
               }
               else
               {
                   printf("Only -d or -i options allowed");
               }
               
               

           }
           else
           {
               for(int k=1;k<argc;k++){

                   if (is_file(argv[k])==1 && remove(argv[k])==0)
            {   printf("");
                
            }
            else
            {
                printf("Cannot Delete file or directory\n");
            }

               }
           }

        }    
    return 0;
}
