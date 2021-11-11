#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
	char *name;
	int value;
	Nameval *next;
};

Nameval *newitem(char *name, int value){
	Nameval *newp;
	newp = (Nameval *) malloc(sizeof(Nameval));
	newp->name = name;
	newp->value = value;
	newp->next = NULL;
	return newp;
}

Nameval *addfront(Nameval *listp, Nameval *newp)
{
	newp->next = listp;
	return newp;
}

Nameval *addend(Nameval *listp, Nameval *newp)
{
	Nameval *p;

	if (listp == NULL)
		return newp;
	for (p = listp; p->next != NULL; p = p->next)
		;
	p->next = newp;
	return listp;
}

/* lookup: sequential search for name in listp */
Nameval *lookup(Nameval *listp, char *name)
{
	for ( ; listp != NULL; listp = listp->next)
		if (strcmp(name, listp->name) == 0)
			return listp;
	return NULL;	/* no match */
}

/* apply: execute fn for each element of listp */
void apply(Nameval *listp,
	void (*fn)(Nameval*, void*), void *arg)
{
	for ( ; listp != NULL; listp = listp->next)
		(*fn)(listp, arg);	/* call the function */
}

/* printnv: print name and value using format in arg */
void printnv(Nameval *p, void *arg)
{
	char *fmt;

	fmt = (char *) arg;
	printf(fmt, p->name, p->value);
}

/* inccounter: increment counter *arg */
void inccounter(Nameval *p, void *arg)
{
	int *ip;

	/* p is unused */
	ip = (int *) arg;
	(*ip)++;
}

/* freeall: free all elements of listp */
void freeall(Nameval *listp)
{
	Nameval *next;

	for ( ; listp != NULL; listp = next) {
		next = listp->next;
		/* assumes name is freed elsewhere */
		free(listp);
	}
}

/* delitem: delete first "name" from listp */
Nameval *delitem(Nameval *listp, char *name){
	Nameval *p, *prev;

	prev = NULL;
	for (p = listp; p != NULL; p = p->next) {
		if (strcmp(name, p->name) == 0) {
			if (prev == NULL)
				listp = p->next;
			else
				prev->next = p->next;
			free(p);
			return listp;
		}
		prev = p;
	}

	return NULL;
}

void print(const Nameval *listp)
{
	const Nameval *p;

	printf("{");
	for (p = listp; p != NULL; p = p->next) {
		if (p == listp)
			printf(" ");
		else
			printf(", ");
		printf("%s:%d", p->name, p->value);
	}
	printf(" }\n");
}

int count(const Nameval *listp){
	int n = 0;
	apply((Nameval *) listp, inccounter, &n);
	return n;
}
/*
Nameval *generate(){
	Nameval *listp1 = NULL;
	listp1 = addfront(listp1, newitem("A",  0x00c6));
	listp1 = addfront(listp1, newitem("B", 0x00c1));
	listp1 = addfront(listp1, newitem("C",  0x00c2));
	listp1 = addfront(listp1, newitem("D",   0x03b6));
    return listp1;
}

Nameval *generate1(){
	listp1 = addfront(listp, newitem("Andy", 2));
	listp1 = addfront(listp, newitem("Billy",8));
	listp1 = addfront(listp, newitem("Alice", 5));
	listp1 = addfront(listp, newitem("John",  4));
	return listp1;
}
*/

Nameval *copy(const Nameval *original){
	Nameval *listp, *p, *prev;

	prev = NULL;
	for ( ; original != NULL; original = original->next) {
		p = newitem(original->name, original->value);
		if (prev == NULL)
			listp = p;
		else
			prev->next = p;
		prev = p;
	}

	return listp;
}

Nameval *merge(Nameval *lista, Nameval *listb){
	Nameval *p;

	if (lista == NULL)
		return listb;
    else
        return lista;
	for (p = lista; p->next != NULL; p = p->next);
	p->next = listb;

	return lista;
}

Nameval *split(Nameval *listp, const char *name, Nameval **other){
	Nameval *p, *prev;

	prev = NULL;
	for (p = listp; p != NULL; p = p->next) {
		if (strcmp(p->name, name) == 0) {
			*other = p;
			if (prev == NULL)
				listp = NULL;
			else
				prev->next = NULL;
			return listp;
		}
		prev = p;
	}
	*other = NULL;
	return listp;
}

Nameval *insert_before(Nameval *listp, Nameval *item, Nameval *newp) {

	Nameval *p, *prev;
	prev = NULL;
	for (p = listp; p != NULL; p = p->next) {
		if (p == item) {
			p = addfront(item, newp);
			if (prev == NULL)
				listp = p;
			else
				prev->next = p;
			return listp;
		}
		prev = p;
	}
	return NULL;
}

Nameval *insert_after(Nameval *listp, Nameval *item, Nameval *newp) {
	item->next = addfront(item->next, newp);

	return listp;
}

void test_insert_before(Nameval *list, Nameval *item1, Nameval *item2) {
    list = insert_before(list, item1, newitem("Nik",3));
    list = insert_before(list, item2, newitem("Ann",1));
	print(list); printf("\n\n");
}

void test_insert_after(Nameval *list, Nameval *item1, Nameval *newitem1) {
    list = insert_after(list, item1, newitem1);
    print(list); printf("\n\n");
}

Nameval test_copy(Nameval *listp, Nameval *litsp2){
    listp2 = copy(listp);
    print(listp2); printf("\n\n");
}

int main() {

    Nameval *listp = NULL, *listp1 = NULL, *merged = NULL, *other;

    listp = addfront(listp, newitem("Andy", 2));
	listp = addfront(listp, newitem("Billy", 8));
	listp = addfront(listp, newitem("Alice", 5));
	listp = addfront(listp, newitem("John", 4));

	print(listp); printf("\n\n");

    test_insert_before(listp, listp,lookup(listp, "John"));
    test_insert_before(listp, listp,lookup(listp, "John"));
  //  test_insert_after(listp, lookup(listp1, "Billy"), newitem("Mike", 6));

  //  listp = insert_after(listp, lookup(listp1, "Billy"), newitem("Mike", 6));
  //  print(listp); printf("\n\n");

    test_copy(listp, listp1);

    return 0;
}