#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>

// ls
// ls -a
// ls -m
int main(int argc,char *argv[])
{
	struct dirent *dp;
    DIR *dir = opendir(argv[2]);

    // Unable to open directory stream
    if (!dir) 
        printf("Error"); 

    if(strcmp(argv[1],"-a")==0){
        while ((dp = readdir(dir)) != NULL)
        {
            printf("%s\n", dp->d_name);
        }
    }
    else if(strcmp(argv[1],"-m")==0){
        while ((dp = readdir(dir)) != NULL)
        {
            if((strcmp(dp->d_name,".")!=0) && (strcmp(dp->d_name,"..")!=0)) {
                printf("%s, ", dp->d_name);
            }    
        }
    }
    else if(strcmp(argv[1],"")==0){
        while ((dp = readdir(dir)) != NULL)
        {
            if((strcmp(dp->d_name,".")!=0) && (strcmp(dp->d_name,"..")!=0)){
                printf("%s\n", dp->d_name);
            }
        }
    }
    else{
        printf("Wrong Command");
    }

    // Close directory stream
    closedir(dir);
	return 0;
}

