//
//  pe13_12a.c
//  ConsoleApplication2
//
//  Created by he.b.wang on 15/8/18.
//  Copyright (c) 2015年 He Wang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 30

static void createFile(char *fileName);
static char transfer(char ch);
static char transfer_s(char ch, char str[][COL], int i, int j);

void showBitmap(void) {
    //createFile("bitmap.txt");
    char temp[ROW][COL];
    char str[COL];
    FILE *fp;
    fopen_s(&fp, "bitmap.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "could not open file bitmap.txt\n");
		exit(1);
	}
    int i = 0;
	int j = 0;
    while (fscanf_s(fp, "%s", str, COL) == 1) {
        if (j != 0 && j % COL == 0) {
            i++;
            j = 0;
        }
        temp[i][j] = str[0];
        j++;
    }
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            putc(transfer(temp[i][j]), stdout);
        }
        putc('\n', stdout);
    }
    fclose(fp);
}

void showBitmap_s(void) {
    char temp[ROW][COL];
    char str[COL];
    FILE *fp;
	//createFile("bitmap.txt");
    fopen_s(&fp, "bitmap.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "could not open file bitmap.txt\n");
		exit(1);
	}
    int i = 0;
    int j = 0;
    while (fscanf_s(fp, "%s", str, COL) == 1) {
        if (j != 0 && j % COL == 0) {
            i++;
            j = 0;
        }
        temp[i][j] = str[0];
        j++;
    }
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            
            putc(transfer(transfer_s(temp[i][j], temp, i, j)), stdout);
        }
        putc('\n', stdout);
    }
    fclose(fp);
}

static char transfer_s(char ch, char str[][COL], int i, int j) {
    int sum = 0;
    int count = 0;
    if (i -1 >= 0) {
        if (abs(str[i - 1][j] - ch) > 1) {
            sum += str[i - 1][j];
            count++;
        } else {
            return ch;
        }
    }
    if (j - 1 >= 0) {
        if (abs(str[i][j - 1] - ch) > 1) {
            sum += str[i][j - 1];
            count++;
        } else {
            return ch;
        }
    }
    if (i + 1 < ROW) {
        if (abs(str[i + 1][j] - ch) > 1) {
            sum += str[i + 1][j];
            count++;
        } else {
            return ch;
        }
    }
    if (j + 1 < COL) {
        if (abs(str[i][j + 1] - ch) > 1) {
            sum += str[i][j + 1];
            count++;
        } else {
            return ch;
        }
    }
    ch = sum / count;
    return ch;
}

static void createFile(char *fileName) {
    FILE *fp;
    time_t t = time(NULL);
    printf("%ld\n", t);
    srand(t);
    fopen_s(&fp, fileName, "w");
    if (fp == NULL) {
        fprintf(stderr, "could not open file %s\n", fileName);
        exit(1);
    }
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            fprintf(fp, "%d ", rand() % 10);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

static char transfer(char ch) {
    char c;
    switch (ch) {
    case '0':
        c = ' ';
        break;
    case '1':
        c = '.';
        break;
    case '2':
        c = '\'';
        break;
    case '3':
        c = ':';
        break;
    case '4':
        c = '~';
        break;
    case '5':
        c = '*';
        break;
    case '6':
        c = '=';
        break;
    case '7':
        c = '$';
        break;
    case '8':
        c = '%';
        break;
    case '9':
        c = '#';
        break;
    }
    return c;
}


