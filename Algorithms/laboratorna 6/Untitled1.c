#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef unsigned int ui;
static const char alphanum[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const char vowels[] = "AEYUIOaeyiou";
const char consonants[] = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";

int stringLength = sizeof(alphanum) - 1;

char genRandom() {
    //return alphanum[rand() % stringLength + 'a'  - 'z'];
    return alphanum[rand() % stringLength + rand()%32 + 1];
}

int main() {
    srand(time(0));
    string Str;
int k = 0;
    for(ui i = 0; i < 20; ++i) {
            //cout << ' ';
        for(ui j = 0; j < 10; ++j) {
            Str += genRandom();
        }
       // cout << ' ';
    }
    cout << Str << endl;


    return 0;
}
