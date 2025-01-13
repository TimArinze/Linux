#include <stdio.h>
#include <unistd.h>
/**
 * main - execve example
 *
 * Return: Always 0
 */
int main(void)
{
	printf("Before the execve system call the process ID: %d\n", getpid());
	char *argv[] = {"./getline", NULL};

	if (execve(argv[0], argv, NULL) == -1)
		perror("Error: ");
	printf("After execve the process PID: %d\n", getpid());
	return (0);
}
