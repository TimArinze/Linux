#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
/**
 * main - A simple shell project
 *
 * Return: 0 Always
 */
#define MAX_PROMPT 20
int main(void)
{
	ssize_t characters;
	size_t bufsize = 0, i;
	char *buffer = NULL, *token;
	char **argv;
	pid_t child_pid;
	int status;

	while(1)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error with child fork: ");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("cisfun$ ");
			characters = getline(&buffer, &bufsize, stdin);
			if (characters == -1)
				perror("Error getting the prompt");
			argv = (char **)malloc(sizeof(char *) * MAX_PROMPT);
			if (argv == NULL)
				perror("Space unable to be allocated to array");
			i = 0;
			token = strtok(buffer, " \n");
			while (token != NULL)
			{
				argv[i] = malloc((strlen(token) + 1) * sizeof(char));
				strcpy(argv[i], token);
				token = strtok(NULL, " \n");
				i++;
			}
			free(buffer);
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error:");
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
