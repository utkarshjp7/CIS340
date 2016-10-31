#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include"minix.h"

void help() {
	char* help = "Print command descriptions\n"; //TODO for dequane
	write(1, help, strlen(help));
    printf("1. help: Display available commands.\n");
    printf("2. minimount (fileName): Mount image file.\n");
    printf("3. miniumount: Unmount the mounted floppy disk. \n");
    printf("4. showsuper: List information of super block.\n");
    printf("5. traverse [-l]: Show the contents in the root directory. Optional -l flag gives detailed information of the root directory.\n");
    printf("6. showzone (zone_number): Show ASCII content of zone (zone_number).\n");
    printf("7. showfile (filename): Show content of target file. \n");	
    printf("8. quit: Quit the minix shell. \n");
 	//free(help);
}

void minimount(char x[]) {
	//TODO for dequane
	write(1, x, strlen(x));
}

void miniunmount() {
//use imagePath global variable to unmount the disk

//TODO for dequane
	write(1, imagePath, strlen(imagePath));
}

void showsuper() {
	char* buf = (char *) malloc(BLOCK_SIZE);

	char imagePath[] = "imagefile.img";
	int fd = open(imagePath, O_RDONLY);
	lseek(fd, 1024, SEEK_SET);
	read(fd, buf, BLOCK_SIZE); //1024 to 2047 //2nd block
	struct minix_super_block* super = (struct minix_super_block *) buf;

	char* temp = (char *) malloc(4);
	write(1, "number of inodes: 	", 19);
	itoa(temp, super->s_ninodes);
	write(1, temp, 4);
	write(1, "\n", 1);

	temp = (char *) malloc(4);
	write(1, "number of zones: 	", 18);
	itoa(temp, super->s_nzones);
	write(1, temp, 4);
	write(1, "\n", 1);

	temp = (char *) malloc(4);
	write(1, "number of imap_blocks: 	", 24);
	itoa(temp, super->s_imap_blocks);
	write(1, temp, 4);
	write(1, "\n", 1);

	temp = (char *) malloc(4);
	write(1, "number of zmap_blocks: 	", 24);
	itoa(temp, super->s_zmap_blocks);
	write(1, temp, 4);
	write(1, "\n", 1);

	temp = (char *) malloc(4);
	write(1, "first data zone: 	", 18);
	itoa(temp, super->s_firstdatazone);
	write(1, temp, 4);
	write(1, "\n", 1);

	temp = (char *) malloc(4);
	write(1, "log zone size: 	        ", 24);
	itoa(temp, super->s_log_zone_size);
	write(1, temp, 4);
	write(1, "\n", 1);

	temp = (char *) malloc(4);
	write(1, "max size: 	        ", 19);
	itoa(temp, super->s_max_size);
	write(1, temp, 4);
	write(1, "\n", 1);

	temp = (char *) malloc(4);
	write(1, "magic: 	                ", 24);
	itoa(temp, super->s_magic);
	write(1, temp, 4);
	write(1, "\n", 1);

	temp = (char *) malloc(4);
	write(1, "state: 	                ", 24);
	itoa(temp, super->s_state);
	write(1, temp, 4);
	write(1, "\n", 1);

	temp = (char *) malloc(4);
	write(1, "zones: 	                ", 24);
	itoa(temp, super->s_zones);
	write(1, temp, 4);
	write(1, "\n", 1);

	close(fd);
}

void traverse(int showMore) {

	char imagePath[] = "imagefile.img";
	char* buf = (char *) malloc(32);
	char* buf2 = (char *) malloc(32);

	struct minix_dir_entry* dir;
	int fd = open(imagePath, O_RDONLY);

	lseek(fd, BLOCK_SIZE * 5, SEEK_SET); //set pointer to the first inode block (i.e 5th block, i.e root inode)
	read(fd, buf, 32); 		   //read root inode
	struct minix_inode* rootInode = (struct minix_inode *) buf;
	free(buf);

	buf = (char *) malloc(16);
	int i, j;

	for (i = 0; i < 7; i++) { //loop through every zone
		for (j = 0; j < BLOCK_SIZE; j = j + 16) { //loop through every two byte in each block
			if (rootInode->i_zone[i] == '\0')
				break;
			else
				lseek(fd, (rootInode->i_zone[i] * BLOCK_SIZE) + j, SEEK_SET); //set pointer to the begining of data block

			read(fd, buf, 16);
			if (strlen(buf) > 0) {
				dir = (struct minix_dir_entry *) buf;
				if (strcmp(dir->name, ".") != 0
						&& strcmp(dir->name, "..") != 0) {

					char* name = (char *)malloc(100);
					name = dir->name;

					if (showMore == 1) {
						int pointer = (BLOCK_SIZE * 5) + (dir->inode - 1) * 32;
						lseek(fd, pointer, SEEK_SET);
						read(fd, buf2, 32);
						struct minix_inode* inode = (struct minix_inode *) buf2;

						char* stringToPrint = (char *) malloc(100);
						char* temp = (char *) malloc(8);

						processImode(inode->i_mode, stringToPrint); //permission bytes and file type

						strcat(stringToPrint, " ");

						itoa(temp, inode->i_uid);
						strcat(stringToPrint, temp); //user id
						strcat(stringToPrint, " ");

						temp = (char *) malloc(4);
						itoa(temp, inode->i_size);
						strcat(stringToPrint, temp); //file size
						strcat(stringToPrint, " ");

						temp = (char *) malloc(12);
						convertTime(inode->i_time, temp);
						strcat(stringToPrint, temp);
						strcat(stringToPrint, " ");
						strcat(stringToPrint, name);

						write(1, stringToPrint, strlen(stringToPrint));
						write(1, "\n", 1);
					}
					else{
						write(1, name, strlen(name));
						write(1, "\n", 1);
					}
				}
			}
		}
	}

	close(fd);
}

//helper functions

void processImode(int a, char* returnString) {

	char* binaryString = (char *) malloc(17);
	char* permissionBytes = (char *) malloc(10);

	binaryString = binaryString + 15;

	int i = 0;
	for (i = 15; i >= 0; i--) {
		*binaryString-- = (a & 1) + '0';

		a >>= 1;
	}
	binaryString += 1;
	permissionBytes = binaryString + 7;
	if (binaryString[0] == '1')
		strcat(returnString, "-"); //regular File
	else if (binaryString[1] == '1')
		strcat(returnString, "d"); //directory

	processPermissionBytes(permissionBytes, returnString);
}

void processPermissionBytes(char* permissionBytes, char* returnString) {
	int i, j = 0;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if ((j == 0) && (permissionBytes[(i * 3) + j] == '1'))
				strcat(returnString, "r");
			else if ((j == 1) && (permissionBytes[(i * 3) + j] == '1'))
				strcat(returnString, "w");
			else if ((j == 2) && (permissionBytes[(i * 3) + j] == '1'))
				strcat(returnString, "x");
			else
				strcat(returnString, "-");
		}
	}
}

void convertTime(int seconds, char* returnString) {
	int elpasedDays = seconds / SECONDS_IN_A_DAY;
	int elpasedYears = ((elpasedDays / DAYS_IN_FOUR_YEARS) * 4)
			+ ((elpasedDays % DAYS_IN_FOUR_YEARS) / 365);
	int year = 1970 + elpasedYears;

	int daysInCurrentYear = ((elpasedDays % DAYS_IN_FOUR_YEARS) % 365) + 1;
	char* month = (char *) malloc(4);
	char* temp = (char *) malloc(8);

	int leap = 0;
	if (year % 4 == 0)
		leap = 1;

	int day = 0;
	if (daysInCurrentYear <= 31) {
		day = daysInCurrentYear;
		month = "Jan";
	} else if (daysInCurrentYear <= 59 + leap) {
		day = daysInCurrentYear - 31;
		month = "Feb";
	} else if (daysInCurrentYear <= 90 + leap) {
		day = daysInCurrentYear - 59 - leap;
		month = "Mar";
	} else if (daysInCurrentYear <= 120 + leap) {
		day = daysInCurrentYear - 90 - leap;
		month = "Apr";
	} else if (daysInCurrentYear <= 151 + leap) {
		day = daysInCurrentYear - 120 - leap;
		month = "May";
	} else if (daysInCurrentYear <= 181 + leap) {
		day = daysInCurrentYear - 151 - leap;
		month = "Jun";
	} else if (daysInCurrentYear <= 212 + leap) {
		day = daysInCurrentYear - 181 - leap;
		month = "Jul";
	} else if (daysInCurrentYear <= 243 + leap) {
		day = daysInCurrentYear - 212 - leap;
		month = "Aug";
	} else if (daysInCurrentYear <= 273 + leap) {
		day = daysInCurrentYear - 243 - leap;
		month = "Sep";
	} else if (daysInCurrentYear <= 304 + leap) {
		day = daysInCurrentYear - 273 - leap;
		month = "Oct";
	} else if (daysInCurrentYear <= 334 + leap) {
		day = daysInCurrentYear - 304 - leap;
		month = "Nov";
	} else {
		day = daysInCurrentYear - 334 - leap;
		month = "Dec";
	}
	strcat(returnString, month);
	strcat(returnString, " ");
	itoa(temp, day);
	strcat(returnString, temp);
	strcat(returnString, " ");
	itoa(temp, year);
	strcat(returnString, temp);
	strcat(returnString, " ");

}

void itoa(char *s, int x) {
	char *p = s;

	unsigned t = x;

	do {
		*p++ = '0' + t % 10;
		t /= 10;
	} while (t);

	while (s < --p) {
		char t = *s;
		*s++ = *p;
		*p = t;
	}
}
