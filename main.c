#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "minix.h"

char imagePath[100];

int main() {

	char *welcome = "Welcome to the minix console\n";
	write(1, welcome, strlen(welcome));

	while (1) {
		char *input = (char *) malloc(100000);
		write(1, "minix>>", 7);
		read(0, input, 100000);

		if (strcmp(input, "help\n") == 0) {
			help();
		} else if (strstr(input, "minimount") != NULL) {

			strncpy(imagePath, strstr(input, "minimount") + 10, strlen(strstr(input, "minimount") + 10));
			imagePath[sizeof(imagePath) - 1] = '\0';

			minimount(imagePath);

		} else if ((strstr(input, "miniunmount")) != NULL) {

			miniunmount();
		}
		else{
			char* helpMessage = "Invalid Command. \nPlease type help to see the list of available commands.\n";
			write(1, helpMessage, strlen(helpMessage));
		}
		free(input);
	}

	free(welcome);

	return 0;
}