#include <stdbool.h>
#include <string.h>
#include <time.h>

#define SIZE 30011

enum{MULTIPLIER = 31};
typedef struct List List; //for task 1

struct List{
    int data;
    char *string;
    struct List *next;
};

const unsigned char n_begin = 'A';
const unsigned char n_end = 'Z';
const size_t str_len = 3;

int next_element(char *str, size_t strlen) {
	size_t index = strlen - 1;
	int cond = 0;
	while(!cond) {
		cond = 1;
		if(++str[index] > n_end) {
			if (index == 0) {
				return 0;
			}
			str[index--] = n_begin;
			cond = 0;
		}
	}
	return 1;
}
List * lookupHash(char *string, int create, int value){
    List * sym;
    int h = hash(string);
    for(sym = symtab[h]; sym; sym=sym->next)
        if(strcmp(string, sym->string) == 0)
        return sym;
    if(create) {
        sym = (List*)malloc(sizeof(List));
        sym->string = string;
        sym->data = value;
        sym->next = symtab[h];
        symtab[h] = sym;
    }
    return sym;
}

void freeListForTask(List * list){ // for task 11
    List * temp;
    while(list){
        temp = list;
        list = list->next;
        free(temp->string);
        free(temp);
    }
}

int main(){
    List * node;
    char *str = (char*)malloc((str_len+1)*sizeof(char));
	memset(str, n_begin, str_len);
	str[str_len] = 0;
	int count = 0;
	do {
		node = lookupHash(str, 1, count);
		printf(" %d %s ", node->data, node->string);
		count++;
	} while(next_element(str, str_len));
	freeListForTask(node);
    return 0;
}
