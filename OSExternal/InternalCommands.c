#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>
int newline=0;
int getnewline(){
    return newline;
}
void ic_main(char inputtemp[]){
// cd echo pwd
    char inputmain[100],pwdstr[100];
    // fgets(inputtemp,100,stdin);
    if(inputtemp[0]=='c'){
        char strcd[100];
        int ln=strlen(inputtemp);
        inputtemp[ln-1]='\0';
        if(strcmp(inputtemp,"cd ..")==0){
            char inputcd[2];
            for(int i=3;i<ln;i++){
                inputcd[i-3]=inputtemp[i];
            }

            chdir(inputcd);
            getcwd(strcd,100);
            printf("%s",strcd);
        }
        else if(strcmp(inputtemp,"cd ~")==0){
            char inputcd[1];
            // printf("length %d",ln);
            inputcd[0]=inputtemp[ln-2];
            printf("%s\n",inputcd);
            chdir(inputcd);
            getcwd(strcd,100);
            printf("%s\n",strcd);
        }
        else{
            char inputcd[100];
            for(int i=3;i<ln;i++){
                inputcd[i-3]=inputtemp[i];
            }
            if(chdir(inputcd)==0){
                getcwd(strcd,100);
                printf("%s\n",strcd);
            }
            else if(chdir(inputcd)!=0){
                perror("chdir() failed");
            }
            else{
                printf("Wrong Command in cd");
            }
        }

        // The above program changes the working directory of a process. 
        // But, it doesn’t change the working directory of current shell. 
        // Because when the program is executed in the shell, 
        // the shell follows fork on exec mechanism. 
        // So, it doesn’t affect the current shell
    }
    else if(inputtemp[0]=='e'){
        char inputecho[8];
        char message[30]="";
        int ln=strlen(inputtemp);
        inputtemp[ln-1]='\0';
        for(int i=0;i<7;i++){
            inputecho[i]=inputtemp[i];
        }
        
        
        // char message1[20]=message;
        if(strcmp(inputecho,"echo -e")==0){
            int count=0;
            for(int i=9;i<ln-2;){
                if(inputtemp[i]=='\\' && inputtemp[i+1]=='b'){
                    message[count]='\b';
                    count++;
                    i++;
                }
                else if(inputtemp[i]=='b' && inputtemp[i-1]!='\\'){
                    message[count]=inputtemp[i];
                    count++;
                    i++;
                }
                else if(inputtemp[i]=='b' && inputtemp[i-1]=='\\'){
                    i++;
                }
                else{
                    message[count]=inputtemp[i];
                    count++;
                    i++;
                }
            }
            
            // message[strlen(message)]='\n';
            printf("%s",message);
        }
        else if(strcmp(inputecho,"echo -n")==0){
            newline=1;
            int count=0;
            for(int i=9;i<ln-2;){
                if(inputtemp[i]=='\\' && inputtemp[i+1]=='b'){
                    message[count]='\b';
                    count++;
                    i++;
                }
                else if(inputtemp[i]=='b' && inputtemp[i-1]!='\\'){
                    message[count]=inputtemp[i];
                    count++;
                    i++;
                }
                else if(inputtemp[i]=='b' && inputtemp[i-1]=='\\'){
                    i++;
                }
                else{
                    message[count]=inputtemp[i];
                    count++;
                    i++;
                }
            }
            
            message[strlen(message)]='\0';
            printf("%s",message);
        }
        else{
            printf("Wrong Command\n");
        }

    }
    else if(inputtemp[0]=='p'){
        char inputpwd[10];
        int ln=strlen(inputtemp);
        inputtemp[ln-1]='\0';
        if(strcmp(inputtemp,"pwd")==0){
            getcwd(pwdstr,100);
            printf("%s\n",pwdstr);
        }
        else if(strcmp(inputtemp,"pwd -P")==0){
            getcwd(pwdstr,100);
            printf("%s\n",pwdstr); 
        }
        else if(strcmp(inputtemp,"pwd -L")==0){
            getcwd(pwdstr,100);
            printf("%s\n",pwdstr);
        }
        else{
            printf("%s\n","Wrong Command in pwd");
        }

    }
    else{
        printf("%s\n","Wrong command overall");
    }
}
