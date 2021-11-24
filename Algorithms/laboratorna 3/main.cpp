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

void random_data(int arr[], int n) {//ôóíêö³ÿ äëÿ ñòâîðåííÿ ðàíäîìíîãî ìàñèâó
    for (int i = 0; i < n - 1; ++i)
        arr[i] = rand() / (RAND_MAX / (n - i) + 1);
         //arr[i] = rand() % 10000;
}

void count_sort(int array[], int n) {

    int output[SIZE3];//ìàññèâ äëÿ çáåðåæåííÿ â³äñîðòîâàíîãî ñìàñèâó
    int count[SIZE3];//ìàñèâ äëÿ ï³äðóõóíêó ê³ëüêîñò³ îäíàêîâèõ åëåìåíò³â
    int max_el = array[0];//ìàêñèìàëüíèé åëåìåíò - ïåðùèé åëåìåíò

    for (int i = 1; i < n; ++i) {//ïîøóê íàéá³ëüøîãî åëåìåíòà â ìàñèâ³
        if (array[i] > max_el)
            max_el = array[i];
    }

    for (int i = 0; i <= max_el; ++i)//îáíóëåííÿ ìàñèâó count[]
        count[i] = 0;

    for (int i = 0; i < n; ++i)//çàïèñ ê³ëüêîñò³ ïîâòîðåíü êîæíîãî åëåìåíòà
        count[array[i]]++;

    for (int i = 1; i <= max_el; ++i)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; --i) {//ïîøóê ³íäåêñó êîæíîãî åëåìåíòà â îðèã³íàëüíîìó ìàñèâ³
        output[count[array[i]] - 1] = array[i];//òà ðîçì³ùåííÿ åëåìåíò³â â output[]
        --count[array[i]];
    }

    for (int i = 0; i < n; ++i)
        array[i] = output[i];//êîï³þâàííÿ åëåìåíò³â â³äñîðòîâàíèõ â îðèã³íàëüíèé ìàñèâ
}

void select_sort(int arr[], int n) {
    for(int i = 0; i < n - 1; ++i) {//ïðîõ³ä ïî âñ³õ åëåìåíòàõ ìàñèâó
        int index = i; //index of min el

        for(int j = i + 1; j < n; ++j){//ïîøóê ì³í³ìàëüíîãî åëåìåíòà â ìàñèâ³
            if (arr[j] < arr[index])
                index = j;
        }
        swap(arr[index], arr[i]);//ì³í³ìàëüíèé åëåìåíò ì³íÿºòüñÿ ì³ñöÿìè ç ïåðøèì
    }
}

void print_data(int array[], int n) {//ôóíêö³ÿ äðóêó ìàñèâó
    for (int i = 0; i < n; ++i)
        cout << array[i] << ' ';
    cout << "\n";
}

auto test_count(int arr[], int n){//ôóíêö³ÿ äëÿ òåñòóâàííÿ òðèâàëîñò³ ñîðòóâàííÿ ï³äðàõóíîêîì
    auto begin = steady_clock::now();//
    count_sort(arr, n);
    auto elapsed_ms = duration_cast < milliseconds > (steady_clock::now() - begin);
        //if (n == SIZE) print_data(arr , n);
    return elapsed_ms.count();
}

auto test_select(int arr[], int n) {//ôóíêö³ÿ äëÿ òåñòóâàííÿ òðèâàëîñò³ ñîðòóâàííÿ âèá³ðêîþ
    auto begin = steady_clock::now();
    select_sort(arr, n);
    auto elapsed_ms = duration_cast < nanoseconds > (steady_clock::now() - begin);
        //if (n == SIZE) print_data(arr , n);
    return elapsed_ms.count();
}

void show(int a[], int b[], int n){// ôóíêö³ÿ äëÿ âèâåäåííÿ ðåçóëüòàòó òåñòóâàííÿ ôóíêö³é ñîðòóâàííÿ
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
