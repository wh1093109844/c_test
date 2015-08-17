//
// Created by he.b.wang on 15/8/17.
//
#include <stdio.h>
#include <stdlib.h>
#include "pe13.h"

#define BUFFER_SIZE 256

static int getCharNumberByString(char ch, char str[], size_t size);

void getCharNumber(int argv, char *args[]) {

    int count = 0;
    FILE *fp;
    char ch;
    char temp[BUFFER_SIZE];
	size_t bytes;
    if (argv == 1) {
        fprintf(stderr, "using:command char file1 file2...\n");
        exit(1);
    }
    ch = args[1][0];
    if (argv == 2) {
		gets_s(temp, BUFFER_SIZE);
        count = getCharNumberByString(ch, temp, BUFFER_SIZE);
        printf("the string has %d's '%c'\n", count, ch);
    } else {
        int i = 1;
        while (i++, i < argv) {
            fopen_s(&fp, args[i], "r");
            if (fp == NULL) {
                fprintf(stderr, "could not open file %s\n", args[i]);
                continue;
            }
            if (setvbuf(fp, NULL, _IOFBF, BUFFER_SIZE) != 0) {
                fprintf(stderr, "could not create %s's input buffer\n", args[i]);
            }
			
            while ((bytes = fread_s(temp, sizeof(char) * BUFFER_SIZE, sizeof(char), BUFFER_SIZE, fp)) > 0) {
                count += getCharNumberByString(ch, temp, bytes);
            }
            printf("the file %s has %d's '%c'\n", args[i], count, ch);
            fclose(fp);
        }
    }
}

static int getCharNumberByString(char ch, char str[], size_t size) {
    int i = 0;
    int count = 0;
    char c;
    while ((c = str[i]) != '\0' && i < size) {
        if (c == ch) {
            count++;
        }
		i++;
    }
    return count;
}