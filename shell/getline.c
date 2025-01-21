#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
	char *buffer = NULL;
	size_t bufsize = 0, i;
	ssize_t characters;
	char *tokens;
	char *array[1024];
	
	printf("Enter a line of text: ");
	characters = getline(&buffer, &bufsize, stdin);

	if (characters == -1) {
		perror("getline failed");
	} else {
		printf("$ You entered: %s", buffer);
		printf("$ Number of characters: %zd\n", characters);
	}
	tokens = strtok(buffer, " \n");
	i = 0;
	while (tokens != NULL)
	{
		//printf("%s\n", tokens);
		array[i] = tokens;

		tokens = strtok(NULL, " \n");
		i++;
	}

        for (i = 0; array[i] != NULL; i++)
        {
                printf("%s\n", array[i]);
        }
	free(buffer);
	return 0;
}
