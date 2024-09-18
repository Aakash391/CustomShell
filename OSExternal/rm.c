#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
void rm_func(char rminput[]){
    char option[30]="";
    char option2[30]="";
    // fgets(rminput,30,stdin);
    int ln=strlen(rminput);
    rminput[ln-1]='\0';

    for(int i=3;i<5;i++){
        option[i-3]=rminput[i]; 
    }
    
    
    // printf("OPtion %s\n",option);
    // printf("Option 2 %s\n",option2);


    pid_t f =fork();
    if (f<0){

        printf("Fork Error(Child Process Not Created)");
        exit(1);
    }
    else if(f==0){
        if(strcmp(option,"-i")!=0 && strcmp(option,"--")!=0){
            for(int i=3;i<strlen(rminput);i++){
                option2[i-3]=rminput[i]; 
            }
            char *test[]={"./rmimplement",option2,NULL};
            execvp(test[0],test);

        }
        else{
            for(int i=6;i<strlen(rminput);i++){
                option2[i-6]=rminput[i]; 
            }
            char *test[]={"./rmimplement",option,option2,NULL};
            execvp(test[0],test);
        }
    }
    else{
        wait(NULL);
    }
}

void * rmthread(void * rminput){
    system(rminput);
}

void rm_th(void * rminput){
    pthread_t tid;
    pthread_create(&tid,NULL,rmthread,rminput);
    pthread_join(tid,NULL);
}
