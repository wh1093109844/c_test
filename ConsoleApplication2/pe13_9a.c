//
//  pe13_9a.c
//  C_Primer_Plus_Test
//
//  Created by he.b.wang on 15/8/18.
//  Copyright (c) 2015年 He Wang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "pe13.h"

#define BUFFER_SIZE 1024

void addWord() {
    FILE *fp;
    char temp[BUFFER_SIZE];
    fp = fopen("word.txt", "a");
    if (fp == NULL) {
        fprintf(stderr, "could not open file word.txt\n");
        exit(1);
    }
    puts("Enter words to add to the file: press the Enter");
    puts("key at the beginning of a line to terminate");
    while (gets(temp) != NULL && temp[0] != '\0') {
        fprintf(fp, "%s ", temp);
    }
    puts("file contents: ");
    rewind(fp);
    while (fscanf(fp, "%s", temp) == 1) {
        puts(temp);
    }
    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file\n");
    }
}
