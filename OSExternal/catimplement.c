#include<stdio.h>
#include<string.h>

// cat
// cat -n
// cat -e
int main(int argc, char *argv[])
{
	char option1[4]="";
	
	for(int i=0;i<2;i++){
		option1[i]=argv[1][i];
	}

	if(strcmp(option1,"-n")==0){
		char file[30]="";
		int k=0;
		int index=1;
		for(int i=3;i<strlen(argv[1]);i++){
			if(argv[1][i]==' '){
				FILE *fptr;
				char ch;
				fptr=fopen(file,"r");
				if(!fptr)
				{
					printf("%s","Error");
				}
				else{
					while((ch=fgetc(fptr))!=EOF)
					{
						printf("\t%d ",index);
						while(ch!='\n'){
							printf("%c",ch);
							ch=fgetc(fptr);
						}
						printf("%s","\n");
						index++;
					}
					fclose(fptr);
				}
				k=0;

			}
			else{
				file[k]=argv[1][i];
				k++;
			}
		}
		FILE *fptr;
		char ch;

		fptr=fopen(file,"r");
		if(!fptr)
		{
			printf("%s","Error");
		}
	
		else{
		
			while((ch=fgetc(fptr))!=EOF)
			{
				printf("\t%d ",index);
				while(ch!='\n'){
					printf("%c",ch);
					ch=fgetc(fptr);
				}
				printf("%s","\n");
				index++;
			}
			fclose(fptr);
		}

	}
	else if(strcmp(option1,"-e")==0){
		char file[30]="";
		int k=0;
		// int index=1;
		for(int i=3;i<strlen(argv[1]);i++){
			if(argv[1][i]==' '){
				FILE *fptr;
				char ch;
				fptr=fopen(file,"r");
				if(!fptr)
				{
					printf("%s","Error");
				}

				else{
		
					while((ch=fgetc(fptr))!=EOF)
					{
						// printf("\t%d ",index);
						if(ch!='\n'){
							while(ch!='\n'){
								printf("%c",ch);
								ch=fgetc(fptr);
							}
						}
						else if(ch=='\n'){
							printf("%s","$");
							printf("%s","\n");
						}
						// index++;
					}
					fclose(fptr);
				}
				k=0;

			}
			else{
				file[k]=argv[1][i];
				k++;
			}
		}
		printf("%s","\n");
		FILE *fptr;
		char ch;

		fptr=fopen(file,"r");
		if(!fptr)
		{
			printf("%s","Error");
		}

		else{
	
			while((ch=fgetc(fptr))!=EOF)
			{
				// printf("\t%d ",index);
				while(ch!='\n'){
					printf("%c",ch);
					ch=fgetc(fptr);
				}
				printf("%s","$");
				printf("%s","\n");
				// index++;
			}
			fclose(fptr);
		}
	}
	else{
		char file[30]="";
		int k=0;
		// int index=1;
		for(int i=0;i<strlen(argv[1]);i++){
			if(argv[1][i]==' '){
				FILE *fptr;
				char ch;
				fptr=fopen(file,"r");
				if(!fptr)
				{
					printf("%s","Error");
				}

				else{
		
					while((ch=fgetc(fptr))!=EOF)
					{
						// printf("\t%d ",index);
						while(ch!='\n'){
							printf("%c",ch);
							ch=fgetc(fptr);
						}
						printf("%s","\n");
						// index++;
					}
					fclose(fptr);
				}
				k=0;

			}
			else{
				file[k]=argv[1][i];
				k++;
			}
		}
		FILE *fptr;
		char ch;

		fptr=fopen(file,"r");
		if(!fptr)
		{
			printf("%s","Error");
		}

		else{
	
			while((ch=fgetc(fptr))!=EOF)
			{
				// printf("\t%d ",index);
				while(ch!='\n'){
					printf("%c",ch);
					ch=fgetc(fptr);
				}
				printf("%s","\n");
				// index++;
			}
			fclose(fptr);
		}
	}
	// else{
	// 	printf("Wrong Command\n");
	// }
	return 0;
}
