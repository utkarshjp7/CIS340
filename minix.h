/*
 * minix.h
 *
 *  Created on: Oct 29, 2016
 *      Author: root
 */

#ifndef MINIX_H_
#define MINIX_H_

//Shared Global Variable
extern char imagePath[];

void help();
void minimount(char imageFilePath[]);
void miniunmount();

#endif /* MINIX_H_ */
