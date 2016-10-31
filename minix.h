/*
 * minix.h
 *
 *  Created on: Oct 29, 2016
 *      Author: root
 */

#ifndef MINIX_H_
#define MINIX_H_

#define BLOCK_SIZE 1024
#define SECONDS_IN_A_DAY 86400
#define DAYS_IN_FOUR_YEARS 1461

//Shared Global Variable
extern char imagePath[];

//struct

struct minix_super_block {
	unsigned short s_ninodes;
	unsigned short s_nzones;
	unsigned short s_imap_blocks;
	unsigned short s_zmap_blocks;
	unsigned short s_firstdatazone;
	unsigned short s_log_zone_size;
	unsigned int s_max_size;
	unsigned short s_magic;
	unsigned short s_state;
	unsigned int s_zones;
};

struct minix_inode
{
	unsigned short i_mode;
	unsigned short i_uid;
	unsigned int i_size;
	unsigned int i_time;
	unsigned char i_gid;
	unsigned char i_nlinks;
	unsigned short i_zone[9];
};

struct minix_dir_entry
{
	unsigned short inode; // i number of file
	char name[0]; //name of file
};

void help();
void minimount(char imageFilePath[]);
void miniunmount();
void showsuper();
void traverse(int showMore);

//helper functions
void itoa(char *s, int x);
void processImode(int a, char* returnString);
void processPermissionBytes(char* permissionBytes, char* returnString);
void convertTime(int seconds, char* returnString);

#endif /* MINIX_H_ */
