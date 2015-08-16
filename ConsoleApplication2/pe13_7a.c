#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pe13.h"
#define BUFFER_SIZE 1024

static char * index(const char str[], char ch);

void showFileText(int argv, char *args[]) {
	FILE *fb1;
	FILE *fb2;
	char *t1;
	char *t2;
	char *t;
	char temp1[BUFFER_SIZE], temp2[BUFFER_SIZE];
	if (argv < 3) {
		fprintf(stderr, "using:command file1 file2\n");
		exit(1);
	}
	fopen_s(&fb1, args[1], "r");
	if (fb1 == NULL) {
		fprintf(stderr, "could not open file %s\n", args[1]);
		exit(2);
	}
	fopen_s(&fb2, args[2], "r");
	if (fb2 == NULL) {
		fprintf(stderr, "could not open file %s\n", args[2]);
		exit(3);
	}
	while (t1 = fgets(temp1, BUFFER_SIZE, fb1), t2 = fgets(temp2, BUFFER_SIZE, fb2), t1 != NULL || t2 != NULL) {
		if (t1 != NULL) {
			t = index(temp1, '\n');
			if (t != NULL) {
				*t = ' ';
			}
			fputs(temp1, stdout);
		}
		if (t2 != NULL) {
			fputs(temp2, stdout);
		}
	}
	fclose(fb1);
	fclose(fb2);
}

char * index(const char str[], char ch) {
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] == ch) {
			return str + i;
		}
		i++;
	}
	return NULL;
}