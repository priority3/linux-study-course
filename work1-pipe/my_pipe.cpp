#include <iostream>
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
	char InPipe[100];

	pipe(fd);

	// create pipe
	//while((pid2 = fork()) == -1);
	pid2 = fork();
	// child process 2
	if(pid2 == 0){
		// do something
		std::cout<<"child 2 \n";
		lockf(fd[1],1,0);
		write(fd[1],"Child process 2 is sending a message!",50);
		lockf(fd[1],0,0);
		exit(0);
	}
	else {
		// relative child 2 process of parent
		//while ((pid1 = fork()) == -1);
		pid1 = fork();
		if(pid1 == 0){
			// child process 1
			lockf(fd[1],1,0);
		  std::cout<<"child 1 \n";
			write(fd[1],"child process 1 is sending a message",50);
			lockf(fd[1],0,0);
			exit(0);
		}else {
			// relative child 1 process of parent
			while(-1 == read(fd[0],InPipe,sizeof(InPipe))){
				sleep(1);
				std::cout<<"wait... \n";
			}
		  std::cout<<InPipe<<"\n";			
			while(-1 == read(fd[0],InPipe,sizeof(InPipe))){
				sleep(1);
				std::cout<<"wait... \n";
			}
			std::cout<<InPipe<<"\n";
			exit(0);
		}
	}

	return 0;
}

