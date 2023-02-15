#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/**
  * main -  a function that splits a string and returns an array of
  * each word of the string.
  * Return 0
  */
int main()
{
	char *command = malloc(1024);
	size_t len = 1024;
	char *token;

	while (1)
	{
		printf("$s ");
		getline(&command, &len, stdin);
		printf("command getline: %s", command);

		token = strtok(command, "\n");
		while (token)
		{
			printf("command strtok: %s\n", token);
			token = strtok(NULL, "\n");
		}
	}
	return (0);
}
