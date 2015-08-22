#include <stdio.h>	
#include <stdbool.h>
#include <string.h>
#include "pe14.h"

#define MAXTITL 41		//书名最大长度 + 1
#define MAXAUTH 31		//作者名最大长度 + 1
#define MAXBOOKS 100	//最大书本数

struct book {
	char title[MAXTITL];
	char author[MAXAUTH];
	float value;
};

void showBookLibray(void) {
	struct book library;
	printf("Please enter the book title.\n");
	gets_s(library.title, MAXTITL);
	printf("Now enter the author.\n");
	gets_s(library.author, MAXAUTH);
	printf("Now enter the value.\n");
	scanf_s("%f", &library.value);
	printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
	printf("%s: \"%s\" ($%.2f) \n", library.author, library.title, library.value);
	printf("Done.\n");
}

void showBookList(void) {
	struct book library[MAXBOOKS];
	int count = 0;
	int index;
	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while (count < MAXBOOKS && gets_s(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0') {
		printf("Now enter the author.\n");
		gets_s(library[count].author, MAXAUTH);
		printf("Now enter the value.\n");
		scanf_s("%f", &library[count++].value);
		while (getchar() != '\n') {
			continue;
		}
		if (count < MAXBOOKS) {
			printf("Enter the next title.\n");
		}
	}
	if (count > 0) {
		printf("Here is the list of your books:\n");
		for (index = 0; index < count; index++) {
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
		} 
	} else {
		printf("No books?Too bad.\n");
	}

}

/**
 * 校验是否是闰年
 * return true:闰年；false:平年
 */
_Bool isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return true;
	}
	return false;
}

int getDays(YEAR year, int month) {
	int i = 0;
	int day = 0;
	MONTH m;
	while (m = year.monthList[i], m.month < month) {
		day +=m.days;
		i++;
	}
	return day;
}

void initYear(YEAR * const y, int year) {
	y->year = year;
	for (int i = 0; i < 12; i++) {
		y->monthList[i].month = i + 1;
		switch (i + 1) {
		case 1:
			y->monthList[i].days = 31;
			strcpy_s(y->monthList[i].monthName, SIZE, "January\0");
			strcpy_s(y->monthList[i].shortName, 4, "JAU\0");
			break;
		case 2:
			y->monthList[i].days = isLeapYear(year) ? 29 : 28;
			strcpy_s(y->monthList[i].monthName, SIZE, "February\0");
			strcpy_s(y->monthList[i].shortName, 4, "FEB\0");
			break;
		case 3:
			y->monthList[i].days = 31;
			strcpy_s(y->monthList[i].monthName, SIZE, "March\0");
			strcpy_s(y->monthList[i].shortName, 4, "MAR\0");
			break;
		case 4:
			y->monthList[i].days = 30;
			strcpy_s(y->monthList[i].monthName, SIZE, "April\0");
			strcpy_s(y->monthList[i].shortName, 4, "APR\0");
			break;
		case 5:
			y->monthList[i].days = 31;
			strcpy_s(y->monthList[i].monthName, SIZE, "May\0");
			strcpy_s(y->monthList[i].shortName, 4, "MAY\0");
			break;
		case 6:
			y->monthList[i].days = 30;
			strcpy_s(y->monthList[i].monthName, SIZE, "June\0");
			strcpy_s(y->monthList[i].shortName, 4, "JUN\0");
			break;
		case 7:
			y->monthList[i].days = 31;
			strcpy_s(y->monthList[i].monthName, SIZE, "July\0");
			strcpy_s(y->monthList[i].shortName, 4, "JUL\0");
			break;
		case 8:
			y->monthList[i].days = 31;
			strcpy_s(y->monthList[i].monthName, SIZE, "August\0");
			strcpy_s(y->monthList[i].shortName, 4, "AUG\0");
			break;
		case 9:
			y->monthList[i].days = 30;
			strcpy_s(y->monthList[i].monthName, SIZE, "September\0");
			strcpy_s(y->monthList[i].shortName, 4, "SEP\0");
			break;
		case 10:
			y->monthList[i].days = 31;
			strcpy_s(y->monthList[i].monthName, SIZE, "October\0");
			strcpy_s(y->monthList[i].shortName, 4, "OCT\0");
			break;
		case 11:
			y->monthList[i].days = 30;
			strcpy_s(y->monthList[i].monthName, SIZE, "November\0");
			strcpy_s(y->monthList[i].shortName, 4, "NOV\0");
			break;
		case 12:
			y->monthList[i].days = 31;
			strcpy_s(y->monthList[i].monthName, SIZE, "December\0");
			strcpy_s(y->monthList[i].shortName, 4, "DEC\0");
			break;
		}
	}
}

void getDaysInYear(void) {
	int currYear, currMonth, m;
	YEAR year;
	printf("Enter the current year: ");
	scanf_s("%d", &currYear);
	initYear(&year, currYear);
	
	printf("Enter the current month: ");

	while ((m = scanf_s("%d", &currMonth) == 1) && currMonth >= 1 && currMonth <= 12) {
		int days = getDays(year, currMonth);
		printf("between %s and %s, there are %d days, in the %d\n", year.monthList[0].monthName, year.monthList[currMonth - 1].monthName, days, currYear);
		while (getchar() != '\n') {}
	}

}