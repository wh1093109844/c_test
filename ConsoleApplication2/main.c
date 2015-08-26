#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "pe12.h"
#include "pe13.h"
#include "pe14.h"

extern int random_s(void);
extern void setNext(void);

extern void reverse(void);
void readLine(int argv, char * args[]);
void showArray(double targer[], int size);

int main(int argv, char * args[]) {
	//getCharNum();
	//readLine(argv, args);
	//copyFile_s();
	//showFile(argv, args);
	//appendFile(argv, args);
	//showFileText(argv, args);
//    addWord();
    //showBitmap_s();
	//showBookList();
	//getDaysInYear();
	//readFileToStruct();
	//test();
	//assignSeatsSys();
	//assignFlight();
	double source[100];
	double targer[100];
	rand(time(0));
	int i;
	for (i = 0; i < 100; i++) {
		source[i] = i;
	}
	transform(source, targer, 100, sin);
	showArray(targer, 100);
	transform(source, targer, 100, cos);
	printf("==================================================\n");
	showArray(targer, 100);
	transform(source, targer, 100, tan);
	printf("==================================================\n");
	showArray(targer, 100);
	return 0;
}

void showArray(double targer[], int size) {
	static int i = 0;
	for (i = 0; i < size; i++) {
		printf("%+6.3lf  ", targer[i]);
		if ((i + 1) % 10 == 0) {
			putchar('\n');
		}
	}
}


