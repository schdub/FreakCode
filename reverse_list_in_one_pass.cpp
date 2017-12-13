#include <iostream>

template <class T> struct list_node {
    T data;
    list_node<T> *next;
};

int main() {
    list_node<int> *root, *prev = NULL, *next = NULL;

    // create one linked list with numbers 1..10
    for (int i = 10; i > 0; --i) {
        next = prev;
        prev = new list_node<int>();
        prev->data = i;
        prev->next = next;
    }
    root = prev;

    // print: 1 2 3 4 5 6 7 8 9 10
    for (list_node<int> *cur = root; cur; cur = cur->next)
        std::cout << " " << cur->data;
    std::cout << std::endl;

    // reverse one linked list in one pass
    prev = NULL;
    for (list_node<int> *cur = root; cur;) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    root = prev;

    // print: 10 9 8 7 6 5 4 3 2 1
    for (list_node<int> *cur = root; cur; cur = cur->next)
        std::cout << " " << cur->data;
    std::cout << std::endl;

    return 0;
}
