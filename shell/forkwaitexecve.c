#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
/**
 * main - A program that executes the command ls -l /tmp in 5 different child
 * processes
 * Each child is created by the same process the father and
 * it will wait for a child to exit before creating a new child
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	pid_t child_pid;
	int status, i = 0;

	while (i < 5)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return 1;
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error:");
		}
		else
		{
			wait(&status);
			printf("Father's PID is %u\n", getpid());
		}
		i++;
		printf("Number %d successful\n", i);
	}
	return 0;
}
