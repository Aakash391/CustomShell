#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
void mkdir_func(char mkdirinput[]){
    char option[30]="";
    char option2[30]="";
    char nooption[30]="";
    // fgets(mkdirinput,60,stdin);
    int ln=strlen(mkdirinput);
    mkdirinput[ln-1]='\0';

    for(int i=6;i<8;i++){
        option[i-6]=mkdirinput[i];
    }

    for(int i=9;i<strlen(mkdirinput);i++){
        option2[i-9]=mkdirinput[i];
    }
    if(strcmp(option,"-n")!=0 || strcmp(option,"-p")!=0){
        for(int i=6;i<strlen(mkdirinput);i++){
           nooption[i-6]=mkdirinput[i];
        }
    }
    // printf("%s",nooption);
    pid_t f =fork();
    if (f<0){
        printf("Fork Error(Child Process Not Created)");
        exit(1);
    }
    else if(f==0){
        if(strcmp(option,"-n")!=0 || strcmp(option,"-p")!=0){
            // printf("%s","Working");
            char *test[]={"./mkdirimplement",nooption,NULL};
            execvp(test[0],test);    
        }
        else{
        char *test[]={"./mkdirimplement",option,option2,NULL};
        execvp(test[0],test);
        }
    }
    else{
        wait(NULL);
    }
}

void * mkdirthread(void * mkdirinput){
    system(mkdirinput);
}

void mkdir_th(void * mkdirinput){
    pthread_t tid;
    pthread_create(&tid,NULL,mkdirthread,mkdirinput);
    pthread_join(tid,NULL);
}
