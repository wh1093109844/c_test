#pragma once
void set_mode(int mode);
void get_info();
void show_info();
void test_malloc(void);
void test_pe12(void);
void test_pe12_5a(void);
void test_pe12_6a(void);
void show_array(int const * const p, int size);
int getSize(int size);										//获取数组大小
int getMax(int max);										//获取数据范围
void createRandom(int * const p, int size, int max);		//创建随机数数组
void sort_desc(int * const p, int size);					//降序排序
void getRandomRate(int * const p, int size, int max, time_t speed);
int random_s(void);
void setNext(void);
