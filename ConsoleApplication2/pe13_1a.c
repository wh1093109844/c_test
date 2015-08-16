#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pe13.h"

#define SIZE 81

void getCharNum(void) {
	char fileName[SIZE];
	FILE *fp;
	char ch;
	int count = 0;
	printf("Enter the file name: ");
	gets_s(fileName, SIZE);
	fopen_s(&fp, fileName, "r");
	if (fp == NULL) {
		fprintf(stderr, "Could not open file %s\n", fileName);
		exit(1);
	}
	while ((ch = getc(fp)) != EOF) {
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("the file %s has %d char.\n", fileName, count);
}

void copyFile(int argv, char *args[]) {
	FILE *source, *targer;
	char temp[SIZE];
	size_t bytes;
	if (argv < 3) {
		fprintf(stderr, "using:command source targer\n");
		exit(1);
	}
	if (strcmp(args[1], args[2]) == 0) {
		fprintf(stderr, "could not copy file to itself.\n");
		exit(4);
	}
	fopen_s(&source, args[1], "r");
	if (source == NULL) {
		fprintf(stderr, "Could not open source file %s\n", args[1]);
		exit(2);
	}
	fopen_s(&targer, args[2], "w");
	if (targer == NULL) {
		fprintf(stderr, "Could not open targer file %s\n", args[2]);
		exit(3);
	}
	while ((bytes = fread(temp, sizeof(char), SIZE, source)) != 0) {
		puts(temp);
		fwrite(temp, sizeof(char), bytes, targer);
	}
	fclose(targer);
	fclose(source);
}

void copyFile_s() {
	char sourceName[SIZE], targerName[SIZE];
	FILE *source, *targer;
	char ch;
	printf("Enter the source file name:");
	gets(sourceName);
	fopen_s(&source, "main.c", "r");
	if (source == NULL) {
		fprintf(stderr, "could not open source file %s\n", sourceName);
		exit(1);
	}
	printf("Enter the targer file name:");
	gets(targerName, SIZE);
	if (strcmp(sourceName, targerName) == 0) {
		fprintf(stderr, "could not copy file to itself.\n");
		fclose(source);
		exit(2);
	}
	fopen_s(&targer, targerName, "w");
	if(targer == NULL) {
		fprintf(stderr, "could not open targer file %s\n", targerName);
		fclose(source);
		exit(3);
	}
	while ((ch = fgetc(source)) != EOF) {
		ch = toupper(ch);
		fputc(ch, targer);
	}
	printf("copy %s to %s done.\n", sourceName, targerName);
}
