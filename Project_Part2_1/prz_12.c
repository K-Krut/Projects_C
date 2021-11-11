#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
    char *name;
    int value;
    Nameval *next;
};

Nameval *newitem(char *name, int value) {
    Nameval *newp;
    newp = (Nameval *)malloc(sizeof(Nameval));
    newp->name = name;
    newp->value = value;
    newp->next = NULL;
    return newp;
}

Nameval *addfront(Nameval *listp, Nameval *newp) {
    newp->next = listp;
    return newp;
}

Nameval *addend(Nameval *listp, Nameval *newp) {
    if(listp == NULL)
        return newp;
    Nameval *p;
    for(p = listp; p->next != NULL; p = p-> next);
        p->next = newp;
        return listp;
}

Nameval *lookup(Nameval *listp, char *name){
    for( ; listp != NULL; listp = listp-> next)
        if(strcmp(name, listp->name) == 0)
        return listp;
    return NULL;
}

void freeall(Nameval *listp) {
    Nameval *next;
    for( ; listp != NULL; listp = next){
        next = listp->next;
        free(listp);
    }
}

Nameval *delitem(Nameval *listp, char *name){
        Nameval *p, *prev;
        prev = NULL;
        for(p = listp; p != NULL; p = p->next){
            if(strcmp(name, p->name) == 0) {
                if(prev == NULL)
                    listp = p->next;
                else
                    prev->next = p->next;
                free(p);
                return listp;
            }
            prev = p;
        }
        printf("delitem: %s not in list", name);
        return NULL;
}

int main(){
    Nameval *nvlist = NULL;
    nvlist = addfront(nvlist, newitem("data1", 10));
    printf("%s %d\n", nvlist->name, nvlist->value);

    Nameval *item = newitem("data2", 45);
    nvlist = addend(nvlist, item);
    printf("%s %d\n", item->name, item->value);

    return 0;
}
