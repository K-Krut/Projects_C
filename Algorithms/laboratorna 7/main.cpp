#include <iostream>
#include <ctime>
#include <cstring>

#define SIZE 10

using namespace std;

static clock_t clock_start;

typedef struct Tree {
    int value;
    Tree *left;
    Tree *right;
} Tree;

Tree *tree = NULL, *res = NULL;

Tree *tree_insert(Tree *tree, int value) {
    if(tree == NULL) {
        tree = new Tree;
        tree->value = value;
        tree->left = NULL;
        tree->right = NULL;
    } else if (value < tree->value)
        tree->left = tree_insert(tree->left, value);
    else
        tree->right = tree_insert(tree->right, value);
    return tree;
}

Tree *recursive_search(Tree *tree, int value) {
    if(tree == NULL)
        return NULL;
    if(value == tree->value)
        return tree;
    else if(value < tree->value)
        return recursive_search(tree->left, value);
    else
        return recursive_search(tree->right, value);
}

Tree *iterative_search(Tree *tree, int value) {
    while(tree != NULL) {
        if(value == tree->value)
            return tree;
        else if(value < tree->value)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return NULL;
}

void display_tree(Tree* tree) {
    if(tree == NULL)
        return;
    display_tree(tree->left);
    display_tree(tree->right);
    cout << tree->value << ' ';
}

void insert() {
    int a;
    cout << "Enter value to insert" << endl;
    for(int i = 0; i < SIZE; ++i) {
        cin >> a;
        tree = tree_insert(tree, a);
    }
}
void search_r() {
    int a;
    cout << "Enter value to search recursive" << endl;
    cin >> a;
    if (res = recursive_search(tree, a))
        cout << "Searched value: "  << res->value << endl;
    else
        cout << "Value not searched" << endl;
}
void search_iter() {
    int a;
    cout << "Enter value to search iterative" << endl;
    cin >> a;
    if (res = iterative_search(tree, a))
        cout << "Searched value: "  << res->value << endl;
    else
        cout << "Value not searched" << endl;
}

int main() {

    insert();
    display_tree(tree);
    cout << endl;
    search_r();
    search_iter();

    return 0;
}


















//
//#include <iostream>
//#include <ctime>
//#include <cstring>
//
//#define SIZE 10
//
//using namespace std;
//
//static clock_t clock_start;
//
//typedef struct Tree {
//    int value;
//    Tree *left;
//    Tree *right;
//} Tree;
//
//Tree *tree = NULL, *res = NULL;
//
//void timer_start() {
//    clock_start = clock();
//}
//
//double timer_elapsed() {
//    return ((double) clock() - clock_start) / CLOCKS_PER_SEC;
//}
//
//Tree *tree_insert(Tree *tree, int value) {
//    if(tree == NULL) {
//        tree = new Tree;
//        tree->value = value;
//        tree->left = NULL;
//        tree->right = NULL;
//    } else if (value < tree->value)
//        tree->left = tree_insert(tree->left, value);
//    else
//        tree->right = tree_insert(tree->right, value);
//    return tree;
//}
//
//Tree *recursive_search(Tree *tree, int value) {
//    if(tree == NULL)
//        return NULL;
//    if(value == tree->value)
//        return tree;
//    else if(value < tree->value)
//        return recursive_search(tree->left, value);
//    else
//        return recursive_search(tree->right, value);
//}
//
//Tree *iterative_search(Tree *tree, int value) {
//    while(tree != NULL) {
//        if(value == tree->value)
//            return tree;
//        else if(value < tree->value)
//            tree = tree->left;
//        else
//            tree = tree->right;
//    }
//    return NULL;
//}
//
//void display_tree(Tree* tree) {
//    if(tree == NULL)
//        return;
//    display_tree(tree->left);
//    display_tree(tree->right);
//    cout << tree->value << ' ';
//}
//
//void insert() {
//    int a;
//    cout << "Enter value to insert" << endl;
//    for(int i = 0; i < SIZE; ++i) {
//        cin >> a;
//        tree = tree_insert(tree, a);
//    }
//}
//void search_r() {
//    int a;
//    cout << "Enter value to search recursive" << endl;
//    cin >> a;
//    if (res = recursive_search(tree, a))
//        cout << "Searched value: "  << res->value << endl;
//    else
//        cout << "Value not searched" << endl;
//}
//void search_iter() {
//    int a;
//    cout << "Enter value to search iterative" << endl;
//    cin >> a;
//    if (res = iterative_search(tree, a))
//        cout << "Searched value: "  << res->value << endl;
//    else
//        cout << "Value not searched" << endl;
//}
//
//Tree* min_value(Tree *tree) {
//    Tree* current = tree;
//    while (current && current->left != NULL)
//        current = current->left;
//    return current;
//}
//Tree *delete_tree_leaf(Tree *tree, int value) {
//    if (tree == NULL)
//        return tree;
//    if (value < tree->value)
//        tree->left = delete_tree_leaf(tree->left, value);
//    else if (value > tree->value)
//        tree->right = delete_tree_leaf(tree->right, value);
//    else {
//        if (tree->left == NULL) {
//            struct Tree* temp = tree->right;
//            delete tree;
//            return temp;
//        } else if (tree->right == NULL) {
//            struct Tree* temp = tree->left;
//            delete tree;
//            return temp;
//        }
//        struct Tree* temp = min_value(tree->right);
//        tree->value = temp->value;
//        tree->right = delete_tree_leaf(tree->right, temp->value);
//    }
//    return tree;
//}
//
//void delete_leaf() {
//    int a;
//    cout << "Enter value to be deleted" << endl;
//    cin >> a;
//    if(iterative_search(tree, a)){
//        res = delete_tree_leaf(tree, a);
//    cout << a << " was deleted from tree" << endl;
//    }
//    else
//        cout << a << " doesn't exist in tree" << endl;
//}
//
//int main() {
//
//    insert();
//    display_tree(tree);
//    cout << endl;
//
//    search_r();
//    search_iter();
//
//    delete_leaf();
//    display_tree(tree);
//
//    return 0;
//}
//
//
//
































//Tree *delete_tree(Tree *tree) {
//    if(tree == NULL)
//        return NULL;
//    else {
//        delete_tree(tree->left);
//        delete_tree(tree->right);
//        delete tree;
//    }
//    return NULL;
//}
