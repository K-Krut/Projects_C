#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int value;
} Nameval;

typedef struct {
    Nameval nameval;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} List;

List* create() {
    List *result = malloc(sizeof(List));
    result->head = NULL;
    return result;
}

void pop_front(List *list) {
    if (list == NULL && list->head == NULL) {
        return;
    }
    Node *temp = list->head;
    list->head = list->head->next;
    delete_item(temp);
}

Node *new_item(Nameval nameval){
    Node *newp = malloc(sizeof(Node));
    newp->nameval = nameval;
    newp->next = NULL;
    return newp;
}
void delete_item(Node *item) {
    if (item != NULL) {
        free(item->nameval.name);
    }
    free(item);
}

void push_front(List *list, Nameval nameval){
    if (list == NULL) {
        return;
    }
    Node *temp = new_item(nameval);
    temp->next = list->head;
    list->head = temp;
}

void push_back(List *list, Nameval nameval){
    if (list == NULL) {
        return;
    }
    if (list->head == NULL) {
        push_front(list, nameval);
        return;
    }
    Node *temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_item(nameval);
}

void clear(List *list) {
    for (; list && list->head; pop_front(list));
}

void remove_items_by_name(List *list, const char *name) {
    for (Node **i = &list->head; *i != NULL; i = (*i != NULL ? &(*i)->next : i)) {
        while (*i != NULL && strcmp((*i)->nameval.name, name) == 0) {
            Node *temp = *i;
            *i = (*i)->next;
            delete_item(temp);
        }
    }
}

void print(List *list) {
    for (Node *i = list->head; i != NULL; i = i->next) {
        printf("%s %d\n", i->nameval.name, i->nameval.value);
    }
    putchar('\n');
}

char* make_string(const char *source) {
    return strcpy(malloc(sizeof(char) * (strlen(source) + 1)), source);
}

int main(){

    List *nvlist = create();
    push_front(nvlist, (Nameval){.name=make_string("data1"), .value=10});
    push_back(nvlist, (Nameval){.name=make_string("data1"), .value=45});
    push_back(nvlist, (Nameval){.name=make_string("data2"), .value=123});

    print(nvlist);

    remove_items_by_name(nvlist, "data1");

    print(nvlist);

}

