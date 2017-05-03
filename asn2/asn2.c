#include <stdio.h>
#include <stdlib.h>

int main()
{

	short queue[10];
	//read the input file
	FILE *file;
	char x[10];
	file = fopen("mullevel_queue_CPU_scheduling_input_file.txt","r");
	if(file == NULL)
	{
		perror("Error opening file");
	}
	else{
		for (int i = 0; i < 5; ++i)
		{
			fscanf(file, "%s", x);
		}
		for (int i = 0; i < 10; ++i)
		{
		fscanf(file, "%s", x);
		fscanf(file, "%s", x);
		queue[i]=atoi(x);
		}

		fclose(file);
	}

	file = fopen( "multilevel_cpu_output.txt","w" );

	printf("\n");
	printf("*****************************************************************\n");
	printf("*                           RR Algorithm                        *\n");
	printf("*****************************************************************\n");
	printf("\n");

	fprintf(file,"\n");
	fprintf(file,"*****************************************************************\n");
	fprintf(file,"*                           RR Algorithm                        *\n");
	fprintf(file,"*****************************************************************\n");
	fprintf(file,"\n");

	//RR Algorithm
	double totalTime1=0;
	int time_quantum = 5;
	short remain[10];
	short turnaroud_time[10];
	double waitingTime1=0;
	short waitingTime[10];

	int i;

	//Order for ready queue 2
	printf("The order of the processes selected by CPU in Ready Queue 2 is:\n");
	fprintf(file,"The order of the processes selected by CPU in Ready Queue 2 is:\n");

	for(i=0;i<10;i++){
		remain[i]=queue[i];
	}

	for(i=0;i<10;i++)
	{
		if(remain[i]>0){
			printf("Process[%d]\n", i+1);
			fprintf(file,"Process[%d]\n", i+1);
			if(remain[i]<5)
			{
				totalTime1=totalTime1+remain[i];
				turnaroud_time[i]=totalTime1;
				remain[i]=0;
			}
			else{
				remain[i]=remain[i]-5;
				totalTime1=totalTime1+5;
				turnaroud_time[i]=totalTime1;
				}
		}
	}

	for(i=0;i<10;i++)
	{
		if(remain[i]>0){
			printf("Process[%d]\n", i+1);
			fprintf(file,"Process[%d]\n", i+1);

			if(remain[i]<5)
			{
				totalTime1=totalTime1+remain[i];
				turnaroud_time[i]=totalTime1;
				remain[i]=0;
			}
			else{
				remain[i]=remain[i]-5;
				totalTime1=totalTime1+5;
				turnaroud_time[i]=totalTime1;
				}
		}
	}

	for(i=0;i<10;i++)
	{
		if(remain[i]>0){
			printf("Process[%d]\n", i+1);
			fprintf(file,"Process[%d]\n", i+1);

			if(remain[i]<5)
			{
				totalTime1=totalTime1+remain[i];
				turnaroud_time[i]=totalTime1;
				remain[i]=0;

			}
			else{
				remain[i]=remain[i]-5;
				totalTime1=totalTime1+5;
				turnaroud_time[i]=totalTime1;
				}
		}
	}

	for(i=0;i<10;i++)
	{
		if(remain[i]>0){
			printf("Process[%d]\n", i+1);
			fprintf(file,"Process[%d]\n", i+1);

			if(remain[i]<5)
			{
				totalTime1=totalTime1+remain[i];
				turnaroud_time[i]=totalTime1;
				remain[i]=0;

			}
			else{
				remain[i]=remain[i]-5;
				totalTime1=totalTime1+5;
				turnaroud_time[i]=totalTime1;

				}
		}
	}

	printf("\n");
	fprintf(file,"\n");

	//Waiting time for every process
	for(i=0;i<10;i++)
	{
			if(queue[i]<5){
				waitingTime1=waitingTime1+queue[i];
				waitingTime[i+1]=waitingTime1;
			}
			else{
				waitingTime1=waitingTime1+5;
				waitingTime[i+1]=waitingTime1;
				}
	}
	waitingTime[0]=0;

	for(i=0;i<10;i++){
		printf("The turnaround time for process[%d] is:%d\n",i+1,turnaroud_time[i] - waitingTime[i]);
		fprintf(file,"The turnaround time for process[%d] is:%d\n",i+1,turnaroud_time[i]- waitingTime[i]);
	}	
	printf("\n");
	fprintf(file,"\n");
	printf("Total Time for queue 2 is:%f\n",totalTime1);
	fprintf(file,"Total Time for queue 2 is:%f\n",totalTime1);

	printf("\n");
	printf("*****************************************************************\n");
	printf("*                          FCFS Algorithm                       *\n");
	printf("*****************************************************************\n");
	printf("\n");

	fprintf(file,"\n");
	fprintf(file,"*****************************************************************\n");
	fprintf(file,"*                          FCFS Algorithm                       *\n");
	fprintf(file,"*****************************************************************\n");
	fprintf(file,"\n");

	//FCFS Algorithm
	// Queue's process burst time
	int waitingTime2=0;
	double totalTime2=0;
	double totalWaitingTime2=0;
	//Order for ready queue 1
	printf("The order of the processes selected by CPU in Ready Queue 1 is:\n");
	fprintf(file,"The order of the processes selected by CPU in Ready Queue 1 is:\n");
	
	for(i=0;i<10;i++){
		printf("Process[%d]\n",i+1);
		fprintf(file,"Process[%d]\n",i+1);
		totalTime2=totalTime2+queue[i];
 	}
 	printf("\n");
 	fprintf(file,"\n");
	//calculate the waiting time for each process and the average waiting time for queue 1
	for(i=0;i<10;i++){
		waitingTime2=waitingTime2+queue[i-1];
		printf("Process [%d]'s waiting time is %d\n",i+1,waitingTime2);
		fprintf(file,"Process [%d]'s waiting time is %d\n",i+1,waitingTime2);
		totalWaitingTime2=totalWaitingTime2+waitingTime2;
	}

	printf("\n");
 	fprintf(file,"\n");

	printf("The average waiting time for ready queue 1 is: %f.\n",totalWaitingTime2/10);
	fprintf(file,"The average waiting time for ready queue 1 is: %f.\n",totalWaitingTime2/10);


	printf("\n");
	printf("*****************************************************************\n");
	printf("*                          SJF Algorithm                        *\n");
	printf("*****************************************************************\n");
	printf("\n");

	fprintf(file,"\n");
	fprintf(file,"*****************************************************************\n");
	fprintf(file,"*                          SJF Algorithm                        *\n");
	fprintf(file,"*****************************************************************\n");
	fprintf(file,"\n");

	//SJF Algorithm
	short process3[10];
	
	for(i=0;i<10;i++){
		process3[i]=queue[i]; 
	}

	double totalTime3=0;
	int waitingTime3=0;
	double totalWaitingTime3=0;
	int j,k,temp,pos;
	short array[10];
	//Order for ready queue 3
	for(j=0;j<10;j++){
		pos=j;
		for(k=j+1;k<10;k++){
			if(process3[k]<process3[pos])
			{
				temp = process3[k];
				process3[k]=process3[pos];
				process3[pos]=temp;
			}
		}
	}

	//Order for ready queue 3
	printf("The order of the processes selected by CPU in Ready Queue 3 is:\n");
	fprintf(file,"The order of the processes selected by CPU in Ready Queue 3 is:\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++){
			if(process3[i]==queue[j])
			{
				printf("Process[%d]\n",j+1);
				fprintf(file,"Process[%d]\n",j+1);

				array[i]=j+1;
				totalTime3=totalTime3+queue[i];

			}
		}
	}
	printf("\n");
	fprintf(file,"\n");

	//calculate the waiting time for each process and the average waiting time for queue 3
	for(i=0;i<10;i++){
		waitingTime3=waitingTime3+process3[i-1];
		printf("Process [%d]'s waiting time is %d\n",array[i],waitingTime3);
		fprintf(file,"Process [%d]'s waiting time is %d\n",array[i],waitingTime3);
		totalWaitingTime3=totalWaitingTime3+waitingTime3;
	}
	printf("\n");
	fprintf(file,"\n");
	printf("The average waiting time for ready queue 3 is: %f.\n",totalWaitingTime3/10);
	fprintf(file,"The average waiting time for ready queue 3 is: %f.\n",totalWaitingTime3/10);

	printf("\n");
	printf("*****************************************************************\n");
	printf("*                 Total time for all 3 Algorithms               *\n");
	printf("*****************************************************************\n");
	printf("\n");

	fprintf(file,"\n");
	fprintf(file,"*****************************************************************\n");
	fprintf(file,"*                 Total time for all 3 Algorithms               *\n");
	fprintf(file,"*****************************************************************\n");
	fprintf(file,"\n");

	//Total time taken to process all three queues
	printf("Total time taken to process all three queues is: %f.\n", totalTime1+totalTime2+totalTime3);
	fprintf(file,"Total time taken to process all three queues is: %f.\n", totalTime1+totalTime2+totalTime3);

	fclose(file);
}



