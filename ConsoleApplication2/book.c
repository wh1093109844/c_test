#include <stdio.h>	
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
