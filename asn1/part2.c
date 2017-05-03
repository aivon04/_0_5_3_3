#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

#define READ 0
#define WRITE 1

int main(void)
{
	int X, Y;
	int n, m;
	int pipe1[2];
	int pipe2[2];
	pid_t pid;
	int status;
	/*build two pipes*/
	pipe(pipe1);
	pipe(pipe2);

	/*pipe1 error*/
	if (pipe(pipe1) < 0){
		perror("pipe1 error");
		exit(-1);
	}

	/*pipe2 error*/
	if (pipe(pipe2) < 0){
		perror("pipe2 error");
		exit(-1);
	}

	pid = fork();

	/*fork error*/
	if(pid<0){
		perror("fork error");
		exit(-1);
	}

	if(pid>0){
		/*parent*/
		printf("A pipe is created for communication between parent and child\n");
		printf("From parent %d: child with PID %d is created\n",getppid(),getpid());
		printf("From parent %d: Reading X from the user: ",getppid());
		scanf("%d",&X);
		close(pipe1[0]);
		write(pipe1[1], &X, sizeof(X));
		printf("From parent %d: Writing X into the pipe\n", getppid());
		wait(NULL);
		close(pipe2[1]);
		read(pipe2[0], &Y, sizeof(Y));
		printf("From parent %d: Reading Y from the pipe\n", getppid());
		printf("From parent %d: The value of Y is %d\n", getppid(), Y);
	}else{
		/*Child created*/
		sleep(3);
		printf("From child: Reading Y from the user: ");
		scanf("%d",&Y);
		sleep(2);
		printf("From child: Reading X from the pipe\n");
		close(pipe1[1]);
		read(pipe1[0], &X, sizeof(X));
		printf("From child: Writing Y into the pipe\n");
		close(pipe2[0]);
		write(pipe2[1], &Y, sizeof(Y));
		sleep(3);
		printf("From child: The value of X is %d\n", X);
	}
	return 0;
}