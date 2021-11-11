#include <iostream>
#include <chrono>

#define SIZE 10
#define SIZE2 10000

using namespace std;
using namespace chrono;

struct List {
    int value;
    List *next, *prev;//вказівники на попередній та наступний вузли
};

void push(List **head, int num) {//функція для додання елемента до списку
    List *new_list = new List(); //виділення пам'яті для new_list
    new_list->value = num;//додання значення num до new_list
    new_list->next = (*head);//вказівник на наступний new_list стає head
    new_list->prev = NULL;//вказівник на наступний new_list стає NULL
    if ((*head) != NULL)
        (*head)->prev = new_list;//попередній вузол head стає new_list
    (*head) = new_list; //головою стає new_list
}

List create_list(List **head) {//функція для створення списку користувачем
    int a;
    cout << "Enter values for list" << endl;
    for(int i = 0; i < SIZE; ++i) {
        cin >> a;
        push(head, a);//внесення введених даних
    }
    return **head;
}

List random_list(List **head, int size = SIZE2) {//функція для рандомного задання списку
    for(int i = 0; i < size; ++i) {
        int a = rand() / (RAND_MAX / (size - i) + 1);
        push(head, a);
    }
    return **head;
}

void check_list(List *listp) {
    int count = 0;
    int max = 0;
    for ( ; listp != NULL; listp = listp->next) {
        if(listp->value % 2 == 0  && listp->value != 0)
            count++;
        else count = 0;
        if (count > max)
            max = count;
    }
    cout << max << endl;
}

void print_list(const List *listp) {//функція друку списку в прямому порядку
    cout << "Entered list" << endl;
    for ( ; listp != NULL; listp = listp->next)
        cout << listp->value << ' ';
    cout << endl;
}

int create_array(int *arr, int size = SIZE) {//функція для введення масиву
    cout << "Enter values for array" << endl;
    for(int i = 0; i < size; ++i)
        cin >> arr[i];
    return *arr;
}

void random_array(int *arr, int size = SIZE2) {//функція для створення рандомного масиву
    for (int i = 0; i < size - 1; ++i)
        arr[i] = rand() / (RAND_MAX / (size - i) + 1);
}

void print_array(const int *arr, int size = SIZE) {//функція для друку масиву
    cout << "Entered array" << endl;
    for (int i = 0; i < size; ++i)
        cout << arr[i] << ' ';
    cout << "\n\n";
}

void check(int *arr, int size = SIZE){//функція для перевірки масиву
    int count = 0;//лічильник для підраховування послідовності
    int max = 0;//змінна для визначення найбільшої послідовності

    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0 && arr[i] != 0)//перевірка на парність
            ++count;
        else count = 0;//якщо знайдено непарний елемент
        if (count > max)
            max = count;//визначення найбільшої послідовності
    }
    cout << max << endl;
}

void test_array(int *arr1, int *arr2, int size1 = SIZE, int size2 = SIZE2) { //функція для тестування тривалості сортування підрахуноком

    cout << "\ntest array" << endl;
    auto begin = steady_clock::now();
    check(arr1, size1);
    auto elapsed_ms = duration_cast < nanoseconds > (steady_clock::now() - begin);
    cout <<  elapsed_ms.count() << " ns" << "\n\n";

    cout << "test array2" << endl;
    auto begin1 = steady_clock::now();
    check(arr2, size2);
    auto elapsed_ms1 = duration_cast < nanoseconds > (steady_clock::now() - begin1);
    cout <<  elapsed_ms1.count() << " ns" << "\n\n";

}

void test_list(List *listp1, List  *listp2) { //функція для тестування тривалості сортування підрахуноком

    cout << "\ntest listp1" << endl;
    auto begin = steady_clock::now();
    check_list(listp1);
    auto elapsed_ms = duration_cast < nanoseconds > (steady_clock::now() - begin);
    cout <<  elapsed_ms.count() << " ns" << "\n\n";

    cout << "test listp2" << endl;
    auto begin1 = steady_clock::now();
    check_list(listp2);
    auto elapsed_ms1 = duration_cast < nanoseconds > (steady_clock::now() - begin1);
    cout <<  elapsed_ms1.count() << " ns" << "\n\n";

}

int main() {
    srand(time(NULL));
    List *list1 = NULL, *list2 = NULL;
    int array[SIZE], array2[SIZE2];

    create_array(array);
    print_array(array);

    random_array(array2);
    test_array(array, array2);

    create_list(&list1);
    print_list(list1);

    random_list(&list2);
    test_list(list1, list2);

    return 0;
}




//DLL
//Time Complexity: O(N)
//Auxiliary Space: O(1)
//deleting el: O(1)


//Array
//Search: O(N)























//
//void print_list(const List *listp) {//функція друку списку в прямому порядку
//    const List *last;
//    cout << "Entered list" << endl;
//    for ( ; listp != NULL; last = listp, listp = listp->next)
//        cout << listp->value << ' ';
//    cout << endl;
//}






//void check_list(List* listp) {
//    int count = 0, res = 0; int max_ = 0;
//    for (; listp != NULL; listp = listp->next) {
//        res = max(res, listp->value % 2 ? count = 0 : ++count);
//    }
//    cout << count << endl;
//}
//
//

//
//
//40
//20
//17
//16
//10
//8
//34
//36
//43
//57





//
//40
//20
//37
//2
//6
//8
//22
//46
//75
//23



//
//void check(int *arr, int size = SIZE) {
//    int count = 0; int max = 0; int num;
//
//        for (int i = 0; i < size; ++i) {
//            if (arr[i] % 2 == 0)
//                ++count;
//        if (count > max) {
//            max = count; num = i + 1;
//        }
//    }
//    cout << max << endl;
//        for (int i = num - max_i + 1; i < num + 1; ++i)
//            cout << arr[i] << ' ';
//        cout << endl;
//
//}


//void check(int *arr, int size = SIZE) {
//    int count = 0; int max = 0; int num;
//
//        for (int i = 0; i < size; ++i) {
//            if (arr[i] % 2 == 0)
//                ++count;
//        if (count > max) {
//            max = count; num = i + 1;
//        }
//    }
//    cout << max << endl;
//        for (int i = num - max_i + 1; i < num + 1; ++i)
//            cout << arr[i] << ' ';
//        cout << endl;
//
//}








//
//void check_list(List *listp) {
//    int count = 0; int max_i = 0;
//	for ( ;listp != NULL; listp = listp->next){
//        if(listp->value%2 == 0 && listp->next->value%2 == 0 && listp->value < listp->next->value){
//            //cout << listp->value << " < " << listp->next->value << endl;
//                count++;
//        }
//        else count = 0;
//        if (count > max_i)
//            max_i = count;
//    }
//    cout << max_i << endl;
//}
//
//
//void check_list(List *listp){
//    int count = 0; int max;
//	for ( ;listp != NULL; listp = listp->next){
//       if(listp->value % 2 == 0 && listp->next->value % 2 == 0){
//                count++;
//        }
//        else  count = 0;
//        if (count > max_i){
//            max_i = count;
//        }
//	}
//    cout << max_i << endl;
//}

