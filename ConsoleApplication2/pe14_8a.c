#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "pe14.h"

#define FILE_NAME "seats.bin"

typedef struct seat {
	int no;
	_Bool isAssign;
	char surname[SIZE];			//��
	char name[SIZE];			//��
} SEAT;

void initSeatList(SEAT seatList[], int size);
void showNumberOfEmptySeats(const SEAT seatList[], int size);
void showListOfEmptySeats(const SEAT seatList[], int size);
void showAlphabeticalListOfSeats(const SEAT seatList[], int size);
void assignSeats(SEAT seatList[], int size);
void deleteSeats(SEAT seatList[], int size);
SEAT * getSeatByNo(const SEAT seatList[], int size, int no);
void copySeat(SEAT *targer, SEAT s);
void save2File(SEAT seatList[], int size);
void showMenu(void);
void cleanBuffer(void);


void assignSeatsSys(void) {
	char ch;
	SEAT seatList[SIZE];
	initSeatList(seatList, SIZE);
	showMenu();
	while ((ch = getchar()) != 'f') {
		while (getchar() != '\n') {}
		switch (ch) {
		case 'a':
			showNumberOfEmptySeats(seatList, SIZE);
			break;
		case 'b':
			showListOfEmptySeats(seatList, SIZE);
			break;
		case 'c':
			showAlphabeticalListOfSeats(seatList, SIZE);
			break;
		case 'd':
			assignSeats(seatList, SIZE);
			break;
		case 'e':
			deleteSeats(seatList, SIZE);
			break;
		}
		showMenu();
	}

}

/**
 *	��ʼ����λ��������������ļ�������ļ��ж�ȡ
 */
void initSeatList(SEAT seatList[], int size) {
	FILE *fp;
	SEAT temp;
	SEAT *temp2;
	for (int i = 0; i < size; i++) {
		seatList[i].no = i + 1;
		seatList[i].isAssign = false;
	}
	fopen_s(&fp, FILE_NAME, "r+b");
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
	printf("��ʼ����λ���\n");
}

void showNumberOfEmptySeats(const SEAT seatList[], int size) {
	SEAT temp;
	int count = 0;
	for (int i = 0; i < size; i++) {
		temp = seatList[i];
		if (!temp.isAssign) {
			count++;
		}
	}
	printf("Ŀǰ�и� %d ����λ\n", count);
}

void showListOfEmptySeats(const SEAT seatList[], int size) {
	SEAT temp;
	for (int i = 0; i < size; i++) {
		temp = seatList[i];
		if (!temp.isAssign) {
			printf("%d\n", temp.no);
		}
	}
}

void showAlphabeticalListOfSeats(SEAT seatList[], int size) {
	SEAT temp;
	int i;
	int j;
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

void assignSeats(SEAT seatList[], int size) {
	int no;
	SEAT *seat;
	FILE *fp;
	printf("������ҪԤ������λ�ţ�");
	if (scanf_s("%d", &no) == 1) {
		if (no > size || (seat = getSeatByNo(seatList, size, no)) == NULL) {
			printf("û�������λ��\n");
			printf("Ԥ�����\n");
			return;
		}
		printf("������Ԥ���˵�������");
		if (scanf_s("%s %s", seat->surname, SIZE, seat->name, SIZE) == 2) {
			seat->isAssign = true;
			save2File(seatList, size);
			printf("Ԥ�����\n");
		} else {
			printf("Ԥ��ʧ��\n");
		}
	} else {
		printf("Ԥ��ʧ��\n");
	}
	cleanBuffer();
}

void deleteSeats(SEAT seatList[], int size) {
	int no;
	SEAT *seat;
	printf("������Ҫɾ������λ��");
	if (scanf_s("%d", &no) == 1) {
		if (no > size || (seat = getSeatByNo(seatList, size, no)) == NULL) {
			printf("û�������λ��ɾ��ʧ��\n");
			return;
		}
		seat->isAssign = false;
		save2File(seatList, size);
		printf("ɾ����λ�ɹ�\n");
	} else {
		printf("û�������λ��ɾ��ʧ��\n");
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

void save2File(SEAT seatList[], int size) {
	FILE *fp;
	fopen_s(&fp, FILE_NAME, "w+b");
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