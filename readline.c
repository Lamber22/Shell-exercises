#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

// main - A program that prints "$ ", wait for the user to enter a command, prints it on the next line.
  
int main(int argc, char **argv)
{
	char *command = NULL;
	size_t len = 0;
	char *stkn;
	pid_t my_pid;
	int status, i;
	
	while (1)
	{
		printf("$ ");
		getline(&command, &len, stdin);

		stkn = strtok(command, "\n");

		char **arr = malloc(sizeof(char *) * 32);
		arr[0] = stkn;

		if ((strcmp(arr[0], "exit") == 0) && (arr[1] == NULL))
			exit(0);

		i = 1;
		while (stkn != NULL)
		{
			stkn = strtok(NULL, "\n");
			arr[i] = stkn;
			i++;
		}

		my_pid = fork();
		if (my_pid == -1)
		{
			perror("Error");
			return (1);
		}

		else if (my_pid == 0)
		{
			if (execve(arr[0], arr, NULL) == -1)
			{
				perror("./readline");
				return (1);
			}
			execve(arr[0], arr, NULL);
		}
		else
		{
			wait(&status);
		}

	}
	free(command);
	return (0);
}
