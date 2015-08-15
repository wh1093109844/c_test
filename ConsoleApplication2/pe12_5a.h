#pragma once
int getSize(int size);										//获取数组大小
int getMax(int max);										//获取数据范围
void createRandom(int * const p, int size, int max);		//创建随机数数组
void sort_desc(int * const p, int size);					//降序排序
void getRandomRate(int * const p, int size, int max, time_t speed);