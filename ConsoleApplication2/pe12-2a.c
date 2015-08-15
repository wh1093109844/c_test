#include <stdio.h>
#include "pe12-2a.h"

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


