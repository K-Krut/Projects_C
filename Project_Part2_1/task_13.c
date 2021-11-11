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



Nameval *addfront(Nameval *listp, Nameval *newp){
	newp->next = listp;
	return newp;
}

Nameval *addend(Nameval *listp, Nameval *newp){
	Nameval *p;

	if (listp == NULL)
		return newp;
	for (p = listp; p->next != NULL; p = p->next)
		;
	p->next = newp;
	return listp;
}

Nameval *lookup(Nameval *listp, char *name){
	for ( ; listp != NULL; listp = listp->next)
		if (strcmp(name, listp->name) == 0)
			return listp;
	return NULL;	/* no match */
}

void freeall(Nameval *listp){
	Nameval *next;

	for ( ; listp != NULL; listp = next) {
		next = listp->next;
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
	for (p = listp; p != NULL; p = p->next)
		printf("%s: %d   ", p->name, p->value);
}

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


Nameval *split(Nameval *listp, char *name, Nameval **other){
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
  //  printf("test_insert_before\n");
    list = insert_before(list, item1, newitem("Nik",3));
    list = insert_before(list, item2, newitem("Ann",1));
	print(list); printf("\n\n");
}

void test_insert_after(Nameval *list, Nameval *item1, Nameval *newitem1) {
 //   printf("test_insert_after\n");
    list = insert_after(list, item1, newitem1);
    print(list); printf("\n\n");
}

Nameval test_copy(Nameval *listp, Nameval *listp2){
  //  printf("test_copy\n");
    listp2 = copy(listp);
    print(listp2); printf("\n\n");
}

Nameval *generate(){
	Nameval *listp = NULL;
	listp = addfront(listp, newitem("Rosie", 2));
	listp = addfront(listp, newitem("Wall",8));
	listp = addfront(listp, newitem("Din", 5));
	listp = addfront(listp, newitem("Tom",  4));
	return listp;
}

void reverse(struct Nameval **listp) {
	struct Nameval* prev = NULL;
	struct Nameval* current = *listp;
	struct Nameval* next;
	while (current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*listp = prev;
}

void recursive_reverse(struct Nameval **listp){
    struct Nameval *first, *oters;

    if (*listp == NULL)
       return;

    first = *listp;
    oters  = first->next;

    if (oters == NULL)
       return;

    recursive_reverse(&oters);
    first->next->next  = first;
    first->next  = NULL;
    *listp = oters;
}

void test_merge(Nameval *lista){
  //  printf("test_merge\n");
    Nameval *listb, *merged;
    listb = generate();
    merged = merge(lista, listb);
    print(merged); printf("\n\n");
}

void test_split(Nameval *listp) {
    Nameval *other;
    listp = split(listp, "Alice", &other);
    print(listp); printf("\n\n");
}

void test_reverse(Nameval *listp){
        reverse(&listp);
        print(listp); printf("\n\n");
}

void test_reverse_recursive(Nameval *listp){
        recursive_reverse(&listp);
        print(listp); printf("\n\n");
}

int main() {

    Nameval *listp = NULL, *listp1 = NULL, *merged = NULL, *other;

    listp = addfront(listp, newitem("Andy", 2));
	listp = addfront(listp, newitem("Billy", 8));
	listp = addfront(listp, newitem("Alice", 5));
	listp = addfront(listp, newitem("John", 4));
    listp = addfront(listp, newitem("Mike", 4));
    listp = addfront(listp, newitem("Ostin", 4));

	print(listp); printf("\n\n");

    test_insert_before(listp, listp,lookup(listp, "John"));
    test_copy(listp, listp1);
    test_merge(listp);
    test_split(listp);
    test_reverse_recursive(listp);
    test_reverse(listp);

    return 0;
}
