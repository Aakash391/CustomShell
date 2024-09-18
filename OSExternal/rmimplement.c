#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
    // rm
    // rm -i
    // rm --
    char choice;
    
    if(strcmp(argv[1],"-i")==0){
        printf("%s ","Are you sure you want to remove");
        scanf("%c",&choice);
        printf("%s",argv[1]);
        if(choice=='y' || choice=='Y'){
        
            // if(strcmp(argv[1],"-i")==0 || strcmp(argv[1],"--")==0){
                remove(argv[2]);
        }
    }
    else if(strcmp(argv[1],"--")==0){
        remove(argv[2]);
    }
    else{
        remove(argv[1]);
    }
    // else{
    //     printf("Wrong Command\n");
    // }
    

   

    return 0;
}

