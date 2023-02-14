#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/**
  * main - a function that prints the parent process ID and process ID of a program
  *
  * Return: 0
  */
int main()
{
	pid_t ppid, pid;

	ppid = getppid();
	pid = getpid();

	printf("Parent process ID is %u\n", ppid);
	printf("Process ID is %u\n", pid);

	return 0;
}

