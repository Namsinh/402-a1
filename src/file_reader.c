#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *find_a(FILE *file) {
	static int found[10];
	int n = 0, c = 0, i = 0;

	while ((c = getc(file)) != EOF) {
		i++;
		putchar(c);
		if (c == 'a') {
			found[n] = i;
			n++;
		}
	}

	return found;
}

int *find_ab(FILE *file) {
	static int found[10];
	int n = 0, c = 0, i = 0;

	while ((c = getc(file)) != EOF) {
		i++;
		putchar(c);
		if (c == 'a') {
			S1: if ((c = getc(file)) == EOF)
				break;
			putchar(c);
			i++;
			if (c == 'b') {
				found[n] = i;
				n++;
			}
			else if (c == 'a') {
				goto S1;
			}
		}
	}

	return found;
}

int *find_aa(FILE *file) {
	static int found[10];
	int n = 0, c = 0, i = 0;

	while ((c = getc(file)) != EOF) {
		i++;
		putchar(c);
		if (c == 'a') {
			S1: if ((c = getc(file)) == EOF)
				break;
			putchar(c);
			i++;
			if (c == 'a') {
				found[n] = i;
				n++;
				goto S1;
			}
		}
	}

	return found;
}

int *find_abc(FILE *file) {
	static int found[10];
	int n = 0, c = 0, i = 0;

	while ((c = getc(file)) != EOF) {
		i++;
		putchar(c);
		if (c == 'a') {
			S1: if ((c = getc(file)) == EOF)
				break;
			putchar(c);
			i++;
			if (c == 'b') {
				if ((c = getc(file)) == EOF)
					break;
				putchar(c);
				i++;
				if (c == 'c') {
					found[n] = i;
					n++;
				}
				else if (c == 'a') {
					goto S1;
				}
			}
			else if (c == 'a') {
				goto S1;
			}
		}
	}

	return found;
}

int *find_aa_aa(FILE *file) {
	static int found[10];
	int n = 0, c = 0, i = 0;

	while ((c = getc(file)) != EOF) {
		i++;
		putchar(c);
		if (c == 'a') {
			if ((c = getc(file)) == EOF)
				break;
			putchar(c);
			i++;
			if (c == 'a') {
				S1: if ((c = getc(file)) == EOF)
					break;
				putchar(c);
				i++;
				if (c != 'a') {
					goto S1;
				}
				else if (c == 'a') {
					if ((c = getc(file)) == EOF)
						break;
					putchar(c);
					i++;
					if (c == 'a') {
						found[n] = i;
						n++;
						goto S1;
					}
					else if (c != 'a') {
						goto S1;
					}
				}
			}
		}
	}

	return found;
}

int *find_aa_aab(FILE *file) {
	static int found[10];
	int n = 0, c = 0, i = 0;

	while ((c = getc(file)) != EOF) {
		i++;
		putchar(c);
		if (c == 'a') {
			if ((c = getc(file)) == EOF)
				break;
			putchar(c);
			i++;
			S1: if (c == 'a') {
				found[n] = i;
				n++;
				if ((c = getc(file)) == EOF)
					break;
				putchar(c);
				i++;
				if (c == 'b') {
					found[n] = i;
					n++;
				}
				else {
					goto S1;
				}
			}
		}
	}

	return found;
}

int main() {
	printf("Enter corresponding letter for the test you would like to run\n");
	printf("(A) a?\n");
	printf("(B) ab?\n");
	printf("(C) aa?\n");
	printf("(D) abc?\n");
	printf("(E) aa*aa?\n");
	printf("(F) aa or aab?\n");

	char answer = getc(stdin);
	char fname[15] = "";
	switch (answer) {
		case 'A':
			strncpy(fname, "../tests/test1", 15);
			break;
		case 'B':
			strncpy(fname, "../tests/test2", 15);
			break;
		case 'C':
			strncpy(fname, "../tests/test3", 15);
			break;
		case 'D':
			strncpy(fname, "../tests/test4", 15);
			break;
		case 'E':
			strncpy(fname, "../tests/test5", 15);
			break;
		case 'F':
			strncpy(fname, "../tests/test6", 15);
			break;
		default :
			printf("Invalid input\n");
			break;
	}

	FILE *file = fopen(fname, "r");
	if (file == NULL) {
		printf("Can't open file :(\n");
		exit(1);
	}
	else {
		printf("File opened\n");
	}

	int *found;
	switch (answer) {
		case 'A':
			found = find_a(file);
			break;
		case 'B':
			found = find_ab(file);
			break;
		case 'C':
			found = find_aa(file);
			break;
		case 'D':
			found = find_abc(file);
			break;
		case 'E':
			found = find_aa_aa(file);
			break;
		case 'F':
			found = find_aa_aab(file);
			break;
		default :
			printf("Invalid input\n");
			break;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d, ", found[i]);
	}
	printf("\n");

	fclose(file);
	exit(1);
}
