//
//  pe13_9a.c
//  ConsoleApplication2
//
//  Created by he.b.wang on 15/8/18.
//  Copyright (c) 2015年 He Wang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "pe13.h"

#define MAX_SIZE 41

void addWord(void) {
    FILE *fp;
    char word[MAX_SIZE];
    fp = fopen("word.txt", "a");
    if (fp == NULL) {
        fprintf(stderr, "colud not open file word.txt\n");
        exit(1);
    }
    printf("Enter words to add to the file: press the Enter");
    printf("key at the beginning of a line to terminat.\n");
    while (gets(word) != NULL && word[0] != '\0') {
        fprintf(fp, "%s ", word);
    }
    puts("file contents:");
//    rewind(fp);
    fclose(fp);
    fp = fopen("word.txt", "r");
    while (fscanf(fp, "%s", word) == 1) {
        puts(word);
    }
    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file\n");
    }
}
