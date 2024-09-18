
// cat ke options bnanae hai
// date ke bhi
// Corner Cases
// echo --help krna hai


#include<stdio.h>

#include "ls.c"
#include "cat.c"
#include "date.c"
#include "rm.c"
#include "mkdir.c"
#include "InternalCommands.c"

int main(){
    char commdinput[60]="";
    char commdinputthread[60]="";
    char lastoption[5]="";
    char s[100]="";
    while(1){
        if(newline==0){
            printf("\033[1;32m");
            printf("\n%s$",getcwd(s,100));
        }
        else{
            printf("\033[1;32m");
            printf("%s$",getcwd(s,100));
        }
        fgets(commdinput,60,stdin);
        int ln=strlen(commdinput);
        for(int i=ln-3;i<ln;i++){
            lastoption[i-ln+3]=commdinput[i];
        }
        // printf("LastOption %s",lastoption);
        if(lastoption[0]=='&' && lastoption[1]=='t'){
            // printf("%s","Equal hai");
            for(int i=0;i<strlen(commdinput)-3;i++){
                commdinputthread[i]=commdinput[i];
            }
            // printf("Thread commdinput %s",commdinputthread);
            if(commdinputthread[0]=='l'){
                // printf("%s","Calling ls_th");
                ls_th(commdinputthread);
            }   
            else if(commdinput[0]=='c'){
                cat_th(commdinputthread);
            }
            else if(commdinput[0]=='d'){
                date_th(commdinputthread);
            }
            else if(commdinput[0]=='r'){
                rm_th(commdinputthread);
            }
            else if(commdinput[0]=='m'){
                mkdir_th(commdinputthread);
            }
            else{
                mkdir_th(commdinputthread);
            }
        }
        else{
            if(commdinput[0]=='l'){
                // printf("%s","Calling ls_func");
                ls_func(commdinput);
            }
            else if(commdinput[0]=='c'){
                if(commdinput[1]=='d'){
                    ic_main(commdinput);
                }
                else{
                    cat_func(commdinput);
                }
            }
            else if(commdinput[0]=='d'){
                // printf("%s","date_func");
                date_func(commdinput);
            }
            else if(commdinput[0]=='r'){
                rm_func(commdinput);
            }
            else if(commdinput[0]=='m'){
                mkdir_func(commdinput);
            }
            else if(commdinput[0]=='p'){
                ic_main(commdinput);
            }
            else if(commdinput[0]=='e'){
                ic_main(commdinput);
            }   
        }
    }
}