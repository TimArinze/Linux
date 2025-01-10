#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../lib/tlpi_hdr.h"
/**
 * main -PID
 *
 * Return: Always 0
 */
int main(void)
{
	int openFd, numread;
	char buf[1024];
	pid_t my_pid = getpid();
	pid_t parent_pid = getppid();

	printf("My PID is %u\n", my_pid);
	printf("The parent PID is %u\n", parent_pid);

	openFd = open("/proc/sys/kernel/pid_max", O_RDONLY);

	numread = read(openFd, buf, sizeof(buf) - 1);

	buf[numread] = '\0';

	dprintf(1, "The max value of PID is %s\n", buf);
	close(openFd);

	return 0;
}
