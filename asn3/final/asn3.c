#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/mman.h>


int critical_section(int loop_limit,int who_called);
void up(int *i);
void down(int *i);

int loop_limit = 10;
int i;


int main()
{	
	//set semaphore and semaphore_second_level_check be the global variable
	int * semaphore = mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS,-1,0); 
	int * semaphore_second_level_check = mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS,-1,0); 
	
	pid_t pid1, pid2, pid3, pid4, pid5, pid6, pid7, pid8, pid9, pid10;
	int status = 0;
	//set semaphore and semaphore_second_level_check initial be 0
	*semaphore_second_level_check = 0;
	*semaphore = 0;
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


									}else{
										/*child_9*/
										while(1)
										{
											if(*semaphore ==0)
											{	
												if((*semaphore_second_level_check)++ == 1)
												{
													up(semaphore);
													critical_section(loop_limit,getpid());
													*semaphore_second_level_check = 1;
													down(semaphore);
													exit(0);
												}
												else{
													while(1)
													{
														//printf("%d\n", *semaphore_second_level_check);
														if(*semaphore_second_level_check == 1)
														{
															break;
														}
													}
												}
											}
										}
									}

								}else{
									/*child_8*/
									while(1)
									{
										if(*semaphore ==0)
										{	
											if((*semaphore_second_level_check)++ == 1)
											{
												up(semaphore);
												critical_section(loop_limit,getpid());
												*semaphore_second_level_check = 1;
												down(semaphore);
												exit(0);
											}
											else{
												while(1)
												{
													if(*semaphore_second_level_check == 1)
													{
														break;
													}
												}
											}
										}
									}
								}

							}else{
								/*child_7*/
								while(1)
								{
									if(*semaphore ==0)
									{	
										if((*semaphore_second_level_check)++ == 1)
										{
											up(semaphore);
											critical_section(loop_limit,getpid());
											*semaphore_second_level_check = 1;
											down(semaphore);
											exit(0);
										}
										else{
											while(1)
											{
												if(*semaphore_second_level_check == 1)
												{
													break;
												}
											}
										}
									}
								}
							}
						}else{
							/*child_6*/
							while(1)
							{
								if(*semaphore ==0)
								{	
									if((*semaphore_second_level_check)++ == 1)
									{
										up(semaphore);
										critical_section(loop_limit,getpid());
										*semaphore_second_level_check = 1;
										down(semaphore);
										exit(0);
									}
									else{
										while(1)
										{
											if(*semaphore_second_level_check == 1)
											{
												break;
											}
										}
									}
								}
							}
						}
					}else{
						/*child_5*/
						while(1)
						{
							if(*semaphore ==0)
							{	
								if((*semaphore_second_level_check)++ == 1)
								{
									up(semaphore);
									critical_section(loop_limit,getpid());
									*semaphore_second_level_check = 1;
									down(semaphore);
									exit(0);
								}
								else{
									while(1)
									{
										if(*semaphore_second_level_check == 1)
										{
											break;
										}
									}
								}
							}
						}
					}

				}else{
					/*child_4*/
					while(1)
					{
						if(*semaphore ==0)
						{	
							if((*semaphore_second_level_check)++ == 1)
							{
								up(semaphore);
								critical_section(loop_limit,getpid());
								*semaphore_second_level_check = 1;
								down(semaphore);
								exit(0);
							}
							else{
								while(1)
								{
									if(*semaphore_second_level_check == 1)
									{
										break;
									}
								}
							}	
						}
					}
				}

			}else{
				/*child_3*/
				while(1)
				{
					if(*semaphore ==0)
					{	
						if((*semaphore_second_level_check)++ == 1)
						{
							up(semaphore);
							critical_section(loop_limit,getpid());
							*semaphore_second_level_check = 1;
							down(semaphore);
							exit(0);
						}
						else{
							while(1)
							{
								if(*semaphore_second_level_check == 1)
								{
									break;
								}
							}
						}
					}
				}
			}
		}else{
			/*child_2*/
			while(1)
			{
				if(*semaphore ==0)
				{	
					if((*semaphore_second_level_check)++ == 1)
					{
						up(semaphore);
						critical_section(loop_limit,getpid());
						*semaphore_second_level_check = 1;
						down(semaphore);
						exit(0);
					}
					else{
						while(1)
						{
							if(*semaphore_second_level_check == 1)
							{
								break;
							}
						}				
					}
				}
			}
		}

	}else{
		/*child_1*/
		while(1)
		{
			if(*semaphore ==0)
			{	
				if((*semaphore_second_level_check)++ == 1)
				{
					up(semaphore);
					critical_section(loop_limit,getpid());
					*semaphore_second_level_check = 1;
					down(semaphore);
					exit(0);
				}
				else{
					while(1)
					{
						if(*semaphore_second_level_check == 1)
						{
							break;
						}
					}
				}
			}
		}

	}
}

/*critical_section function*/
int critical_section(int loop_limit,int who_called)
{
	
	for(i=0;i<loop_limit;i++)
		printf("Child pid %d called, this is the #%d loop\n", who_called, i+1);
				printf("returning to caller process %d\n", who_called);//x is the caller process
				return 0;

			}

//up function
			void up(int *i)
			{
				i++;
				return;
			}

//down function
			void down(int *i)
			{
				i--;
				return;
			}