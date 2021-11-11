#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List List;

struct List {
	char *name;
	int value;
	List *next;
};

List *lookup(List *listp, char *name){
	for ( ; listp != NULL; listp = listp->next)
		if (strcmp(name, listp->name) == 0)
			return listp;
	return NULL;
}

List *create_item(char *name, int value){
	List *newp;
	newp = (List *)malloc(sizeof(List));
	newp->name = name;
	newp->value = value;
	newp->next = NULL;
	return newp;
}

List *push_front(List *listp, List *newp){
	newp->next = listp;
	return newp;
}

List *push_end(List *listp, List *newp){
	List *p;

	if (listp == NULL)
		return newp;
	for (p = listp; p->next != NULL; p = p->next);
	p->next = newp;
	return listp;
}


void free_list(List *listp){
	List *next;

	for ( ; listp != NULL; listp = next) {
		next = listp->next;
                                                        /* assumes name is freed elsewhere */
		free(listp);
	}
}

List *del_item(List *listp, char *name){
	List *p, *prev;
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

void print(const List *listp){
	const List *p;
	for (p = listp; p != NULL; p = p->next) {
		printf("%s: %d   ", p->name, p->value);
	}
}

	List *create_item1(char *name, int value) {
		List *newp;
		newp = (List *)malloc(sizeof(List));
		newp->name = name;
		newp->value = value;
	return newp;
}

List *copy(const List *listp) {
	    if(listp == NULL)
    		return 0;
	List *newp = create_item1(listp->name, listp->value);

	newp->next = copy(listp->next);
	return newp;
}

List *merge(List *lista, List *listb){
	List *p;

	if (lista == NULL)
		return listb;

	for (p = lista; p->next != NULL; p = p->next)
	continue;

	p->next = listb;

	return lista;
}

List *split(List *listp, char *name, List **other){
	List *p, *prev;
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

List *insert_before(List *listp, List *item, List *newp){
	List *p, *prev;

	prev = NULL;
	for (p = listp; p != NULL; p = p->next) {
		if (p == item) {
			p = push_front(item, newp);
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

List *insert_after(List *listp, List *item, List *newp){
	item->next = push_front(item->next, newp);

	return listp;
}
int test_copy(List *listp) {
	List *c;
	int equal;
	c = copy(listp);
	equal = lists_equal(listp, c);
	free_list(listp);
	free_list(c);

	return equal;
}

int main(){
    List *listp = NULL, *listp1 = NULL, *merged = NULL;
    List *other;

  printf("original\n");
	listp = push_front(listp, create_item("A", 2));
	listp = push_front(listp, create_item("B",8));
	listp = push_front(listp, create_item("C", 5));
	listp = push_front(listp, create_item("D",  4));
	print(listp);printf("\n\n");

  printf("insert\n");
	listp = insert_before(listp, listp, create_item("E", 3));
    listp = insert_before(listp, lookup(listp, "C"), create_item("G", 7));
	insert_after(listp, lookup(listp, "B"), create_item("F", 6));
	del_item(listp, "B");
	print(listp); printf("\n\n");

	printf("copy\n");
	listp1 = copy(listp);
    print(listp1); printf("\n\n");

	printf("split\n");
	listp = split(listp, "C", &other);
    print(listp); printf("\n\n");

  printf("merge\n");
    merged = merge(listp1, listp);
	print(merged); printf("\n\n");

	return 0;
}






List *create_item(char *name, int value){
	List *newp;
	newp = (List *)malloc(sizeof(List));
	newp->name = name;
	newp->value = value;
	newp->next = NULL;
	return newp;
}

List *push_front(List *listp, List *newp){
	newp->next = listp;
	return newp;
}

List *push_end(List *listp, List *newp){
	List *p;

	if (listp == NULL)
		return newp;
	for (p = listp; p->next != NULL; p = p->next);
	p->next = newp;
	return listp;
}


