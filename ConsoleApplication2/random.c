#include <stdio.h>
#include <time.h>
#include "pe12.h"
static unsigned long int next = 1;

int random_s(void) {
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}

void setNext(void) {
	next = time(0);
}