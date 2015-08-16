#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pe13.h"
#define BUFFER_SIZE 1024

void appendFile(int argv, char *args[]) {
	int i = 1;
	FILE *source, *targer;
	char temp[BUFFER_SIZE], read_buffer[BUFFER_SIZE], write_buffer[BUFFER_SIZE];
	size_t bytes;

	if (argv == 3) {
		fprintf(stderr, "using:command targer source1 source2...\n");
		exit(1);
	}
	printf("================ open targer file %s =================\n", args[1]);
	fopen_s(&targer, args[1], "ab");
	if (targer == NULL) {
		fprintf(stderr, "could not open targer file %s\n", args[1]);
	}
	if (setvbuf(targer, write_buffer, _IOFBF, BUFFER_SIZE) == 0) {
		fprintf(stderr, "could not create write buffer\n");
	}
	while (++i < argv) {
		printf("+++++++++++++++++++++ open source file %s ++++++++++++++++++++++++\n", args[i]);
		if (strcmp(args[1], args[i]) == 0) {
			fprintf(stderr, "could not append to itself\n");
			continue;
		}
		fopen_s(&source, args[i], "rb");
		if (source == NULL) {
			fprintf(stderr, "could not open source file %s\n", args[i]);
			continue;
		}
		if (setvbuf(source, read_buffer, _IOFBF, BUFFER_SIZE) == 0) {
			fprintf(stderr, "could not create read buffer\n");
		}
		while ((bytes = fread(temp, sizeof(char), BUFFER_SIZE, source)) > 0) {
			fwrite(temp, sizeof(char), bytes, targer);
		}
		fclose(source);
	}
	printf("append done.\n");
	fclose(targer);
}