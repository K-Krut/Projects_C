#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
    char *name;
    int value;
};

struct Nvtab {
    int nval;
    int max;
    Nameval *nameval;
} nvtab;

enum { NVINIT = 1, NVGROW = 2 };

int addname(Nameval newname) {
    Nameval *nvp;
    if(nvtab.nameval == NULL){
        nvtab.nameval = (Nameval *)malloc(NVINIT *sizeof(Nameval));
        if(nvtab.nameval == NULL)
            return -1;
        nvtab.max = NVINIT;
        nvtab.nval = 0;
    } else if (nvtab.nval >= nvtab.max){
        nvp = (Nameval *}realloc(nvtab.nameval, (NVGROW* nvtab.max)*sizeof(Nameval));
        if (nvp == NULL)
            return -1;
        nvtab.max *= NVGROW;
        nvtab.nameval = nvp;
    }
    for(int i = 0; i < nvtab.nval; ++i){
        if(nvtab.nameval[i].name == NULL){
           // nvtab.nameval = (Nameval *)malloc(NVINIT *sizeof(Nameval));
           nvtab.nameval[i].name = newname;
           //return
        }
    }
    nvtab.nameval[nvtab.nval] = newname;
    return nvtab.nval++;
}

int delname(char *name){
    for(int i = 0; i<nvtab.nval; ++i){
        if(strcmp(nvtab.nameval[i].name, name) == 0)
            nvtab.nameval[i].name == NULL;
            --nvtab.nval;
            return 1;
    }
    return 0;
}


int main (){
    int curname = addname((struct Nameval) {.name = "Andy", .value = 23});
    printf("%d\n", curname);
    for(int i = 0; i < nvtab.nval; ++i)
        printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);

return 0;
}
