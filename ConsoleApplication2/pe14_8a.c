#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "pe14.h"

#define FILE_NAME "seats.bin"

typedef struct seat {
	int no;
	_Bool isAssign;
	char surname[SIZE];			//��
	char name[SIZE];			//��
} SEAT;

typedef struct flight {
	int no;
	SEAT seatList[SIZE];
} FLIGHT;

void initSeatList(SEAT seatList[], int size, const char fileName[]);
void initFlight(FLIGHT *flight, int no);
void showNumberOfEmptySeats(const SEAT seatList[], int size, int no);
void showListOfEmptySeats(const SEAT seatList[], int size, int no);
void showAlphabeticalListOfSeats(const SEAT seatList[], int size, int no);
void assignSeats(SEAT seatList[], int size, int no);
void deleteSeats(SEAT seatList[], int size, int no);
SEAT * getSeatByNo(const SEAT seatList[], int size, int no);
void copySeat(SEAT *targer, SEAT s);
void save2File(SEAT seatList[], int size, char *fileName);
void showMenu(void);
void cleanBuffer(void);
char * number2String(int number);
char * getFileNameByNo(int no);
FLIGHT * getChoiseFight(FLIGHT flightList[], int size, int no);
void assignSeatsSys(FLIGHT *flight);


void assignFlight(void) {
	FLIGHT flightList[4];
	int no;

	FLIGHT *flight;

	initFlight(&flightList[0], 102);
	initFlight(&flightList[1], 311);
	initFlight(&flightList[2], 444);
	initFlight(&flightList[3], 519);

	while (printf("��ѡ�񺽰ࣺ"), scanf_s("%d", &no) == 1) {
		cleanBuffer();
		flight = getChoiseFight(flightList, 4, no);
		if (flight == NULL) {
			printf("%d ���಻���ڣ�Ŀǰ�� 102��311��444 �� 519 4�˺���.\n", no);
			continue;
		}
		assignSeatsSys(flight);
	}
}

FLIGHT * getChoiseFight(FLIGHT flightList[], int size, int no) {
	FLIGHT *p = NULL;
	for (int i = 0; i < size; i++) {
		if (flightList[i].no == no) {
			p = &flightList[i];
			break;
		}
	}
	return p;
}

void assignSeatsSys(FLIGHT *flight) {
	char ch;
	initSeatList(flight->seatList, SIZE, getFileNameByNo(flight->no));
	showMenu();
	while ((ch = getchar()) != 'f') {
		while (getchar() != '\n') {}
		switch (ch) {
		case 'a':
			showNumberOfEmptySeats(flight->seatList, SIZE, flight->no);
			break;
		case 'b':
			showListOfEmptySeats(flight->seatList, SIZE, flight->no);
			break;
		case 'c':
			showAlphabeticalListOfSeats(flight->seatList, SIZE, flight->no);
			break;
		case 'd':
			assignSeats(flight->seatList, SIZE, flight->no);
			break;
		case 'e':
			deleteSeats(flight->seatList, SIZE, flight->no);
			break;
		}
		showMenu();
	}

}

/**
 *	��ʼ����λ��������������ļ�������ļ��ж�ȡ
 */
void initSeatList(SEAT seatList[], int size, const char fileName[]) {
	FILE *fp;
	SEAT temp;
	SEAT *temp2;
	for (int i = 0; i < size; i++) {
		seatList[i].no = i + 1;
		seatList[i].isAssign = false;
	}
	fopen_s(&fp, fileName, "r+b");
	if (fp != NULL) {
		while (fread(&temp, sizeof(SEAT), 1, fp) == 1) {
			temp2 = getSeatByNo(seatList, size, temp.no);
			if (temp2 != NULL) {
				temp2->isAssign = temp.isAssign;
				strcpy_s(temp2->name, SIZE, temp.name);
				strcpy_s(temp2->surname, SIZE, temp.surname);
			}
		}
		fclose(fp);
	}
}

void showNumberOfEmptySeats(const SEAT seatList[], int size, int no) {
	SEAT temp;
	int count = 0;
	for (int i = 0; i < size; i++) {
		temp = seatList[i];
		if (!temp.isAssign) {
			count++;
		}
	}
	printf("%d ����Ŀǰ�и� %d ����λ\n", no, count);
}

void showListOfEmptySeats(const SEAT seatList[], int size, int no) {
	SEAT temp;
	printf("%d ����Ŀǰ��λ���£�\n", no);
	for (int i = 0; i < size; i++) {
		temp = seatList[i];
		if (!temp.isAssign) {
			printf("%d\n", temp.no);
		}
	}
}

void showAlphabeticalListOfSeats(SEAT seatList[], int size, int no) {
	SEAT temp;
	int i;
	int j;
	printf("%d ������λԤ�����������ʾ��\n", no);
	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (!seatList[j].isAssign) {
				continue;
			}
			if (!seatList[i].isAssign || strcmp(seatList[i].surname, seatList[j].surname) > 0) {
				copySeat(&temp, seatList[i]);
				copySeat(&seatList[i], seatList[j]);
				copySeat(&seatList[j], temp);
			}
		}
	}
	for (i = 0; i < size; i++) {
		if (seatList[i].isAssign) {
			printf("%2d  %10s  %10s\n", seatList[i].no, seatList[i].surname, seatList[i].name);
		}
	}
}

void assignSeats(SEAT seatList[], int size, int no) {
	SEAT *seat;
	FILE *fp;
	int num;
	printf("�������� %d �а���ҪԤ������λ�ţ�", no);
	if (scanf_s("%d", &num) == 1) {
		if (num > size || (seat = getSeatByNo(seatList, size, num)) == NULL) {
			printf("%d ����û�������λ��\n", no);
			printf("Ԥ��ʧ��\n");
			return;
		}
		printf("������Ԥ���˵�������");
		if (scanf_s("%s %s", seat->surname, SIZE, seat->name, SIZE) == 2) {
			seat->isAssign = true;
			save2File(seatList, size, getFileNameByNo(no));
			printf("��Ԥ���� %d ������λԤ�����\n", no);
		} else {
			printf("��Ԥ���� %d ����Ԥ��ʧ��\n", no);
		}
	} else {
		printf("��Ԥ���� %d ����Ԥ��ʧ��\n", no);
	}
	cleanBuffer();
}

void deleteSeats(SEAT seatList[], int size, int no) {
	SEAT *seat;
	int num;
	printf("������ %d ����Ҫɾ������λ��", no);
	if (scanf_s("%d", &num) == 1) {
		if (num > size || (seat = getSeatByNo(seatList, size, num)) == NULL) {
			printf("%d ����û�������λ��ɾ��ʧ��\n", no);
			return;
		}
		seat->isAssign = false;
		save2File(seatList, size, getFileNameByNo(no));
		printf("ɾ�� %d ������λ�ɹ�\n", no);
	} else {
		printf("%d ����û�������λ��ɾ��ʧ��\n", no);
	}
	cleanBuffer();
}

SEAT * getSeatByNo(const SEAT seatList[], int size, int no) {
	SEAT *seat = NULL;
	for (int i = 0; i < size; i++) {
		if (seatList[i].no == no) {
			seat = &seatList[i];
			break;
		}
	}
	return seat;
}

void copySeat(SEAT *targer, SEAT s) {
	targer->no = s.no;
	targer->isAssign = s.isAssign;
	if (s.isAssign) {
		strcpy_s(targer->name, SIZE, s.name);
		strcpy_s(targer->surname, SIZE, s.surname);
	}
}

void save2File(SEAT seatList[], int size, const char *fileName) {
	FILE *fp;
	fopen_s(&fp, fileName, "w+b");
	for (int i = 0; i < size; i++) {
		if (seatList[i].isAssign) {
			fwrite(&seatList[i], sizeof(SEAT), 1, fp);
		}
	}
	fclose(fp);
}

void showMenu(void) {
	printf("To choose a function enter its letter lable:\n");
	printf("a) show number of empty seats\n");
	printf("b) show list of empty seats\n");
	printf("c) show alphabetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assigment\n");
	printf("f) Quit\n");
}

void cleanBuffer(void) {
	while (getchar() != '\n') {}
}

void initFlight(FLIGHT *flight, int no) {
	flight->no = no;
	initSeatList(flight->seatList, SIZE, getFileNameByNo(no));
}

char * number2String(int number) {
	int i = 1;
	while (number / powl(10, i) >= 1) {
		i++;
	}
	i++;
	char *p = malloc(sizeof(char) * i);
	p[i - 1] = '\0';
	while (number >= 1) {
		p[i - 2] = number % 10 + '0';
		number = number / 10;
		i--;
	}
	
	return p;
}

char * getFileNameByNo(int no) {
	char *str1 = number2String(no);
	int length = strlen(str1) + 5;
	char *p = malloc(sizeof(char) * length);
	strcpy_s(p, length, str1);
	strcat_s(p, length, ".txt");
	p[length - 1] = '\0';
	return p;
}