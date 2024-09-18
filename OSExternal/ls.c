#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include<pthread.h>

// ls-l
// ls-lh
// ls
void ls_func(char lsinput[]){
    char option[10]="";
    char option2[100]="";
    int flag=0;
    int ln=strlen(lsinput);
    lsinput[ln-1]='\0';
    for(int i=3;i<strlen(lsinput);i++){
        option[i-3]=lsinput[i];
    }
    getcwd(option2,100);


    
    pid_t f =fork();
    if (f<0){
        printf("Fork Error(Child Process Not Created)");
        exit(1);
    }
    else if(f==0){
        char *test[]={"./lsimplement",option,option2,NULL};
        execvp(test[0],test);
        
    }
    else{
        wait(NULL);
    }
}

void * lsthread(void * lsinput){
    system(lsinput);
}

void ls_th(void * lsinput){
    pthread_t tid;
    pthread_create(&tid,NULL,lsthread,lsinput);
    pthread_join(tid,NULL);
}


