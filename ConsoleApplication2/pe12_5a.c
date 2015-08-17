#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pe12.h"

static int random(int max);

int getSize(int size) {
	int currSize;
	printf("Enter the array length");
	if (size == -1) {
		printf(": ");
	} else {
		printf(" (-1 to quit): ");
	}
	scanf_s("%d", &currSize);
	if (currSize != -1 && currSize < 0) {
		printf("Invaild number. The array's length is %d.\n", size);
		currSize = size;
	}
	return currSize;
}

int getMax(int max) {
	int currMax;
	printf("Enter the max number: ");
	scanf_s("%d", &currMax);
	if (currMax < 0) {
		printf("Invaild number. The max number is %d.\n", max);
		currMax = max;
	}
	return currMax;
}

void createRandom(int * const p, int size, int max) {
	for (int i = 0; i < size; i++) {
		p[i] = random(max);
	}
}

void sort_desc(int * const p, int size) {
	int temp;
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size - i; j++) {
			if (p[j] > p[j - 1]) {
				temp = p[j];
				p[j] = p[j - 1];
				p[j - 1] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		if (i != 0 && i % 10 == 0) {
			printf("\n");
		}
		printf("p[%4d] = %4d    ", i, p[i]);
	}
}

static int random(int max) {
	return rand() % max + 1;
}

void getRandomRate(int * const p, int size, int max, time_t speed) {
	srand(speed);
	for (int i = 0; i < size; i++) {
		int r = random(max);
		p[r - 1]++;
	}
}