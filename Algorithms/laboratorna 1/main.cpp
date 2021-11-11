#include <iostream>
#include <cstring>

#define SIZE 100 //розм≥р масиву str[]

using namespace std;

void print(char arr[]) {
    int num;                                       //зм≥нна дл€ п≥драхунку к≥лькост≥ входжень
    for(int i = 0; i < arr[i] != '\0'; ++i) {      //цикл в≥дбуваЇтьс€ допоки не буде дос€гнуто к≥нц€ р€дка - '\0'
        num = 1;                                   //кожен символ входить у р€док м≥н≥мум 1 раз
        for(int j = i + 1; j < arr[j] != '\0'; ++j) {
            if(arr[i] == arr[j] && arr[i] != ' ') {//перев≥рка на повторенн€
                ++num;                             //к≥льк≥сть входжень зростаЇ на 1
                arr[j] = '/';                      //≥дентиф≥катор дл€ уникненн€ повторного виведенн€
            }
        }
        if(num > 1 && arr[i] != '/')
            cout << arr[i] << " -> " << num << " times" << endl;
    }
}

int main() {
    char str[SIZE];
    cout << "Enter string\n";

    cin.getline(str, SIZE);
    print(str);

    return 0;
}


























/*#include <iostream>
#include<cstring>

//enum { SIZE 100 };

using namespace std;

int main() {

    char str[] = "ahhhhhh";
    int num;
    for(int i = 0; strlen(str); ++i){
    //for(int i = 0; str[i] != '\0'; ++i){
        num = 1;
        for(int j =  i + 1 ; strlen(str); ++j){
            if(str[i] == str[j]){
                ++num;
                str[j] = '\0';
            }
        }
        if( num  > 1 && str[i] != '\0')
            cout << str[i];// << ' ' << num;
    }


    return 0;
}
*/
