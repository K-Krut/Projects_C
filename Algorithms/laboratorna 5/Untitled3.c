#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

class List
{
public:
    int data;
    List *next;
    List *prev;
};

void printList(List *list)
{
    List *last;
    cout << "\nTraversal in forward direction \n";
    while (list != NULL)
    {
        cout << " " << list->data << " ";
        last = list;
        list = list->next;
    }
}

bool uppercheckList(List *list){
    List *last;
    while (list != NULL)
    {
        if (list < list->next)
            if (list->next < list->next->next)
                if (list->next->next < list->next->next->next)
                    if (list->next->next->next < list->next->next->next->next)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                    list = list->next;
    }
}


bool lowercheckList(List *list){
    List *last;
    while (list != NULL)
    {

        if (list > list->next)
            if (list->next > list->next->next)
                if (list->next->next > list->next->next->next)
                    if (list->next->next->next > list->next->next->next->next)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                    list= list->next;
    }
}

void push(List **head_ref, int new_data)
{
    /* 1. allocate list */
    List *new_list = new List();

    /* 2. put in the data */
    new_list->data = new_data;

    /* 3. Make next of new list as head
    and previous as NULL */
    new_list->next = (*head_ref);
    new_list->prev = NULL;

    /* 4. change prev of head list to new list */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_list;

    /* 5. move the head to point to the new list */
    (*head_ref) = new_list;
}

void print(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

void rand(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 10;
    }
}

// bool check(int array[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         if (array[i] +1 == array[i + 1])
//             if (array[i+1] + 1 == array[i + 2])
//                 if (array[i + 2] + 1 == array[i+3])
//                     if (array[i+3] + 1 == array[i + 4])
//         {
//             cout << "u have ordered array" << endl;
//             return true;
//         }
//         else
//         {
//             cout << "u have no ordered array" << endl;
//             return false;
//         }
//     }
// }
bool uppercheck(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] < array[i + 1])
            if (array[i + 1] < array[i + 2])
                if (array[i + 2] < array[i + 3])
                    if (array[i + 3] < array[i + 4])
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
    }
}
bool lowercheck(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {

        if (array[i] > array[i + 1])
            if (array[i + 1] > array[i + 2])
                if (array[i + 2] > array[i + 3])
                    if (array[i + 3] > array[i + 4])
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
    }
}

быртр, [06.04.21 10:53]
void arraycheck(int array[], int n)
{
    auto begin = steady_clock::now();
    if (uppercheck(array, n) == true)
    {
        cout << "u have ordered (from the smallest to the biggest element) array" << endl;
    }
    else if (lowercheck(array, n) == true)
    {
        cout << "u have ordered (from the biggest to the smallest element) array" << endl;
    }
    else
    {
        cout << "u have no ordered array" << endl;
    }
    auto end = steady_clock::now();
    auto elapsed_ms = duration_cast<nanoseconds>(end-begin);
    cout<<elapsed_ms.count()<<"ns\n";
}

void listcheck(List* list)
{
    auto begin = steady_clock::now();
    if (uppercheckList(list) == true)
    {
        cout << "u have ordered (from the smallest to the biggest element) list" << endl;
    }
    else if (lowercheckList(list) == true)
    {
        cout << "u have ordered (from the biggest to the smallest element) list" << endl;
    }
    else
    {
        cout << "u have no ordered list" << endl;
    }
    auto end = steady_clock::now();
    auto elapsed_ms = duration_cast<nanoseconds>(end-begin);
    cout<<elapsed_ms.count()<<"ns\n";
}
int main()
{
    srand(time(NULL));
    List *tail = NULL;
    List *head = NULL;
    int array1[10000], array2[200];
    int array[10] = {1, 2, 3, 4, 5, 5, 5, 5, 5, 5};
    push(&tail, 5);
    push(&tail, 5);
    push(&tail, 5);
    push(&tail, 5);
    push(&tail, 5);
    push(&tail, 5);
    push(&tail, 5);
    push(&tail, 5);
    push(&tail, 5);
    push(&tail, 5);


        for (int i = 0; i < 10000; i++)
    {
        int p=rand()%10;
        push(&head, p);
    }

    rand(array1, 10000);
    print(array, 10);
    cout<<endl<<"Check 10 elements of array: "<<endl;
    arraycheck(array, 10);
    cout<<endl<<"Check 10000 elements of array: "<<endl;
    arraycheck(array1, 10000);
    printList(tail);
    cout<<endl<<"Check 10 elements of list: "<<endl;
    listcheck(tail);
    cout<<endl<<"Check 10000 elements of list: "<<endl;
    listcheck(head);
    return 0;
}
