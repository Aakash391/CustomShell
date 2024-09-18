#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
int main(int argc,char *argv[]){
    int check;
    char option[4]="";
   

    for(int i=0;i<2;i++){
      option[i]=argv[1][i];
    }
    if(strcmp(option,"-v")==0){
      // printf("%s","Working if");
      // printf("%d",argc);
      int k=0;
      char file[100]="";
      // printf("Argv[2] =%s\n",argv[2]);
      for(int i=1;i<argc;i++){
          k=0;
          for(int j=3;j<strlen(argv[i]);j++){
            
            if(argv[i][j]==' ' || argv[i][j]=='\n'){
              // printf("file = %s\n",file);
              check = mkdir(file, 0755);
              if (!check)
                printf("mkdir: Created  Directory '%s'\n",file);
              else {
                printf("Unable to create directory");
                exit(1);    
              }
              k=0;
            }
            else{
              file[k]=argv[i][j];
              k++;
            }
          }
          check = mkdir(file, 0755);
          if (!check)
            printf("mkdir: Created  Directory '%s'\n",file);
          else {
            printf("Unable to create directory");
            exit(1);    
          }
      }
    }
          
          
    
//  for mkdir -p with multiple files
    // printf("%d",argc);
    else if(strcmp(option,"-p")==0){
      // printf("%s","Working");
      printf("Working");
      int countdir=0;
      for(int i=1;i<argc;i++){
          char file[30]="";
          int k=0;
          for(int j=3;j<strlen(argv[i]);j++){

              if(argv[i][j]=='/' || argv[i][j]=='\n'){
                  countdir++;
                  // printf("File %s\n",file);
                  check = mkdir(file, 0755);
                  if (!check)
                    printf("Directory created");
                  else {
                    printf("Unable to create directory");
                    exit(1);
                  }
                  char dir[100]="";
                  getcwd(dir,100);
                  int initial=strlen(dir);
                  dir[initial]='/';
                  initial++;
                  for(int k=0;k<strlen(file);k++){
                      dir[initial]=file[k];
                      initial++;
                  }
                  // printf("Dir %s\n",dir);
                  chdir(dir);
                  char s[100]="";
                  // printf("Printnig %s",getcwd(s,100));
                  // printf("Again %s\n",getcwd(s,100));

                  k=0;

              }
              else if(argv[i][j]!=' '){

              
                  file[k]=argv[i][j];

                  k++;
              }
              if(argv[i][j]==' '){
                mkdir(file,0755);
                chdir("..");
                k=0;
              }

          }
          check = mkdir(file, 0755);
          if (!check)
            printf("Directory created");
          else {
            printf("Unable to create directory");
            exit(1);
          }
          for(int i=0;i<countdir;i++){
              chdir("..");
          }
          countdir=0;

      }
    }
    else{
      // printf("\n%s","working else");
      int k=0;
      char file[100]="";
      // printf("Argv[2] nhi hai =%s\n",argv[2]);
      for(int i=1;i<argc;i++){
          k=0;
          for(int j=0;j<strlen(argv[i]);j++){
            
            if(argv[i][j]==' ' || argv[i][j]=='\n'){
              // printf("file = %s\n",file);
              check = mkdir(file, 0755);
              // if (!check)
                // printf("Directory created %s\n",file);
              if(check) {
                printf("Unable to create directory");
                exit(1);    
              }
              k=0;
            }
            else{
              file[k]=argv[i][j];
              k++;
            }
          }
          check = mkdir(file, 0755);
          if (!check)
            printf("Directory created");
          else {
            printf("Unable to create directory");
            exit(1);    
          }
      }
    }
 
    return 0;
}