#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
	char *name;
	int value;
	Nameval *next;
};

Nameval *lookup(Nameval *listp, char *name)
{
	for ( ; listp != NULL; listp = listp->next)
		if (strcmp(name, listp->name) == 0)
			return listp;
	return NULL;
}

Nameval *newitem(char *name, int value){
	Nameval *newp;
	newp = (Nameval *)malloc(sizeof(Nameval));
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
	for (p = listp; p->next != NULL; p = p->next);
	p->next = newp;
	return listp;
}


void freeall(Nameval *listp){
	Nameval *next;

	for ( ; listp != NULL; listp = next) {
		next = listp->next;
                                                        /* assumes name is freed elsewhere */
		free(listp);
	}
}

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

void print(const Nameval *listp){
	const Nameval *p;
	for (p = listp; p != NULL; p = p->next) {
		printf("%s: %d   ", p->name, p->value);
	}
}

Nameval *copy(const Nameval *original){
	Nameval *listp, *p, *prev;

	prev = NULL;
	for ( ; original != NULL; original = original->next)
		p = newitem(original->name, original->value);

	return listp;
}

Nameval *merge(Nameval *lista, Nameval *listb){
	Nameval *p;
	if (lista == NULL)
		return listb;

	for(p = lista; p->next != NULL; p = p->next);
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

Nameval *insert_before(Nameval *listp, Nameval *item, Nameval *newp){
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


Nameval *insert_after(Nameval *listp, Nameval *item, Nameval *newp){
	item->next = addfront(item->next, newp);

	return listp;
}


int main(){
    Nameval *listp = NULL, *listp1 = NULL, *merged = NULL;
    Nameval *other;

	listp = addfront(listp, newitem("Andy", 2));
	listp = addfront(listp, newitem("Billy",8));
	listp = addfront(listp, newitem("Alice", 5));
	listp = addfront(listp, newitem("John",  4));
	print(listp); printf("\n\n");
	listp = insert_before(listp, listp, newitem("Nik",3));
	print(listp); printf("\n\n");
    listp = insert_before(listp, lookup(listp, "John"), newitem("Ted", 7));
    print(listp); printf("\n\n");
	insert_after(listp, lookup(listp, "Alice"), newitem("ff", 6));
	print(listp); printf("\n\n");
    listp1 = copy(listp);
    print(listp1); printf("\n\n");
    merged = merge(listp1, listp);
    print(merged); printf("\n\n");
    listp = split(listp, "Alice", &other);
    print(listp); printf("\n\n");

	return 0;
}
















/*
int test_merge(void)
{
	Nameval *lista, *listb, *m;
	int total;
	int success;

	success = 1;
	lista = referencelist();
	listb = referencelist();
	total = count(lista) + count(listb);
	m = merge(copy(lista), copy(listb));
	if (count(m) != total)
		success = 0;
	freeall(lista);
	freeall(listb);
	freeall(m);

	return success;
}

int test_split(void)
{
	Nameval *ref, *listp, *other;
	int success;

	success = 1;
	ref = referencelist();
	listp = split(ref, ref->name, &other);
	if (listp != NULL || other != ref)
		success = 0;
	freeall(listp);
	freeall(other);
	if (!success)
		return 0;

	ref = referencelist();
	listp = split(ref, "Acirc", &other);
	if (listp == NULL || strcmp(listp->name, ref->name) != 0
	    || other == NULL || strcmp(other->name, "Acirc") != 0) {
		success = 0;
	}

	freeall(listp);
	freeall(other);
	if (!success)
		return 0;

	ref = referencelist();
	listp = split(ref, "nonexistent", &other);
	if (listp != ref || other != NULL)
		success = 0;
	freeall(listp);
	freeall(other);
	if (!success)
		return 0;

	return success;
}

*/






/*void print(const Nameval *listp)
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
}*/





