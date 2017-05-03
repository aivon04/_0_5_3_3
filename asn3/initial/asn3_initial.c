#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/mman.h>


int loop(int loop_limit,int who_called);
int loop_limit = 10;
int i;

int main()
{	
	pid_t pid1, pid2, pid3, pid4, pid5, pid6, pid7, pid8, pid9, pid10;
	int status = 0;
	//fork 9 children
	pid1 = fork();
	if(pid1<0)
		perror("fork()");
	if(pid1>0){
		pid2 = fork();
		if(pid2<0)
			perror("fork()");
		if(pid2>0){
			pid3 = fork();
			if(pid3<0)
				perror("fork()");
			if(pid3>0){
				pid4 = fork();
				if(pid4<0)
					perror("fork()");
				if(pid4>0){
					pid5 = fork();
					if(pid5<0)
						perror("fork()");
					if(pid5>0){
						pid6 = fork();
						if(pid6<0)
							perror("fork()");
						if(pid6>0){
							pid7 = fork();
							if(pid7<0)
								perror("fork()");
							if(pid7>0){
								pid8 = fork();
								if(pid8<0)
									perror("fork()");
								if(pid8>0){
									pid9 = fork();
									if(pid9<0)
										perror("fork()");
									if(pid9>0){
										loop(loop_limit,getpid());


									}else{
										/*child_9*/
										loop(loop_limit,getpid());

									}

								}else{
									/*child_8*/
									loop(loop_limit,getpid());

								}

							}else{
								/*child_7*/
								loop(loop_limit,getpid());

							}
						}else{
							/*child_6*/
							loop(loop_limit,getpid());

						}
					}else{
						/*child_5*/
						loop(loop_limit,getpid());

					}

				}else{
					/*child_4*/
					loop(loop_limit,getpid());

				}

			}else{
				/*child_3*/
				loop(loop_limit,getpid());

			}
		}else{
			/*child_2*/
			loop(loop_limit,getpid());

		}

	}else{
		/*child_1*/
		
		loop(loop_limit,getpid());

	}
}


/*loop function*/
int loop(int loop_limit,int who_called)
{
	
	for(i=0;i<loop_limit;i++)
		printf("Child pid %d called, this is the #%d loop\n", who_called, i+1);
				printf("returning to caller process %d\n", who_called);//x is the caller process
				return 0;

			}

