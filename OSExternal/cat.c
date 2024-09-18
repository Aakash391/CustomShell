#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
void cat_func(char catinput[]){

    char option[30]="";
    // char option2[15]="";
    // char option3[5]="";
    // int optionflag=0;

    int ln=strlen(catinput);
    int file2=0,start=0;
    catinput[ln-1]='\0';
    // if(catinput[4]=='-'){
    //     for(int i=4;i<6;i++){
    //         option3[i-4]=catinput[i];
    //         optionflag=1;
    //     }
    // }
    // if(optionflag==0){
    //     for(int i=4;i<ln;i++){
    //         if(catinput[i]==' '){
    //             file2=1;
    //             start=i;
    //             break;
    //         }
    //         else{
    //             option[i-4]=catinput[i];
    //         }
    //     }
    // }
    // else if(optionflag==1){
    //     for(int i=7;i<ln;i++){
    //         if(catinput[i]==' '){
    //             file2=1;
    //             start=i;
    //             break;
    //         }
    //         else{
    //             option[i-7]=catinput[i];
    //         }
    //     }
    // }

    // if(file2==1 ){
    //     // printf("\n%s","Working");
    //     for(int i=start+1;i<strlen(catinput);i++){
    //         option2[i-start-1]=catinput[i];
    //     }    
    // }

    for(int i=4;i<strlen(catinput);i++){
        option[i-4]=catinput[i];
    }
    // printf("Option %s",option);
    pid_t f =fork();
    if (f<0){
        printf("Fork Error(Child Process Not Created)");
        exit(1);
    }
    else if(f==0){
        printf("%s","Working");
        char *test[]={"./catimplement",option,NULL};
            
        execvp(test[0],test);
    }

    //     else if(file2==0 && optionflag==1){
    //         // char s[100],dir[20]="OSExternal";
    //         // getcwd(s,100);
    //         // int ln=strlen(s);
    //         // s[ln]='/';
    //         // printf("Length ln =%d\n",ln);
    //         // printf("Length dir =%ld",strlen(dir));
    //         // for(int i=0;i<strlen(dir);i++){
    //         //     s[ln+1+i]=dir[i];
    //         // }
    //         // int ln1=ln+strlen(dir);
    //         // printf("ln1 =%d",ln1);
    //         // s[ln1+1]='\0';            
    //         // printf("S= %s\n",s);
    //         // chdir(s);
    //         // printf("New directory %s\n",getcwd(s,100));

    //         char *test[]={"./catimplement",option3,option,NULL};
    //         printf("Option %s",option);
    //         execv(test[0],test);
    //         printf("\n%s","Ending");
    //     }
        
    //     else if(file2==1 && optionflag==0){
    //         char *test[]={"./catimplement",option,option2,NULL};
    //         execvp(test[0],test);
    //     }
    //     else if(file2==1 && optionflag==1){
    //         char *test[]={"./catimplement",option3,option,option2,NULL};
    //         execvp(test[0],test);
    //     }
    // }
    else{
        wait(NULL);
    }

}

void * catthread(void * catinput){
    system(catinput);
}

void cat_th(void * catinput){
    pthread_t tid;
    pthread_create(&tid,NULL,catthread,catinput);
    pthread_join(tid,NULL);
}
