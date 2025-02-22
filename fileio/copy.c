#include <sys/stat.h>
#include <fcntl.h>
#include "../lib/tlpi_hdr.h"

#ifndef BUF_SIZE		/* Allow "cc -D" to override definition */
#define BUF_SIZE 1024
#endif

int main(int argc, char *argv[])
{
	int inputFd, outputFd, openFlags;
	mode_t filePerms;
	ssize_t numRead;
	char buf[BUF_SIZE];

	if (argc != 3 || strcmp(argv[1], "--help") == 0)
	{
		fprintf(stderr, "Usage: %s old-file new-file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	/* Open input and output files */

	inputFd = open(argv[1], O_RDONLY);
	if (inputFd == -1)
	{
		fprintf(stderr, "Error: opening file %s\n", argv[1]);
	}
	openFlags = O_CREAT | O_WRONLY | O_TRUNC;
	/*filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
		S_IROTH | S_IWOTH;*/ /* rw-rw-rw similar to 0666*/
	
	filePerms = 666;
	outputFd = open(argv[2], openFlags, filePerms);
	if (outputFd == -1)
	{
		fprintf(stderr, "Error: opening file %s\n", argv[2]);
	}

	/* Transfer data until we encourter end of input or an error */

	while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0)
		if (write(outputFd, buf, numRead) != numRead)
		{
			fprintf(stderr, "Fatal: write()returned error or partial write occurred\n");
			exit(EXIT_FAILURE);
		}
	if (numRead == -1)
	{
		fprintf(stderr, "Error: read");
		exit(EXIT_FAILURE);
	}
	dprintf(outputFd, "Writing to check if it works\n"); /* You can write or output error and print using dprintf */
	dprintf(1, "Hello, %s! Welcome to %s. The number %d\n", "Arinze", "dprintf", (O_RDONLY | O_WRONLY));
	if (close(inputFd) == -1)
	{
		fprintf(stderr, "Error: close input");
                exit(EXIT_FAILURE);
	}
	if (close(outputFd) == -1)
        {
                fprintf(stderr, "Error: close output");
                exit(EXIT_FAILURE);
        }

	exit(EXIT_SUCCESS);
}
