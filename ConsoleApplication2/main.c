#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pe12.h"
#include "pe13.h"

extern int random_s(void);
extern void setNext(void);

extern void reverse(void);
void readLine(int argv, char * args[]);

int main(int argv, char * args[]) {
	//getCharNum();
	//readLine(argv, args);
	//copyFile_s();
	//showFile(argv, args);
	//appendFile(argv, args);
	//showFileText(argv, args);
	getCharNumber(argv, args);
	return 0;
}


