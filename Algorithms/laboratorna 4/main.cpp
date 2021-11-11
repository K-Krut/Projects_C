#include <iostream>
#include <cstring>
#include <chrono>

#define SIZE 50
#define SIZE1 100
#define SIZE2 5000
#define SIZE3 110000

using namespace std;
using namespace chrono;

char *swap_recurs(char *arr){//рекурсивна функція для реверсу масиву
    int len = strlen(arr) - 1;//довжина масиву
    char tmp = arr[len]; //допоміжний масив
    if(len + 1 > 1){//перевірка чи довжина не 1
        for(int i = len; i > 0; --i)//цикл в зворотному порядку
            arr[i] = arr[i - 1];//обмін наступного з попереднім
            arr[0] = tmp;//свап першого і останнього
            swap_recurs(arr + 1);//рекурсивний виклик функції swap_recurs
        }
    return arr;//повернення перевернутого масиву
}

void swap_iter(char *str) {//ітераційна функція обміну
    int i = strlen(str) - 1;//позиція останнього елемента
    for (int j = 0; j < i; ++j, --i)
        swap(str[i], str[j]);
}

void rand(char *str, int n) {//функція рандому
    for(int i = 0; i < n - 1; ++i)
        str[i] = char('a' + rand() % ('z' - 'a'));
}

void swap_iter_time(char *arr, int size = SIZE) {//функція для тестування функції ітераційного реверсу
    cout << "\nString after swap_iterative: ";
    auto start1 = steady_clock::now();
    swap_iter(arr);//виклик функції ітераційного реверсу
    auto end1 = steady_clock::now();
    cout << "\nTime: " << chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count() << " ns" << endl;
    if(size == SIZE) cout << arr << endl;
}

void swap_recurs_time(char *arr, int size = SIZE) {//функція для тестування функції рекурсивного реверсу
    cout << "\nString after swap_recursive swap: ";
    auto start1 = steady_clock::now();
    swap_recurs(arr);//виклик функції рекурсивного ревурсу
    auto end1 = steady_clock::now();
    cout << "\nTime: " << chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count() << " ns" << endl;
    if(size == SIZE) cout << arr << endl;
}

char check_vowels(char *arr, char *arr_h, int size = SIZE) {//функція для вибору голосних літер в масиві
    int k = 0;//лічильник
    const char vowels[] = "AEIOUYaeiouy";//масив голосних літер

    for(int i = 0; i <= strlen(arr); ++i){//перевірка на входження голосних літер
        if (strchr(vowels, arr[i]) != NULL){//якщо значення не знайдено, функція повертає 0
            arr_h[k] = arr[i];//запис в допоміжний масив
                k++;//лічильник
        }
    }
    if(size == SIZE) {
        cout << "\nVowels before swaping: ";//вивід масиву голосних літер
        for (int i = 0; i < strlen(arr_h); ++i)
            cout << arr_h[i] << ' ';
    }
return *arr_h;//повернення масиву з голосними літерами
}

int main() {

    srand(time(NULL));

    char str[SIZE], str1[SIZE1], str2[SIZE2], str3[SIZE3];//масиви для запису рандомного тексту
    char str_1[SIZE], str1_1[SIZE1], str2_1[SIZE2], str3_1[SIZE3];//допоміжні масиви, з голосними літерами

    cout << "Enter your string: ";
    cin.getline(str, SIZE);

    rand(str1, SIZE1);//рандом масивів
    rand(str2, SIZE2);
    rand(str3, SIZE3);

    check_vowels(str, str_1);
    swap_iter_time(str_1);
    swap_recurs_time(str_1);

    cout << "\nstr 1" << endl;
    check_vowels(str1, str1_1, SIZE1);
    swap_iter_time(str1_1, SIZE1);
    swap_recurs_time(str1_1, SIZE1);

    cout << "\n\n\nstr 2" << endl;
    check_vowels(str2, str2_1, SIZE2);
    swap_iter_time(str2_1, SIZE2);
    swap_recurs_time(str2_1, SIZE2);

    cout << "\n\n\nstr 3" << endl;
    check_vowels(str3, str3_1, SIZE3);
    swap_iter_time(str3_1, SIZE3);
    swap_recurs_time(str3_1, SIZE3);

return 0;
}













//int main() {
//
//    srand(time(NULL));
//    char str1[SIZE1], str2[SIZE2], str3[SIZE3];//масиви для запису рандомного тексту
//    char str1_1[SIZE1], str2_1[SIZE2], str3_1[SIZE3];//допоміжні масиви, з голосними літерами
//
//    rand(str1, SIZE1);//рандом масивів
//    rand(str2, SIZE2);
//    rand(str3, SIZE3);
//
//    cout << "\nstr 1" << endl;
//    check_vowels(str1, str1_1);
//    swap_iter_time(str1_1);
//    swap_recurs_time(str1_1);
//
//    cout << "\n\n\nstr 2" << endl;
//    check_vowels(str2, str2_1);
//    swap_iter_time(str2_1);
//    swap_recurs_time(str2_1);
//
//    cout << "\n\n\nstr 3" << endl;
//    check_vowels(str3, str3_1);
//    swap_iter_time(str3_1);
//    swap_recurs_time(str3_1);
//
//return 0;
//}












//
//
//    if(strlen(arr) < 51 ){
//    cout << "\nVowels before swaping: ";//вивід масиву голосних літер
//    for (int i = 0; i < strlen(arr_h); ++i)
//        cout << arr_h[i] << ' ';
//    }
//return *arr_h;//повернення масиву з голосними літерами
//}
//
//
//
//int main() {
//
//    srand(time(NULL));
//    char str[50], str1[SIZE1], str2[SIZE2], str3[SIZE3];//масиви для запису рандомного тексту
//    char str_1[50], str1_1[SIZE1], str2_1[SIZE2], str3_1[SIZE3];//допоміжні масиви, з голосними літерами
//    cout << "Enter your string: ";
//    cin.getline(str, 50);
//
//    rand(str1, SIZE1);//рандом масивів
//    rand(str2, SIZE2);
//    rand(str3, SIZE3);
//
//    check_vowels(str, str_1);
//    swap_iter_time(str_1);
//    swap_recurs_time(str_1);
//
//    cout << "\nstr 1" << endl;
//    check_vowels(str1, str1_1);
//    swap_iter_time(str1_1);
//    swap_recurs_time(str1_1);
//
//    cout << "\n\n\nstr 2" << endl;
//    check_vowels(str2, str2_1);
//    swap_iter_time(str2_1);
//    swap_recurs_time(str2_1);
//
//    cout << "\n\n\nstr 3" << endl;
//    check_vowels(str3, str3_1);
//    swap_iter_time(str3_1);
//    swap_recurs_time(str3_1);
//
//return 0;
//}
//


//void swap_recurs_time(char *arr){
//    cout << "\nString after swap_recursive swap: ";
//    auto start1 = steady_clock::now();
//    swap(arr);
//    auto end1 = steady_clock::now();
//    cout << "\nTime: " << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << " ms" << endl;
//    cout << arr << endl;
//}

//void swap(char *p){//рекурсивна функція обмі?ну
//
//    if (*p)
//        swap(p + 1);//прохід всіх елементів масиву
//   // cout << *p;//вивід останнього елемента в масиві
//
//}
//char swap_recurs(char *arr, int start, int end) {
//    if(*arr < 0 || arr == end)
//        return 0;
//    return (*arr) +swap_recurs(arr + 1, end);
////}
//void swap_recurs(char *arr, int start, int end)
//{
//    while (start < end)
//    {
//        int temp = arr[start];
//        arr[start] = arr[end];
//        arr[end] = temp;
//        start++;
//        end--;
//    }
//}
















//#include <iostream>
//#include <chrono>
//
//#define SIZE 20
//#define SIZE2 5000
//#define SIZE3 50000
//
//using namespace std;
//using namespace chrono;
//
//void create_increase(int arr[], int n){
//    for (int i = 0; i < n; ++i)
//        arr[i] = i + 1;
//}
//
//void create_decrease(int arr[], int n){
//    int j = 0;
//    for (int i = n; i > 0; --i) {
//            arr[j] = i;
//            ++j;
//    }
//}
//
//void random_data(int arr[], int n) {//функція для створення рандомного масиву
//    for (int i = 0; i < n - 1; ++i)
//        arr[i] = rand() / (RAND_MAX / (n - i) + 1);
////        arr[i] = rand() % 10000;
//}
//
//void count_sort(int array[], int n) {
//
//    int output[SIZE3];//массив для збереження відсортованого смасиву
//    int count[SIZE3];//масив для підрухунку кількості однакових елементів
//    int max_el = array[0];//максимальний елемент - перщий елемент
//
//    for (int i = 1; i < n; ++i) {//пошук найбільшого елемента в масиві
//        if (array[i] > max_el)
//            max_el = array[i];
//    }
//
//    for (int i = 0; i <= max_el; ++i)//обнулення масиву count[]
//        count[i] = 0;
//
//    for (int i = 0; i < n; ++i)//запис кількості повторень кожного елемента
//        count[array[i]]++;
//
//    for (int i = 1; i <= max_el; ++i)
//        count[i] += count[i - 1];
//
//    for (int i = n - 1; i >= 0; --i) {//пошук індексу кожного елемента в оригінальному масиві
//        output[count[array[i]] - 1] = array[i];//та розміщення елементів в output[]
//        --count[array[i]];
//    }
//
//    for (int i = 0; i < n; ++i)
//        array[i] = output[i];//копіювання елементів відсортованих в оригінальний масив
//}
//
//void select_sort(int arr[], int n) {
//    for(int i = 0; i < n - 1; ++i) {//прохід по всіх елементах масиву
//        int index = i; //індекс мінімального елемента
//        for(int j = i + 1; j < n; ++j)//пошук мінімального елемента в масиві
//            if (arr[j] < arr[index])
//                index = j;
//
//        swap(arr[index], arr[i]);//мінімальний елемент міняється місцями з першим
//    }
//}
//
//void print_data(int array[], int n) {//функція друку масиву
//    for (int i = 0; i < n; ++i)
//        cout << array[i] << ' ';
//    cout << "\n";
//}
//
//auto test_count(int arr[], int n){//функція для тестування тривалості сортування підрахуноком
//    auto begin = steady_clock::now();//
//    count_sort(arr, n);
//    auto elapsed_ms = duration_cast < milliseconds > (steady_clock::now() - begin);
//    //if (n == SIZE) print_data(arr , n);
//    return elapsed_ms.count();
//}
//
//auto test_select(int arr[], int n){//функція для тестування тривалості сортування вибіркою
//    auto begin = steady_clock::now();
//    select_sort(arr, n);
//    auto elapsed_ms = duration_cast < milliseconds > (steady_clock::now() - begin);
//    //if (n == SIZE) print_data(arr , n);
//    return elapsed_ms.count();
//}
//
//void show(int a[], int b[], int n){// функція для виведення результату тестування функцій сортування
//    cout << "count sort\n";
//    create_increase(a, n); //if (n == 20) print_data(a , n);
//    cout << "increase   \n" << test_count(a, n)  << " ms" << endl;
//    random_data(a, n); //if (n == 20) print_data(a , n);
//    cout << "random   \n" << test_count(a, n)  <<" ms" <<  endl;
//    create_decrease(a, n); //if (n == 20) print_data(a , n);
//    cout << "decrease  \n" << test_count(a, n)  << " ms" << endl;
//
//    cout << "\nselect sort\n";
//    create_increase(b, n); //if (n == 20) print_data(b , n);
//    cout << "increase   \n" << test_select(b, n)  << " ms" <<  endl;
//    random_data(b, n); //if (n == 20)print_data(b , n);
//    cout << "random   \n" << test_select(b, n)  << " ms" << endl;
//    create_decrease(b, n); //if (n == 20) print_data(b , n);
//    cout << "decrease   \n" << test_select(b, n)  << " ms" << endl;
//}
//
//
//int main() {
//
//    srand(time(NULL));
//
//    int data[SIZE], data2[SIZE2], data3[SIZE3];
//    int data_1[SIZE], data2_1[SIZE2], data3_1[SIZE3];
//
//    cout << "test data " << endl;
//    show(data, data_1, SIZE);
//
//    cout << "\n\ntest data2 " << endl;
//    show(data2, data2_1, SIZE2);
//
//    cout << "\n\ntest data3 " << endl;
//    show(data3, data3_1, SIZE3);
//
//    return 0;
//}
