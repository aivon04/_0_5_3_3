#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler()
{
	printf("\n Caught the SIGINT signal\n");

	exit(0);
}

int main(void)
{
	//Reguster signal handler through the signal() function
	signal(SIGINT, sig_handler);

	while(1)
	{
//simulate a delay -- as if the program is doing some other stuff
	}
	return 0;
}