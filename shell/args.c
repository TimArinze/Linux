#include <stdio.h>


int main(int argc, char **argv)
{

	while (*argv != NULL)
	{
		printf("%s ", *argv);
		argv++;
	}
	printf("\n");
	return 0;
}
