#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int alarmflag=0;

void alarmHandler ()
{
	printf("An alarm clock signal was received\n");
	alarmflag = 1;
}

int main()
{
	signal(SIGALRM, alarmHandler);
	alarm(3);
	printf("Alarm has been set\n");

	while (alarmflag==0)
	;

printf("Back from alarm signal handler\n");
}