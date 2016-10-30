#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include"minix.h"

void help() {
	char* help = "Print command descriptions\n"; //TODO for dequane
	write(1, help, strlen(help));

	//free(help);
}

void minimount(char x[]) {
	//TODO for dequane
	
}

void miniunmount() {
//use imagePath global variable to unmount the disk

//TODO for dequane
	
}
