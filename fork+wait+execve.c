#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

/**
  * main - a program that executes the command ls -l /tmp in 5 different
  * child processes
  * Return: 0
  */

int main(void)
{
	int status, i;
	pid_t my_pid;

	//looping to create the 5 processes
	for (i = 0; i < 5; i++)
	{
		my_pid = fork();
		if (my_pid != 0)
		{
			perror("Error:unable to fork\n");
			exit(1);
		}
		else if (my_pid == 0)
		{
			//creating child process
			printf("Child process: %d is executing ls -l /tmp\n", i+1);
			execve("/bin/ls", "ls", "-l", "/tmp", (char*)NULL);
			printf("Error: execve failed\n");
			exit(1);
		}
		else
		{
			//parent process
			wait(&status);
		}
	}
	return 0;
}

