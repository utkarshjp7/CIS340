#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "minix.h"

char* imagePath;

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
			imagePath = (char *)malloc(265);
			strncpy(imagePath, strstr(input, "minimount") + 10,
					strlen(strstr(input, "minimount") + 11));

		} else if ((strstr(input, "miniunmount\n")) != NULL) {

			free(imagePath);

		} else if (strstr(input, "showsuper\n") != NULL) {

			showsuper();

		} else if (strstr(input, "traverse") != NULL) {

			char* lSwitch = (char *) malloc(3);
			lSwitch = strstr(input, "traverse") + 9;

			if (strcmp(lSwitch, "-l\n") == 0)
				traverse(1);
			else
				traverse(0);

		} else if (strstr(input, "showzone") != NULL) {

			char* zone = (char *)malloc(5);

			strncpy(zone, strstr(input, "showzone") + 9,
					strlen(strstr(input, "showzone") + 10));
			zone[sizeof(zone) - 1] = '\0';

			showzone(zone);

		} else if (strstr(input, "quit") != NULL) {
			write(1, "\nYou will now quit out of the floppy disk shell.\n", 49);
			break;
			
		} else {
			char* helpMessage =
					"Invalid Command. \nPlease type help to see the list of available commands.\n";
			write(1, helpMessage, strlen(helpMessage));
		}
		free(input);
	}

	free(welcome);

	return 0;
}
