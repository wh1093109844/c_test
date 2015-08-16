#include <stdio.h>
#include <stdlib.h>
#include "pe13.h"

#define BUFFER_SIZE 1024

void showFile(int argv, char *args[]) {
	int i = 0;
	FILE *fp;
	char temp[BUFFER_SIZE];
	if (argv == 1) {
		fprintf(stderr, "using:command file1 file2...\n");
		exit(1);
	}
	while (++i < argv) {
		printf("====================open file %s====================\n", args[i]);
		fopen_s(&fp, args[i], "r");
		if (fp == NULL) {
			fprintf(stderr, "could not open file %s\n", args[i]);
			continue;
		}
		if (setvbuf(fp, NULL, _IOFBF, BUFFER_SIZE) == 0) {
			fprintf(stderr, "could not create output buffer\n");
		}
		
		while (fgets(temp, BUFFER_SIZE, fp) != NULL) {
			fputs(temp, stdout);
		}
		fclose(fp);
	}
}