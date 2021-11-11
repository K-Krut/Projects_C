
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NHASH 384

typedef struct Nameval Nameval;
typedef unsigned int ui;
typedef unsigned char uch;

struct Nameval {
	char *name;
	int value;
	Nameval *next;
};

Nameval *symtab[NHASH];

enum { MULTIPLIER = 32 };

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
	lookup("Billy", 1, 12);
	lookup("Alise", 1, 65);
	lookup("John", 1, 6);
	lookup("Endy", 1, 7);
	lookup("Rozie", 1, 2);
	lookup("Julia", 1, 3);
	lookup("Martin", 1, 74);
	lookup("Nick", 1, 0);
}
void generate1(){
    lookup("https://developer.mozilla.org/ru/docs/Learn/", 1, 12);
	lookup("developer.mozilla.org/ru/docs/Learn",1, 65);
	lookup("http://support.google.com/google-ads", 1, 6);
	lookup("http://www.google.com/intl/uk/privacy", 1, 7);
	lookup("https://www.instagram.com/septembrenell/", 1, 2);
	lookup("https://www.instagram.com/p/CJQhLxRrUMy/", 1, 3);
	lookup("https://www.instagram.com/p/CJTpou8r4Np/", 1, 74);
	lookup("https://www.instagram.com/p/CJD-OVALuCE/", 1, 0);
}

void generate2(){
    lookup("The most difficult part of writing this book was deciding", 1, 12);
	lookup("Chapter 1 provides a review of the C++ features that are used", 1, 65);
	lookup("Chapter 6 is mostly unchanged; however", 1, 6);
	lookup("Chapter 2 deals with algorithm analysis. This chapter explains", 1, 7);
	lookup("We can use this same technique to compute, a sum that occur", 1, 2);
	lookup("Lines 3 and 4 handle what is known as the base case", 1, 3);
	lookup("It turns out that recursive calls are handled no differently", 1, 74);
	lookup("Our recursive strategy to understand words is as follows", 1, 0);
}

void generate3(){

    lookup("AAAAAAA1", 1, 12);
	lookup("AAAAAAA;", 1, 65);
	lookup("AaAAa_A1", 1, 6);
	lookup("AA_AA_A1", 1, 7);
	lookup("AAytAAA1", 1, 2);
	lookup("BAAuA*AA", 1, 3);
	lookup("BBbAAtA1", 1, 74);
	lookup("AAÀAuye*", 1, 0);
}


void show(){
		Nameval *sym;
	for(int i = 0; i < NHASH; ++i){
		for (sym = symtab[i]; sym != NULL; sym = sym->next)
		printf("%s %d\n", sym->name, sym->value);

	}
}
void show_(){
		Nameval *sym;
	for(int i = 0; i < NHASH; ++i){
		for (sym = symtab[i]; sym != NULL; sym = sym->next)
		printf("%s %d\n", sym->name, sym->value);
	}
}


int main(){
	//generate();
	//show();
    //generate1();
    //show();
    //generate2();
    //show();
    generate3();
    show();
   //printf("%d\n", hash(char *str));

   //Nameval *node = lookup("Billy", 1, 12);
   //printf("\n\n%s %d\n", node->name, node->value);
	return 0;
}


















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
nhash_collisions in hash.c.*/
