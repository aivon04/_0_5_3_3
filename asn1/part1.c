#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	pid_t pid1,pid2,pid3,pid4;
	int status = 0;
	pid1 = fork();
	if(pid1<0)
		perror("fork()");
	if(pid1>0){
		wait(0);
		pid2 = fork();
		if(pid2<0)
			perror("fork()");
		if(pid2>0){
			wait(0);
			printf("From parent process %d: Waiting for child_2 to complete before creating child_3\n",getpid());
			pid3 = fork();
			if(pid3<0)
				perror("fork()");
			if(pid3>0){
				wait(NULL);
			}else{
				/*child_3*/
				printf("From parent process %d: child_3 is created with PID %d\n",getppid(),getpid());
				printf("From child_3: Calling an external program B.out and leaving child_3...\n");
				printf("From the external program B: \n");
                execl("B.out","B.out",NULL);
				exit(0);

			}
		}else{
			/*child_2*/
			printf("From parent process %d: child_2 is created with PID %d\n",getppid(),getpid());

		}

	}else{
		/*child_1*/
		printf("From parent process %d: child_1 is created with PID %d\n",getppid(),getpid());
		pid4 = fork();
		if(pid4<0)
			perror("fork()");
		if(pid4>0){
			wait(0);
		}else{
			/*child_1.1*/
			printf("From child_1: child_1.1 is created with PID %d\n",getpid());

		}

	}
	return 0;
}

