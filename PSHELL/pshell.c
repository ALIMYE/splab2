// your code here
#include <stdlib.h>
#include <unistd.h> 
#include <stdio.h>
#include <string.h> 
#include <sys/wait.h>
#include <stdarg.h>  
#define MAX_SIZE 1025

int print_select(); 

pid_t child_pids[1000];
int child=0;


int main() 
{
	char st[MAX_SIZE];  
    	int length;
	char st_copy[MAX_SIZE];
	printf("enter a command line ");


    while (fgets( st, MAX_SIZE, stdin)){

        length=strlen(st);

        if (st[length-1]=='\n')
             st[length-1]='\0';


	int x=0,z=length;
	 while (st[x]==' ')
        	x++;
    	while (st[z-1]==' ')
        	z--;
	z=z-x;


	stncpy(st,st+x,z);
	length=strlen(st);	
       	if(strcmp(st,"exit")==0){
		exit(1);
		break;
	}
	else if(strcmp(str,"showjobs")==0){
		for(int i=0;i < (child+1);i++){
			printf("%ld\n",(int)child_pids[i]);
		}
	}
	else{
		char *pChar = &st[strlen(st)-1];
		if(strcmp(pChar,"&")==0){
			pid_t process = fork();
			if(process<0){
				abort();
			}
			else if(process==0){
				char *name[] = { "/bin/bash","-c",st,NULL};
				execvp(name[0], name);
				exit(-1);
			}

		}

		else{
			pid_t process=fork();
			if(process<0){
				abort();
			}
			else if(process==0){
				  char *name[] = { "/bin/bash","-c",st,NULL};
				  execvp(name[0], name);
				exit(-1);
			}

			else{
				waitpid(process,0,0);

			}

		}
	}

	printf("Enter a command line ");
    }





    return 0; 
}
