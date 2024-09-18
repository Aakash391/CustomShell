#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

// date --date=""
// date -R
// date
void date_func(char dateinput[]){
    char option[30]="";
    char option2[30]="";
    // fgets(dateinput,30,stdin);
    int ln=strlen(dateinput);
    dateinput[ln-1]='\0';

    if(ln>6){
        for(int i=5;i<11;i++){
            option[i-5]=dateinput[i];
        }

        for(int i=13;i<strlen(dateinput)-1;i++){
            option2[i-13]=dateinput[i];
        }
    }
    else{
        for(int i=5;i<strlen(dateinput);i++){
            option[i-5]=dateinput[i];
        }
    }
    // printf("ln = %d",ln);
 
    pid_t f =fork();
    if (f<0){
        
        printf("Fork Error(Child Process Not Created)");
        exit(1);
    }
    else if(f==0){
        if(ln==8){
            // printf("Single date");
            // printf("%s","Working");
            char *test[]={"./dateimplement",option,NULL};
            execvp(test[0],test);    
        }
        else if(ln==4){
            // printf("%s","Working1");
            char *test[]={"./dateimplement",NULL};
            execvp(test[0],test);
        }
        else{
            // printf("%s","Working2");
            char *test[]={"./dateimplement",option,option2,NULL};
            execvp(test[0],test);
        }
    }
    else{
        wait(NULL);
    }
}

void * datethread(void * dateinput){
    system(dateinput);
}

void date_th(void * dateinput){
    pthread_t tid;
    pthread_create(&tid,NULL,datethread,dateinput);
    pthread_join(tid,NULL);
}
