#include <iostream>
#include <ctime>
#include <cassert>

#define SIZE_OF_STACK 10

using namespace std;

class Stack {
    int index;
    int stack[SIZE_OF_STACK];
  public:

    Stack() {
        index = -1;
    }
    int is_Empty() {
        return index = -1;
    }
    void push_array(int value);
    int pop_array();
    void rand_array();
    void display_array_stack();
    void max_array_stack();
    void min_array_stack();
};
void Stack::push_array(int value) {
    stack[++index] = value;
}

int Stack::pop_array() {
    if(index == -1) {
        cout << "Emty stack\n";
        return 0;
    }
    int j = stack[index--];
    return j;
}

void Stack::rand_array() {
    for(int i = 0; i < SIZE_OF_STACK; ++i){
        push_array(rand() % 64);
    }
}

void Stack::display_array_stack() {
    if(index == 0) {
        cout << "Empty stack\n";
        return;
    }
    for(int i = 0; i < SIZE_OF_STACK ; ++i)
        cout << pop_array() << ' ';
    cout << endl;
}
void Stack::max_array_stack() {
    int max = INT_MIN;
    int count = 0;
    for(int i = 0; i < SIZE_OF_STACK; ++i) {
        if(stack[i] > max) {
            max = stack[i];
            count = i;
        }
    }
    cout << "max element: " << max << " it's position: " << count << endl;
}

void Stack::min_array_stack() {
    int min = INT_MAX;
    int count = 0;
    for(int i = 0; i < SIZE_OF_STACK; ++i) {
        if(stack[i] < min) {
            min = stack[i];
            count = i;
        }
    }
    cout << "min element: " << min << " it's position: " << count << endl;
}


class List {
    struct Node {
        int data;
        Node *next;
    };
    Node *top;

  public:
    List() {
        top == nullptr;
    }
    int Empty(){
        return top == nullptr;
    }
    void rand_list();
    int pop();
    void push_list(int data);
    void free_l();
    void max_list();
    void min_list();
    void show(){
    for(int i = 0; i < SIZE_OF_STACK; ++i)
        pop();
    }
};

void List::push_list(int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->next = top;
    top = temp;
}

void List::free_l() {
    if (Empty())
        return;
    Node *temp = top;
    top = top->next;
    delete temp;
}

void List::rand_list() {
    for(int i = 0; i < SIZE_OF_STACK; ++i)
        push_list(rand() % 64);
}

int List::pop() {
    if (Empty()) {
        cout << "list stack is empty"<< endl;
        return 0;
    }

    int k = top->data;
    top = top->next;
    return k;
//    for(Node *temp = top; temp != nullptr; temp = temp->next)
//        cout <<temp->data << ' ';
//    cout << endl;
}

void List::max_list() {
    int max = INT_MIN;
    int count = 0;
    Node *temp = top;
    for(int i = SIZE_OF_STACK - 1; temp != nullptr; temp = temp->next, --i) {
        if(temp->data > max) {
            count = i;
            max = temp->data;
        }
    }
    cout << "max element: " << max << " it's position: " << count << endl;
}

void List::min_list() {
    int min = INT_MAX;
    int count = 0;
    Node *temp = top;
    for(int i = SIZE_OF_STACK - 1; temp != nullptr; temp = temp->next, --i) {
        if(temp->data < min) {
            min = temp->data;
            count = i;
        }
    }
    cout << "min element: " << min << " it's position: " << count << endl;
}

void test_list_queue() {
    cout << "test list_queue" << endl;
    List b;
    b.rand_list();
    b.max_list();
    b.min_list();
    b.show();
}
void test_array_queue() {
    cout << "test aray_queue" << endl;
    Stack a;
    a.rand_array();
    a.display_array_stack();
    a.max_array_stack();
    a.min_array_stack();
}

int main() {
    srand(time(nullptr));
    test_list_queue();
    test_array_queue();
    return 0;
}
