#INCLUDE <STDIO.H>
#INCLUDE <STDLIB.H>
#INCLUDE <TIME.H>
#INCLUDE <STRING.H>
#INCLUDE "PE12-2A.H"
#INCLUDE "PE12_5A.H"
#INCLUDE "PE13.H"

#DEFINE SIZE 1024
#DEFINE CNTL_Z '\032'

EXTERN INT RANDOM(VOID);
EXTERN VOID SETNEXT(VOID);
VOID TEST_MALLOC(VOID);
VOID TEST_PE12(VOID);
VOID TEST_PE12_5A(VOID);
VOID TEST_PE12_6A(VOID);
VOID SHOW_ARRAY(INT CONST * CONST P, INT SIZE);
EXTERN VOID REVERSE(VOID);
VOID READLINE(INT ARGV, CHAR * ARGS[]);

INT MAIN(INT ARGV, CHAR * ARGS[]) {
	GETCHARNUM();
	//READLINE(ARGV, ARGS);
	COPYFILE_S();
	RETURN 0;
}

VOID TEST_MALLOC(VOID) {
	DOUBLE * PTD;
	INT MAX;
	INT NUMBER;
	INT I = 0;

	FPUTS("WHAT IS THE MAXIMUM NUMBER OF TYPE DOUBLE ENTRIES?", STDOUT);
	SCANF_S("%D", &MAX);
	PTD = (DOUBLE *)MALLOC(MAX * SIZEOF(DOUBLE));
	IF (PTD == NULL) {
		FPUTS("MEMORY ALLOCATION FAILED. GOODBAY.", STDOUT);
		EXIT(EXIT_FAILURE);
	}
	PUTS("ENTER THE VALUES(Q TO QUIT):");
	WHILE (I < MAX && SCANF_S("%LF", &PTD[I]) == 1) {
		I++;
	}
	PRINTF("HERE ARE YOUR %D ENTRIES:\N", NUMBER = I);
	FOR (I = 0; I < NUMBER; I++) {
		PRINTF("%7.2F ", PTD[I]);
		IF (I % 7 == 6) {
			PUTCHAR('\N');
		}
	}
	IF (I % 7 != 0) {
		PUTCHAR('\N');
	}
	PUTS("DONE.");
	FREE(PTD);
}

VOID TEST_PE12(VOID) {
	INT MODE;
	PRINTF("ENTER 0 FOR METRIC MODE, 1 FOR US MODE: ");
	SCANF_S("%D", &MODE);
	WHILE (MODE >= 0) {
		SET_MODE(MODE);
		GET_INFO();
		SHOW_INFO();
		PRINTF("ENTER 0 FOR METRIC MODE, 1 FOR US MODE");
		PRINTF(" (-1 TO QUIT)�� ");
		SCANF_S("%D", &MODE);
	}
	PRINTF("DONE.\N");
}

VOID TEST_PE12_5A(VOID) {
	INT SIZE = -1;
	WHILE (SIZE = GETSIZE(SIZE), SIZE != -1) {
		INT * P = MALLOC(SIZE * SIZEOF(INT));
		INT MAX = 10;
		MAX = GETMAX(MAX);
		CREATERANDOM(P, SIZE, MAX);
		SORT_DESC(P, SIZE);
		FREE(P);
	}
	PRINTF("DONE.\N");
}

VOID TEST_PE12_6A(VOID) {
	INT SIZE = -1;
	WHILE (SIZE = GETSIZE(SIZE), SIZE != -1) {
		INT MAX = 10;
		MAX = GETMAX(MAX);
		FOR (INT I = 1; I <= MAX; I++) {
			PRINTF("  %3D  ", I);
		}
		PRINTF("\N\N");
		FOR (INT I = 0; I < 10; I++) {
			INT * P = CALLOC(MAX, SIZEOF(INT));
			TIME_T SPEED = TIME(0) + I;
			GETRANDOMRATE(P, SIZE, MAX, SPEED);
			SHOW_ARRAY(P, MAX);
			FREE(P);
		}
	}
	PRINTF("DONE.\N");
}

VOID SHOW_ARRAY(INT CONST * CONST P, INT SIZE) {
	FOR (INT I = 0; I < SIZE; I++) {
		PRINTF("  %3D  ", P[I]);
	}
	PRINTF("\N\N");
}

VOID READLINE(INT ARGV, CHAR * ARGS[]) {
	CHAR FILE[SIZE];
	CHAR CH;
	FILE *FP;
	LONG COUNT, LAST;
	IF (ARGV < 3) {
		FPRINTF(STDERR, "USING:COMMAND STRING FILENAME\N");
		EXIT(2);
	}
	IF (FOPEN_S(&FP, ARGS[2], "R") == NULL) {
		PRINTF("REVERSE CAN'T OPEN %S.\N", ARGS[2]);
		EXIT(1);
	}
	WHILE (FGETS(FILE, SIZE, FP) != NULL) {
		IF (STRSTR(FILE, ARGS[1]) != NULL) {
			FPUTS(FILE, STDOUT);
		}
	}
	PUTCHAR('\N');
	FCLOSE(FP);
}