#include <stdio.h>
#include <stdlib.h>

/**
  * main - a program that prints "$ ", wait for the user to enter a command,
  * prints it on the next line.
  * Return 0
  */
int main()
{
	char *command = malloc(1024);
	size_t len = 1024;

	while (1)
	{
		printf("$ ");
		getline(&command, &len, stdin);
		printf("%s", command);
	}
	return (0);
}
