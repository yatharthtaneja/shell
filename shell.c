#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int loop=1;
    int hist_index=0;
    char path[2000];
    char hist[1000][100];
    getcwd(path,sizeof(path));
    strcat(path,"/");

    while(loop==1){
        char command[100];
        char caller[2000];
        strcpy(caller,path);
        char currpath[2056];
        getcwd(currpath,sizeof(currpath));

       printf("\033[1;32m");
        printf("%s",currpath);
        printf("\033[0m"); 
        printf("$ ");
        gets(command);
        // puts(command);
        strcpy(hist[hist_index],command);
        hist_index++;

        int i=0;
        char *command_array[100];
        // puts(" check 1");
        command_array[i]=strtok(command," ");
        while (command_array[i]!=NULL)
        {   i++;
        // printf("hello");
            command_array[i]=strtok(NULL," ");
            
        }
        
        
        // exit command 
        // puts(command_array[0]);
        if(strcmp(command_array[0],"exit")==0){
            exit(0);
        }
        // cd command

        else if(strcmp(command_array[0],"cd")==0){
            if(i==2){
                if(strcmp(command_array[1],"~")==0){
                    chdir("/home");
                    char s[1000];
                    // printf("%s\n",getcwd(s,1000));
                }
                else
                {   
                    int check=0;
                    char curr[2000]; 
                    char *dirptr;
                    char s[1000];
                    dirptr=getcwd(curr,sizeof(curr));
                    char *dir;
                    if(strcmp(command_array[1],"..")==0){
                        check= chdir("..");
                    }
                    else
                    {
                       dir=strcat(dirptr,"/"); 
                    
                    
                    char *newdir;
                    newdir=strcat(dir,command_array[1]);
                    check=chdir(newdir);
                    }
                    if(check!=-1){
                        // printf("%s\n",getcwd(s,1000));
                    }
                    else
                    {
                        printf("\033[1;31m");
                        printf("Invalid Path\n");
                        printf("\033[0m");

                    }
                    
                    

                    
                }
                
            }
            else if(i==1){
                // corner case of only  cd takes you home.
                chdir("/home");
                char s[1000];
                printf("%s\n",getcwd(s,1000));
            }
            else
            {
                printf("More than 2 arguments\n");
            }
            
            
        }

        // cd command ends

        // echo command

        else if (strcmp(command_array[0],"echo")==0)
        {
            if(i==1){     // for a corner case of just using echo
                printf("\n");
                // puts("chal rha hai");
            }
                //  -n option
            else if(strcmp(command_array[1],"-n")==0){
                char message[10000]="";
                char finalmessage[10000]="";
                for (int k=2;command_array[k]!=NULL;k++){
                    strcat(message,command_array[k]);
                    strcat(message," ");
                }
                int index1=0;
                int pass=0;
                for(int k=0;k<strlen(message)-1;k++){
                        if(message[k]=='\"' || message[k]=="\'"){
                            pass=1;
                        }
                        else if(pass!=1 && message[k]=='\\'){
                            pass=0;
                        }
                        else
                        {
                            finalmessage[index1]= message[k];
                            index1++;
                        }         
                }
                printf("%s",finalmessage);

            }
            //  -e optionn
            else if(strcmp(command_array[1],"-e")==0){
                char message[10000]="";
                char finalmessage[10000]="";
                for (int k=2;command_array[k]!=NULL;k++){
                    strcat(message,command_array[k]);
                    strcat(message," ");
                }
                int index1=0;
                int pass=0;
                for(int k=0;k<strlen(message)-1;k++){
                        
                        if(pass==1 && message[k]=='\\' && message[k+1]=='n'){
                            printf("%s\n",finalmessage);
                            // strcpy(finalmessage,"");
                            memset(finalmessage,0,strlen(finalmessage));
                            // for(int j=0;j<strlen(finalmessage);j++){
                            //     finalmessage[j]="";
                            // }
                            index1=0;
                            k+=2;

                        }

                        if(pass==1 && message[k]=='\\' && message[k+1]=='b'){
                            printf("%s\b",finalmessage);
                            memset(finalmessage,0,strlen(finalmessage));

                            // for(int j=0;j<strlen(finalmessage);j++){
                            //     finalmessage[j]="";
                            // }
                            index1=0;
                            k+=2;

                        }

                        if(pass==1 && message[k]=='\\' && message[k+1]=='t'){
                            printf("%s\t",finalmessage);
                            // for(int j=0;j<strlen(finalmessage);j++){
                            //     finalmessage[j]="";
                            // }
                            memset(finalmessage,0,strlen(finalmessage));

                            index1=0;
                            k+=2;

                        }
                            if(pass==1 && message[k]=='\\' && message[k+1]=='\\'){
                            printf("%s\\",finalmessage);
                            // for(int j=0;j<strlen(finalmessage);j++){
                            //     finalmessage[j]="";
                            // }
                            memset(finalmessage,0,strlen(finalmessage));

                            index1=0;
                            k+=2;

                        }

                        if(message[k]=='\"' || message[k]=="\'"){
                            pass=1;
                            // printf("chal rha haii");
                        }
                        else if(pass!=1 && message[k]=='\\'){
                            pass=0;
                        }
                        else
                        {
                            finalmessage[index1]= message[k];
                            index1++;
                        }         
                }
                printf("%s\n",finalmessage);
            }
            else
            {
                char message[10000]="";
                char finalmessage[10000]="";
                for (int k=1;command_array[k]!=NULL;k++){
                    strcat(message,command_array[k]);
                    strcat(message," ");
                }
                int index1=0;
                int pass=0;
                for(int k=0;k<strlen(message)-1;k++){
                        if(message[k]=='\"' || message[k]=="\'"){
                            pass=1;
                        }

                        else if(pass!=1 && message[k]=='\\'){
                            pass=0;
                        }
                        else
                        {
                            finalmessage[index1]= message[k];
                            index1++;
                        }         
                }
                printf("%s\n",finalmessage);
            }
            
        }
        // echo command ends here.
        //  pwd command here.

        else if(strcmp(command_array[0],"pwd")==0){
            if(i==1){
                char cwd[2000];
                getcwd(cwd,sizeof(cwd));
                if(cwd==NULL){
                    printf("\033[1;31m");
                    printf("Error in director");
                    printf("\033[0m");
                }
                else
                {
                printf("%s\n",cwd);
                }
            }
            else if (i==2){
                if(strcmp(command_array[1],"-P")==0){

                char *cwd;
                cwd=getenv("PWD");
                // getcwd(cwd,sizeof(cwd));
                if(cwd==NULL){
                    printf("\033[1;31m");
                    printf("Error in directory");
                    printf("\033[0m");
                }
                else
                {
                printf("%s\n",cwd);
                }
                }
                else if(strcmp(command_array[1],"-L")==0){

                char cwd[2000];
                getcwd(cwd,sizeof(cwd));
                if(cwd==NULL){
                    printf("\033[1;31m");
                    printf("Error in directory");
                    printf("\033[0m");
                }
                else
                {
                    /* code */
                
                
                printf("%s\n",cwd);
                }
                }
                else
                {  
                printf("\033[1;31m");
                printf("Invalid Option\n");
                printf("\033[0m");
                }   
            }
            else
            {
                /* code */
            printf("\033[1;31m");
            printf("Invalid Option\n");
            printf("\033[0m");

            }          
        }
        // pwd ends here...
        else if(strcmp(command_array[0],"history")==0){
            if(i==1){
            for(int u=0;u<hist_index;u++){
                printf("%d %s\n",u+1,hist[u]);

                }
            }

            else if(i==2){
                    printf(command_array[2]);

                if(strcmp(command_array[1],"-c")==0)
                {
                    hist_index=0;
                    memset(hist,0,sizeof(hist));
                }
                else if(isdigit(command_array[1][0])==1){
                    int nu =atoi(command_array[1]);
                    for(int jk=hist_index-nu; jk<hist_index;jk++){
                        printf("%d %s\n",jk+1,hist[jk]);
                    }

                }
                else
                {
                    printf("Invalid Option\n");
                }
                
                }
                else if(i==3){
                if(strcmp(command_array[1],"-d")==0){
                    int x = atoi(command_array[2]);
                    if(x==0){
                        printf(" Invalid Input \n");
                    }
                    else if(x>hist_index){
                        printf("Input greater than History Index \n");
                    }
                    else{
                        for(int z=x-1;z<hist_index;z++){
                            strcpy(hist[z],hist[z+1]);
                        }
                        hist_index--;
                    }

                }
                else
                {
                    printf("Invalid input\n");
                }
                

            }
            else
            {
                printf("Error more than 3 arguments\n");
            }
            
        }
        // external commands 
        //  date command
        else if ( strcmp(command_array[0],"date")==0){
            // strcpy(caller,"/home/yatharth/Os/Assignment1/date");
            char binarypath[4096];
            strcpy(binarypath,path);
            strcat(binarypath,"date");
            // printf(binarypath);
            pid_t pid;
            pid=fork();
            if(pid==0){
                execv(binarypath,command_array);
            }
            else
            {
                waitpid(pid,NULL,0);
                continue;
            }
                        
        }
        //  date ends here 
        //  mkdir starts here 

        else if ( strcmp(command_array[0],"mkdir")==0){
            // strcpy(caller,"/home/yatharth/Os/Assignment1/date");
            char binarypath[4096];
            strcpy(binarypath,path);
            strcat(binarypath,"mkdir");
            // printf(binarypath);
            pid_t pid;
            pid=fork();
            if(pid==0){
                execv(binarypath,command_array);
            }
            else
            {
                waitpid(pid,NULL,0);
                continue;
            }
                        
        }
        // mkdir ends here
        //  ls starts here
        else if ( strcmp(command_array[0],"ls")==0){
            // strcpy(caller,"/home/yatharth/Os/Assignment1/date");
            char binarypath[4096];
            strcpy(binarypath,path);
            strcat(binarypath,"ls");
            // printf(binarypath);
            pid_t pid;
            pid=fork();
            if(pid==0){
                execv(binarypath,command_array);
            }
            else
            {
                waitpid(pid,NULL,0);
                continue;
            }
                        
        }
            else if ( strcmp(command_array[0],"rm")==0){
            // strcpy(caller,"/home/yatharth/Os/Assignment1/date");
            char binarypath[4096];
            strcpy(binarypath,path);
            strcat(binarypath,"rm");
            // printf(binarypath);
            pid_t pid;
            pid=fork();
            if(pid==0){
                execv(binarypath,command_array);
            }
            else
            {
                waitpid(pid,NULL,0);
                continue;
            }
                        
        }

            else if ( strcmp(command_array[0],"cat")==0){
            // strcpy(caller,"/home/yatharth/Os/Assignment1/date");
            char binarypath[4096];
            strcpy(binarypath,path);
            strcat(binarypath,"cat");
            // printf(binarypath);
            pid_t pid;
            pid=fork();
            if(pid==0){
                execv(binarypath,command_array);
            }
            else
            {
                waitpid(pid,NULL,0);
                continue;
            }
                        
        }
        else
        {
         printf("%s : command not found\n" , command_array[0]) ;   
        }
        


        // ls ends here

    }


    // while loop ends here 
}