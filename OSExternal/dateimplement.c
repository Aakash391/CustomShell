#include<stdio.h>
// #include<conio.h>
#include<time.h>
#include<string.h>

// date
// date -u
// date -R
int main(int argc,char *argv[])
{
    // date -u command
    // printf("%s",argv[1]);
    time_t tm;
    time(&tm);
    char date[100]="";
    char timezone[4]="IST";
    strcpy(date,ctime(&tm));
    // printf("Date %s",date);
    char year[10]="";
    char day[5]="";
    char month[5]="";
    char num[5]="";
    char time[15]="";
    int ln=strlen(date);
    // printf("length %d\n",ln);
    for(int i=ln-5;i<ln-1;i++){
        year[i-ln+5]=date[i];
       
    }
    for(int i=0;i<3;i++){
        day[i]=date[i];
    }
    for(int i=4;i<7;i++){
        month[i-4]=date[i];
    }
    for(int i=8;i<10;i++){
        num[i-8]=date[i];
    }
    for(int i=11;i<19;i++){
        time[i-11]=date[i];
    }
    int len=strlen(year);
    // printf("Yearlenght %d\n",len);
    // printf("Year %s",year);
    date[20]=' ';
    if(strcmp(argv[1],"-u")==0){
        strcpy(timezone,"UTC");
        for(int i=20;i<23;i++){
            date[i]=timezone[i-20];
        }
        date[23]=' ';
        for(int i=0;i<strlen(year);i++){
            date[i+24]=year[i];
        }
        date[28]='\0';
        printf("%s", date);
    }
    // else{
    //     strcpy(timezone,"IST");
    // }
    else if(strcmp(argv[1],"-R")==0){
        printf("%s, ",day);
        printf("%s ",num);
        printf("%s ",month);
        printf("%s ",year);
        printf("%s ",time);
        printf("%s ","+530");
    }
    else if(strcmp(argv[1],"")==0){
        for(int i=20;i<23;i++){
            date[i]=timezone[i-20];
        }
        date[23]=' ';
        for(int i=0;i<strlen(year);i++){
            date[i+24]=year[i];
        }
        date[28]='\0';
        printf("%s", date);
    }
    else{
        printf("Wrong Command\n");
    }
    
    
    

    // getch();


    return 0;
}