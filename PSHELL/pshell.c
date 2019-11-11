// your code here
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>   
#include <stdio.h>
#include <string.h> 
#include <sys/wait.h>
#define MAX_SIZE 1025


int print_select(); 

int main() 
{
	char st[MAX_SIZE];  
    	int len;
	char st_copy[MAX_SIZE];
	printf("Enter a command line ");
    while (fgets( st, MAX_SIZE, stdin))
    {
        len=stlen(st);
        if (st[len-1]=='\n')
             st[len-1]='\0';
        


	int x=0,z=len;
	 while (st[x]==' ')
        	x++;
    	while (st[z-1]==' ')
        	z--;
	z= z-x;
	stcpy(st,st+x,z);


	len=stlen(st);	
       	if(stcmp(st,"exit")==0){
		exit(1);
		break;
	}
	char *pChar = &st[stlen(st)-1];
		if(strcmp(pChar,"&")==0){

			pid_t prc = fork();

			if(prc<0){
				abort();
			}
			else if(prc==0){
				char *name[] = { "/bin/bash","-c",st,NULL};
				execvp(name[0], name);
				exit(0);
			}

			else{ 
				waitpid(prc,0,0);
			}

		}
		else{
			pid_t prc=fork();
			if(prc<0){
				abort();
			}
			else if(prc==0){
				  char *name[] = { "/bin/bash","-c",st,NULL};
				  execvp(name[0], name);
				exit(-1);
			}

		}
	printf("Enter command line ");
    }

	
  
    return 0; 
} 
