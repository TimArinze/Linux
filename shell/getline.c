#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;
	char *tokens;
	
	printf("Enter a line of text: ");
	characters = getline(&buffer, &bufsize, stdin);

	if (characters == -1) {
		perror("getline failed");
	} else {
		printf("$ You entered: %s", buffer);
		printf("$ Number of characters: %zd\n", characters);
	}
	tokens = strtok(buffer, " \n");
	while (tokens != NULL)
	{
		printf("%s\n", tokens);

		tokens = strtok(NULL, " \n");
	}
	free(buffer);
	return 0;
}
