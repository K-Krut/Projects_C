#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NHASH 127

typedef struct Nameval Nameval;
typedef unsigned int ui;
typedef unsigned char uch;

struct Nameval {
	char *name;
	int value;
	Nameval *next;
};

Nameval *symtab[NHASH];

enum { MULTIPLIER = 31 };

ui hash(char *str){
	ui h = 0;
	for(uch *p = (uch *)str; *p != '\0'; ++p)
		h = MULTIPLIER*h + *p;
	return h % NHASH;
}

Nameval *lookup(char *name, int create, int value){
		Nameval *sym;
	int h = hash(name);
	for(sym = symtab[h]; sym != NULL; sym = sym->next)
		if(strcmp(name, sym->name) == 0)
			return sym;
	if(create){
		sym = (Nameval *)malloc(sizeof(Nameval));
		sym->name = name;
		sym->value = value;
		sym->next = symtab[h];
		symtab[h] = sym;
	}
	return sym;
}

void generate() {
	lookup("Billy", 1, 8);
	lookup("Alise", 1, 9);
	lookup("John", 1, 10);
	lookup("Endy", 1, 11);
	//lookup("Rozie", 1, 12);
	//lookup("Julia", 1, 13);
	//lookup("Martin", 1, 14);
}

void generate1(){
	lookup("a", 1, 1);
	lookup("a0", 1, 2);
	lookup("a000", 1, 3);
	lookup("a0000", 1, 4);
	//lookup("a00000", 1, 5);
	//lookup("a000000", 1, 6);
	//lookup("a0000000r", 1, 7);
}

void show(){
    Nameval *sym;
    for(int i = 0; i < NHASH; ++i){
        for (sym = symtab[i]; sym != NULL; sym = sym->next)
            printf("%s %d\n", sym->name, sym->value);
	}
}
/*
void hash_value(){
    return
}
*/
int main(){

	generate();
	show();

    generate1();
	show();
	return 0;
}











/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NHASH 127

typedef struct Nameval Nameval;
typedef unsigned int ui;
typedef unsigned char uch;

struct Nameval {
	char *name;
	int value;
	Nameval *next;
};

Nameval *symtab[NHASH];

enum { MULTIPLIER = 31 };

ui hash(char *str){
	ui h = 0;
	for(uch *p = (uch *)str; *p != '\0'; ++p)
		h = MULTIPLIER*h + *p;
	return h % NHASH;
}

Nameval *lookup(char *name, int create, int value){
		Nameval *sym;
	int h = hash(name);
	for(sym = symtab[h]; sym != NULL; sym = sym->next)
		if(strcmp(name, sym->name) == 0)
			return sym;
	if(create){
		sym = (Nameval *)malloc(sizeof(Nameval));
		sym->name = name;
		sym->value = value;
		sym->next = symtab[h];
		symtab[h] = sym;
	}
	return sym;
}


void generate(){
	lookup("Billy", 1, 1);
	lookup("Alise", 1, 2);
	lookup("John", 1, 3);
	lookup("Endy", 1, 4);
	lookup("Rozie", 1, 5);
	lookup("Julia", 1, 6);
	lookup("Martin", 1, 7);
	lookup("Nick", 1, 8);
}

void generate1(){
	lookup("a", 1, 9);
	lookup("a0", 1, 10);
	lookup("a000", 1, 11);
	lookup("a0000", 1, 12);
	lookup("a0000", 1,13);
	lookup("a0000", 1,14);
	lookup("a00000r", 1,15);
}


void show(){
    Nameval *sym;
    for(int i = 0; i < NHASH; ++i){
        for (sym = symtab[i]; sym != NULL; sym = sym->next)
            printf("%s %d\n", sym->name, sym->value);
	}
}

int main(){

	generate();
	show();

    generate1();
	show();

	return 0;
}



*/










/*
Exercise 2-14
For NHASH = 127, all these strings hash to 100:
"d", "d0", "d00", "d000", "d0000", "d00000", "d00000r"
and all these hash to 103:
"g", "gU", "gUU", "gUUU", "gUUUU", "gUUUUU", "gUUUUU(", "gUUUUU(x", "gUUUUU(x)"
These strings are built up incrementally, at each step figuring what the
next character must be to keep the hash value the same. The sudden
change from the repeated characters is what happens when the hash
counter overflows an unsigned int. See trivial_collisions in hash.c.

If NHASH is 31, the hash function degenerates into the hash of the final
character: hash("a") = hash("cba") = hash("hasha"); at least until the
hash counter overflows an unsigned int. Similarly, if NHASH is 62,
strings with the same final character will fall into one of only two
buckets, and so on with integer multiples of MULTIPLIER. This means
short strings with the same final character are likely to collide. See
nhash_collisions in hash.c.
*/
