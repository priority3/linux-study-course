#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//#include <cstdlib>
#include <unistd.h>
#include <string.h>
int main(){
	// file desc arr
	int fd[2];

	// child process 
	int pid1,pid2;

	// char 
	char OutPipe[100],InPipe[100];

	// create pipe
	while((pid2 = fork()) == -1);

	// child process 2
	if(pid2 == 0){
		// do something
		lockf(fd[1],1,0);
		sprintf(OutPipe,"Child process 2 is sending a message!");
		write(fd[1],OutPipe,50);
		sleep(1);
		lockf(fd[1],0,0);
		exit(2);
	}

	else {
		// relative child 2 process of parent
		while ((pid1 = fork()) == -1);
		if(pid1 == 0){
			// child process 1
			// do something
			lockf(fd[1],1,0);
			sprintf(OutPipe,"Child process 1 is sending a message!");
			write(fd[1],OutPipe,50);
			sleep(1);
			lockf(fd[1],0,0);
			exit(1);
		}else {
			// relative child 1 process of parent
			read(fd[0],InPipe,50);
			printf(" %s \n",InPipe);
			wait();
			read(fd[0],InPipe,50);
			printf(" %s \n",InPipe);

			exit(0);
		}

	}



	return 0;
}

