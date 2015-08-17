#include <stdio.h>
#include "pe12.h"

#define SIZE 1024
#define CNTL_Z '\032'

static void get_us_info();
static void get_metric_info();

static void show_us_info();
static void show_metric_info();

static int model = 0;			//ģʽ
static double kilometers;
static double liters;
static double miles;
static double gallon;

static char *US = "US";
static char *METRIC = "metric";

void set_mode(int mode) {
	if (mode == 1 || mode == 0) {
		model = mode;
	} else {
		char * p = US;
		if (model == 0) {
			p = METRIC;
		}
		printf("Invalid mode specified. Mode 1 (%s) used.\n", p);
	}
}

void get_info() {
	if (model == 1) {
		get_us_info();
	} else {
		get_metric_info();
	}
}

void show_info() {
	if (model == 1) {
		show_us_info();
	} else {
		show_metric_info();
	}

}

static void get_us_info() {
	printf("Enter distance traveled in miles:");
	scanf_s("%lf", &miles);
	printf("Enter fuel consumed in gallons:");
	scanf_s("%lf", &gallon);
}

static void get_metric_info() {
	printf("Enter distance traveled in kilometers:");
	scanf_s("%lf", &kilometers);
	printf("Enter fuel consumed in liters:");
	scanf_s("%lf", &liters);
}

static void show_us_info() {
	double avg = miles / gallon;
	printf("Fuel consumption is %.1lf miles per gallon.\n", avg);
}

static void show_metric_info() {
	double avg = 100 * liters / kilometers;
	printf("Fuel consumption is %.1lf liters per 100 km.\n", avg);
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
		printf(" (-1 to quit)�� ");
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
	FILE *fp;
	if (argv < 3) {
		fprintf(stderr, "using:command string fileName\n");
		exit(2);
	}
	fopen_s(&fp, args[2], "r");
	if (fp == NULL) {
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


