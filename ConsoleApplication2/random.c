#include<stdio.h>
#include<time.h>
static unsigned long int next = 1;
int random();
void setNext();

int random() {
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}

void setNext() {
	next = time(0);
}