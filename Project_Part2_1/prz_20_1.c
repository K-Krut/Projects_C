#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum { MULTIPLIER = 31, NHASH = 127 };

typedef struct Nameval Nameval;

struct Nameval {
	char *name;
	int	value;
	Nameval	*next;
};

Nameval *symtab[NHASH];

unsigned int hash_mod(char *str, unsigned int nhash){
	unsigned int h = 0;
	unsigned char *p;

	for (p = (unsigned char *) str; *p != '\0'; ++p)
		h = MULTIPLIER * h + *p;

	return h % nhash;
}

unsigned int hash(char *str){
	return hash_mod(str, NHASH);
}

Nameval *lookup(char *name, int create, int value){

	Nameval *sym;

	int h = hash(name);
	for (sym = symtab[h]; sym != NULL; sym = sym->next)
		if (strcmp(name, sym->name) == 0)
			return sym;
	if (create) {
		sym = (Nameval *) malloc(sizeof(Nameval));
		sym->name = name;
		sym->value = value;
		sym->next = symtab[h];
		symtab[h] = sym;
	}
	return sym;
}

void show(){
		Nameval *sym;
	for(int i = 0; i < NHASH; ++i){
		for (sym = symtab[i]; sym != NULL; sym = sym->next)
		printf("%s %d\n", sym->name, sym->value);

	}
}

static char *random_string(char *s, int len){
	char chr; int i;

	for (i = 0; i < len; ++i) {
		do {
			chr = rand() % 100;
		} while (!isprint(chr));
		s[i] = chr;
	}
	s[i] = '\0';

	return s;
}

void fill_symtab(){
	lookup("smiley", 1, 7);
	lookup("Aacute", 1, 5);
	lookup("AElig", 1, 2);
	lookup("Acirc", 1, 3);
	lookup("zeta", 1, 9);
}

enum { MAX_MULTIPLE = 3, MAX = 7 };

void trivial_collisions(char base) {

	char string[MAX + 1];
	int h = (int) base % NHASH;
	unsigned int  n = 0;
	for(int i = 0; i < MAX; i++) {
		int r = h - n % NHASH;
            if (r < 0)
                r += NHASH;

		string[i] = (char) r;
		string[i + 1] = '\0';
		n += r;
		n *= MULTIPLIER;
		h = hash(string);
		printf("hash(%s) = %u\n", string, h);
	}
	printf("\n\n");
}

void nhash_collisions() {
	char string[MAX + 1];
	for (int m = 1; m < MAX_MULTIPLE; m++) {
		for (int i = 0; i < MAX - 1; i++) {
			random_string(string, i);
			string[i] = 'fg';
			string[i + 1] = '\0';
			printf("hash(%s, %d) = %u\n", string, m, hash_mod(string, m * MULTIPLIER));
		}
		if (m < MAX_MULTIPLE)
			printf("\n");
	}
}

int main(){
	char chr;

	srand(time(NULL));


	nhash_collisions();
	printf("\n");

	for (chr = 'a'; chr <= 'c'; chr++)
		trivial_collisions(chr);

	printf("\n");

	//fill_symtab();

    show();

	return 0;
}
