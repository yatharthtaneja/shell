#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<time.h>

int main(int argc, char* argv[]){
    time_t t1=time(NULL);
    time_t t2=time(NULL);
    struct tm* local;
    struct tm* gmt;
    local = localtime(&t1);
    gmt = gmtime(&t2);
    char s[100];
    char s1[100];
    strftime(s,sizeof(s),"%c",local);
    strftime(s1,sizeof(s1),"%c",gmt);
    if(argc==1){
        
        printf("%s\n",s);
    }
    else if(argc==2){
        if (strcmp(argv[1],"-I")==0){
            printf("%d-%d-%d\n",local-> tm_year+1900,local->tm_mon+1,local->tm_mday);
        }

        else if(strcmp(argv[1],"-u")==0){
        printf("%s\n",s1);

        }

        else if(strcmp(argv[1],"+%a")==0){
            char *arg[10];
            int i=0;
            arg[i]=strtok(s," ");

            while (arg[i]!=NULL)
            {   i++;
                /* code */
                arg[i]=strtok(NULL," ");
            }
            printf("%s\n",arg[0]);
            
        }

        else if(strcmp(argv[1],"+%b")==0){
            char *arg[10];
            int i=0;
            arg[i]=strtok(s," ");

            while (arg[i]!=NULL)
            {   i++;
                /* code */
                arg[i]=strtok(NULL," ");
            }
            printf("%s\n",arg[1]);            
        }
        else
        {
            printf("Error invalid input: only -I , +%b and +%a allowed ");
        }
    }
    else
    {
        /* code */
        printf("Error invalid input too many operands");
    }
    

    return(0);
}