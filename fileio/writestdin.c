#include <unistd.h>
#include <string.h>

int main() {
	const char *message = "Writing to stdin\n";
	write(0, message, strlen(message)); // Writing to file descriptor 0 
	return 0;
}
