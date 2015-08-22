#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pe14.h"

typedef struct team_info {
	int no;						//编号
	char surname[SIZE];			//姓
	char name[SIZE];			//名
	int playNumber;				//上场次数
	int hitNumber;				//击中次数
	int goBaseNumber;			//走垒次数
	int runPointNumber;			//跑点次数
	double successRate;			//成功率
} TEAMINFO;

static TEAMINFO * getTeamInfoByNo(const TEAMINFO infoList[], int size, int no);
static void initTeamInfo(TEAMINFO * const tinfo);
static void getSuccessRate(TEAMINFO * const info);
static TEAMINFO addTeamInfo(TEAMINFO t1, TEAMINFO t2);

void readFileToStruct(void) {
	TEAMINFO infoList[19];
	TEAMINFO temp;
	TEAMINFO *tinfo;
	FILE *fp;
	int i = 0;
	fopen_s(&fp, "data.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "could not open file data.txt\n");
		exit(1);
	}

	for (i = 0; i < 19; i++) {
		initTeamInfo(&infoList[i]);
	}
	i = 0;
	initTeamInfo(&temp);
	while (fscanf_s(fp, "%d %s %s %d %d %d %d", &temp.no, temp.surname, SIZE, temp.name, SIZE, &temp.playNumber, &temp.hitNumber, &temp.goBaseNumber, &temp.runPointNumber) == 7) {
		tinfo = getTeamInfoByNo(infoList, 19, temp.no);
		if (tinfo->no == -1) {
			tinfo->no = temp.no;
			strcpy_s(tinfo->surname, SIZE, temp.surname);
			strcpy_s(tinfo->name, SIZE, temp.name);
		}
		tinfo->playNumber += temp.playNumber;
		tinfo->hitNumber += temp.hitNumber;
		tinfo->goBaseNumber += temp.goBaseNumber;
		tinfo->runPointNumber += temp.runPointNumber;
		i++;
	}

	printf("%20s  %20s  %20s  %20s  %20s  %20s  %20s  %20s\n", "编号", "姓", "名", "上场次数", "击中数", "走垒数", "跑点数", "成功率");
	tinfo = malloc(sizeof(TEAMINFO));
	initTeamInfo(tinfo);
	for (i = 0; temp = infoList[i], temp.no != -1; i++) {
		getSuccessRate(&temp);
		printf("%20d  %20s  %20s  %20d  %20d  %20d  %20d  %20.2lf\n", temp.no, temp.surname, temp.name, temp.playNumber, temp.hitNumber, temp.goBaseNumber, temp.runPointNumber, temp.successRate);
		*tinfo = addTeamInfo(*tinfo, temp);
	}
	printf("%20s  %20s  %20s  %20d  %20d  %20d  %20d  %20s\n", "", "", "", (*tinfo).playNumber, (*tinfo).hitNumber, (*tinfo).goBaseNumber, (*tinfo).runPointNumber, "");
	free(tinfo);
	fclose(fp);
}

static TEAMINFO * getTeamInfoByNo(const TEAMINFO infoList[], int size, int no) {
	TEAMINFO *tinfo = NULL;
	for (int i = 0; i < size; i++) {
		if (infoList[i].no == -1 || infoList[i].no == no) {
			tinfo = &infoList[i];
			break;
		}
	}
	return tinfo;
}

static void initTeamInfo(TEAMINFO * const tinfo) {
	tinfo->no = -1;
	tinfo->playNumber = 0;
	tinfo->hitNumber = 0;
	tinfo->goBaseNumber = 0;
	tinfo->runPointNumber = 0;
	tinfo->successRate = 0;
}

static void getSuccessRate(TEAMINFO * const info) {
	info->successRate = (double)info->hitNumber / (double)info->playNumber;
}

static TEAMINFO addTeamInfo(TEAMINFO t1, TEAMINFO t2) {
	TEAMINFO t;
	t.playNumber = t1.playNumber + t2.playNumber;
	t.hitNumber = t1.hitNumber + t2.hitNumber;
	t.goBaseNumber = t1.goBaseNumber + t2.goBaseNumber;
	t.runPointNumber = t1.runPointNumber + t2.runPointNumber;
	return t;
}