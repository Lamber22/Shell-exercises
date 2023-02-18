#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

  
int main(int argc, char **argv)
{
//	printing prompt and taking input from the user variable declearation
	char *command = NULL;
	size_t len = 0;
	//string token pointer variable
	char *stkn;
	pid_t my_pid;
	//wait process variable declearation
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
		//creating child process

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
				perror("./shell");
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
