#include <iostream>
#include <chrono>

#define SIZE 20
#define SIZE2 5000
#define SIZE3 50000

using namespace std;
using namespace chrono;

void create_increase(int arr[], int n){
    for (int i = 0; i < n; ++i)
        arr[i] = i + 1;
}

void create_decrease(int arr[], int n){
    int j = 0;
    for (int i = n; i > 0; --i) {
            arr[j] = i;
            ++j;
    }
}

void random_data(int arr[], int n) {//функція для створення рандомного масиву
    for (int i = 0; i < n - 1; ++i)
        arr[i] = rand() / (RAND_MAX / (n - i) + 1);
         //arr[i] = rand() % 10000;
}

void count_sort(int array[], int n) {

    int output[SIZE3];//массив для збереження відсортованого смасиву
    int count[SIZE3];//масив для підрухунку кількості однакових елементів
    int max_el = array[0];//максимальний елемент - перщий елемент

    for (int i = 1; i < n; ++i) {//пошук найбільшого елемента в масиві
        if (array[i] > max_el)
            max_el = array[i];
    }

    for (int i = 0; i <= max_el; ++i)//обнулення масиву count[]
        count[i] = 0;

    for (int i = 0; i < n; ++i)//запис кількості повторень кожного елемента
        count[array[i]]++;

    for (int i = 1; i <= max_el; ++i)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; --i) {//пошук індексу кожного елемента в оригінальному масиві
        output[count[array[i]] - 1] = array[i];//та розміщення елементів в output[]
        --count[array[i]];
    }

    for (int i = 0; i < n; ++i)
        array[i] = output[i];//копіювання елементів відсортованих в оригінальний масив
}

void select_sort(int arr[], int n) {
    for(int i = 0; i < n - 1; ++i) {//прохід по всіх елементах масиву
        int index = i; //index of min el

        for(int j = i + 1; j < n; ++j){//пошук мінімального елемента в масиві
            if (arr[j] < arr[index])
                index = j;
        }
        swap(arr[index], arr[i]);//мінімальний елемент міняється місцями з першим
    }
}

void print_data(int array[], int n) {//функція друку масиву
    for (int i = 0; i < n; ++i)
        cout << array[i] << ' ';
    cout << "\n";
}

auto test_count(int arr[], int n){//функція для тестування тривалості сортування підрахуноком
    auto begin = steady_clock::now();//
    count_sort(arr, n);
    auto elapsed_ms = duration_cast < milliseconds > (steady_clock::now() - begin);
        //if (n == SIZE) print_data(arr , n);
    return elapsed_ms.count();
}

auto test_select(int arr[], int n) {//функція для тестування тривалості сортування вибіркою
    auto begin = steady_clock::now();
    select_sort(arr, n);
    auto elapsed_ms = duration_cast < nanoseconds > (steady_clock::now() - begin);
        //if (n == SIZE) print_data(arr , n);
    return elapsed_ms.count();
}

void show(int a[], int b[], int n){// функція для виведення результату тестування функцій сортування
    cout << "count sort\n";
    cout << "increase\n";
    create_increase(a, n); //if (n == SIZE) print_data(a , n);
    cout << test_count(a, n)  << " ms" << endl;
    cout << "random\n";
    random_data(a, n); //if (n == SIZE) print_data(a , n);
    cout << test_count(a, n)  <<" ms" <<  endl;
    cout << "decrease\n";
    create_decrease(a, n); //if (n == SIZE) print_data(a , n);
    cout << test_count(a, n)  << " ms" << endl;

    cout << "\nselect sort\n";
    cout << "increase\n" ;
    create_increase(b, n); //if (n == SIZE) print_data(b , n);
    cout << test_select(b, n)  << " ms" <<  endl;
    cout << "random\n";
    random_data(b, n); //if (n == SIZE) print_data(b , n);
    cout << test_select(b, n)  << " ms" << endl;
    cout << "decrease\n";
    create_decrease(b, n); //if (n == SIZE) print_data(b , n);
    cout << test_select(b, n)  << " ms" << endl;
}


int main() {

    srand(time(NULL));

    int data[SIZE], data2[SIZE2], data3[SIZE3];
    int data_1[SIZE], data2_1[SIZE2], data3_1[SIZE3];

//    cout << "test data" << endl;
//    show(data, data_1, SIZE);
//
//    cout << "\n\ntest data2" << endl;
//    show(data2, data2_1, SIZE2);

    cout << "\n\ntest data3" << endl;
    show(data3, data3_1, SIZE3);

    return 0;
}











































//auto elapsed_ms = duration_cast < nanoseconds > (steady_clock::now() - begin);

//cout << "increase   \n" << test_count(a, n)  << " ms" << endl;


   // auto end = steady_clock::now();
   // auto elapsed_ms = duration_cast < milliseconds > (end - begin);



//void show1(int a[], int b[], int n){// функція для виведення результату тестування функцій сортування
//    cout << "count sort\n";
//    create_increase(a, n); print_data(a , n);
//    cout << "increase   \n" << test_count(a, n)  << "ms" << endl;
//    random_data(a, n); print_data(a , n);
//    cout << "random   \n" << test_count(a, n)  <<"ms" <<  endl;
//    create_decrease(a, n);  print_data(a , n);
//    cout << "decrease  \n" << test_count(a, n)  << "ms" << endl;
//
//    cout << "\nselect sort\n";
//    create_increase(b, n);  print_data(a , n);
//    cout << "increase   \n" << test_select(b, n)  << "ms" <<  endl;
//    random_data(b, n);  print_data(a , n);
//    cout << "random   \n" << test_select(b, n)  << "ms" << endl;
//    create_decrease(b, n);  print_data(a , n);
//    cout << "decrease   \n" << test_select(b, n)  << "ms" << endl;
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
//        int index = i; //index of min el
//
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
//    cout << "\n\n";
//}
//
//void test_count(int arr[], int n){
//    auto begin = steady_clock::now();
//    count_sort(arr, n);
//    auto end = steady_clock::now();
//    auto elapsed_ms = duration_cast < milliseconds > (end - begin);
//    cout<<elapsed_ms.count()<<"ms\n";
//}
//
//void test_select(int arr[], int n){
//    auto begin = steady_clock::now();
//    select_sort(arr, n);
//    auto end = steady_clock::now();
//    auto elapsed_ms = duration_cast < milliseconds > (end - begin);
//    cout<<elapsed_ms.count()<<"ms\n";
//}
//
//void show(int a[], int b[], int n){
//
//    create_increase(a, n);
//    create_increase(b, n);
//    test_count(a, n);
//    test_select(b, n);
//    random_data(a, n);
//    random_data(b, n);
//    test_count(a, n);
//    test_select(b, n);
//    create_decrease(a, n);
//    create_decrease(b, n);
//    test_count(a, n);
//    test_select(b, n);
//}
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
//








//
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
//        int index = i; //index of min el
//
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
//    cout << "\n\n";
//}
//
//void test_count(int arr[], int n){
//    auto begin = steady_clock::now();
//    count_sort(arr, n);
//    auto end = steady_clock::now();
//    auto elapsed_ms = duration_cast < milliseconds > (end - begin);
//    cout<<elapsed_ms.count()<<"ms\n";
//}
//
//void test_select(int arr[], int n){
//    auto begin = steady_clock::now();
//    select_sort(arr, n);
//    auto end = steady_clock::now();
//    auto elapsed_ms = duration_cast < milliseconds > (end - begin);
//    cout<<elapsed_ms.count()<<"ms\n";
//}
//
//void trata(int a[], int b[], int n){
//    cout << "count sort\n 1 increase 2 random 3 decrease\n";
//    create_increase(a, n);
//    test_count(a, n);
//    random_data(a, n);
//    test_count(a, n);
//    create_decrease(a, n);
//    test_count(a, n);
//cout << "select sort\n 1 increase 2 random 3 decrease\n";
//    create_increase(b, n);
//    test_select(b, n);
//    random_data(b, n);
//    test_select(b, n);
//    create_decrease(b, n);
//    test_select(b, n);
//}
//int main() {
//
//    srand(time(NULL));
//
//    int data[SIZE], data2[SIZE2], data3[SIZE3];
//    int data_1[SIZE], data2_1[SIZE2], data3_1[SIZE3];
//
//    cout << "test data " << endl;
//    trata(data, data_1, SIZE);
//
//    cout << "\n\ntest data2 " << endl;
//        trata(data2, data2_1, SIZE2);
//
//    cout << "\n\ntest data3 " << endl;
//        trata(data3, data3_1, SIZE3);
//
//    return 0;
//}



//
//    int data[SIZE], data2[SIZE2],data3[SIZE3];
//
//    create_increase(data, SIZE);
//    create_increase(data2, SIZE2);
//    create_increase(data3, SIZE3);
//
//    create_decrease(data, SIZE);
//    create_decrease(data2, SIZE2);
//    create_decrease(data3, SIZE3);
//
//    random_data(data, SIZE);
//    random_data(data2, SIZE2);
//    random_data(data3, SIZE3);
//
//
//    cout << "test data " << endl;
//    test_count(data, SIZE);
//    test_count(data, SIZE);
//    test_select(data, SIZE);
//
//    cout << "\n\ntest data2 " << endl;
//    test_count(data2, SIZE2);
//    test_count(data2, SIZE2);
//    test_select(data2, SIZE2);
//
//    cout << "\n\ntest data3 " << endl;
//    test_count(data3, SIZE3);
//    test_count(data3, SIZE3);
//    test_select(data3, SIZE3);

//
//
//
//
//
//
//
//
//    int data_d1[SIZE], data2_d1[SIZE2],data3_d1[SIZE3];
//    int data_d2[SIZE], data2_d2[SIZE2],data3_d2[SIZE3];
//    int data_r1[SIZE], data2_r1[SIZE2],data3_r1[SIZE3];
//    int data_r2[SIZE], data2_r2[SIZE2],data3_r2[SIZE3];
//    int data_i1[SIZE], data2_i1[SIZE2],data3_i1[SIZE3];
//    int data_i2[SIZE], data2_i2[SIZE2],data3_i2[SIZE3];
//
//    create_decrease(data_d1, SIZE);
//    create_decrease(data_d2, SIZE);
//    create_decrease(data2_d1, SIZE2);
//    create_decrease(data2_d2, SIZE2);
//    create_decrease(data3_d1, SIZE3);
//    create_decrease(data3_d2, SIZE3);
//
//    random_data(data_r1, SIZE);
//    random_data(data_r2, SIZE);
//    random_data(data2_r1, SIZE2);
//    random_data(data2_r2, SIZE2);
//    random_data(data3_r1, SIZE3);
//    random_data(data3_r2, SIZE3);
//
//
//    create_increase(data_i1, SIZE);
//    create_increase(data_i2, SIZE);
//    create_increase(data2_i1, SIZE2);
//    create_increase(data2_i2, SIZE2);
//    create_increase(data3_i1, SIZE3);
//    create_increase(data3_i2, SIZE3);
//
//
//    cout << "test data " << endl;
//    test_count(data_d1, SIZE);
//    test_count(data_d2, SIZE);
//    test_count(data_r1, SIZE);
//    test_select(data_r2, SIZE);
//    test_select(data_i1, SIZE);
//    test_select(data_i2, SIZE);
//
//    cout << "\n\ntest data2 " << endl;
//    test_count(data2_d1, SIZE2);
//    test_count(data2_d2, SIZE2);
//    test_count(data2_r1, SIZE2);
//    test_select(data2_r2, SIZE2);
//    test_select(data2_i1, SIZE2);
//    test_select(data2_i2, SIZE2);
//
//    cout << "\n\ntest data3 " << endl;
//    test_count(data3_d1, SIZE3);
//    test_count(data3_d2, SIZE3);
//    test_count(data3_r1, SIZE3);
//    test_select(data3_r2, SIZE3);
//    test_select(data3_i1, SIZE3);
//    test_select(data3_i2, SIZE3);
