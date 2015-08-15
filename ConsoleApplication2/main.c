#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pe12-2a.h"
#include "pe12_5a.h"
#include "pe13.h"

#define SIZE 1024
#define CNTL_Z '\032'

extern int random(void);
extern void setNext(void);
void test_malloc(void);
void test_pe12(void);
void test_pe12_5a(void);
void test_pe12_6a(void);
void show_array(int const * const p, int size);
extern void reverse(void);
void readLine(int argv, char * args[]);

int main(int argv, char * args[]) {
	getCharNum();
	//readLine(argv, args);
	copyFile_s();
	return 0;
}

void test_malloc(void) {
	double * ptd;
	int max;
	int number;
	int i = 0;

	fputs("What is the maximum number of type double entries?", stdout);
	scanf_s("%d", &max);
	ptd = (double *)malloc(max * sizeof(double));
	if (ptd == NULL) {
		fputs("Memory allocation failed. Goodbay.", stdout);
		exit(EXIT_FAILURE);
	}
	puts("Enter the values(q to quit):");
	while (i < max && scanf_s("%lf", &ptd[i]) == 1) {
		i++;
	}
	printf("Here are your %d entries:\n", number = i);
	for (i = 0; i < number; i++) {
		printf("%7.2f ", ptd[i]);
		if (i % 7 == 6) {
			putchar('\n');
		}
	}
	if (i % 7 != 0) {
		putchar('\n');
	}
	puts("Done.");
	free(ptd);
}

void test_pe12(void) {
	int mode;
	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf_s("%d", &mode);
	while (mode >= 0) {
		set_mode(mode);
		get_info();
		show_info();
		printf("Enter 0 for metric mode, 1 for US mode");
		printf(" (-1 to quit)£º ");
		scanf_s("%d", &mode);
	}
	printf("Done.\n");
}

void test_pe12_5a(void) {
	int size = -1;
	while (size = getSize(size), size != -1) {
		int * p = malloc(size * sizeof(int));
		int max = 10;
		max = getMax(max);
		createRandom(p, size, max);
		sort_desc(p, size);
		free(p);
	}
	printf("Done.\n");
}

void test_pe12_6a(void) {
	int size = -1;
	while (size = getSize(size), size != -1) {
		int max = 10;
		max = getMax(max);
		for (int i = 1; i <= max; i++) {
			printf("  %3d  ", i);
		}
		printf("\n\n");
		for (int i = 0; i < 10; i++) {
			int * p = calloc(max, sizeof(int));
			time_t speed = time(0) + i;
			getRandomRate(p, size, max, speed);
			show_array(p, max);
			free(p);
		}
	}
	printf("Done.\n");
}

void show_array(int const * const p, int size) {
	for (int i = 0; i < size; i++) {
		printf("  %3d  ", p[i]);
	}
	printf("\n\n");
}

void readLine(int argv, char * args[]) {
	char file[SIZE];
	char ch;
	FILE *fp;
	long count, last;
	if (argv < 3) {
		fprintf(stderr, "using:command string fileName\n");
		exit(2);
	}
	if (fopen_s(&fp, args[2], "r") == NULL) {
		printf("reverse can't open %s.\n", args[2]);
		exit(1);
	}
	while (fgets(file, SIZE, fp) != NULL) {
		if (strstr(file, args[1]) != NULL) {
			fputs(file, stdout);
		}
	}
	putchar('\n');
	fclose(fp);
}