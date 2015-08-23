#pragma once
#define SIZE 20

typedef struct month {
	char monthName[SIZE];
	char shortName[4];
	int days;
	int month;
} MONTH;

typedef struct year {
	MONTH monthList[12];
	int currMonth;
	int year;
} YEAR;

enum choices {
	no,
	yes,
	maybe
};

void showBookLibray(void);
void showBookList(void);
_Bool isLeapYear(int year);
int getDays(YEAR year, int month);
void getDaysInYear();
void initYear(YEAR * const y, int year);
void readFileToStruct(void);
void test(void);



