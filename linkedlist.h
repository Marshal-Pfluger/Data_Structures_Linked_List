/*********************
 * Name:Marshal Pfluger
 * Coding 05
 * Purpose: Create a fully functional doubly linked list
 * class as described in class and in your text. Create a
 * linked list object from your class. Demonstrate complete
 * testing and full functionality of your linked list.
**********************/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "data.h"
#include <iostream>

class LinkedList{

private:
    Node *head;
    // Private member functions for addNode
    Node* memAllocator(int, string*);
    void addHead(int, string*);
    void addMiddle(Node*, int, string*);
    void addTail(Node*, int, string*);

public:
    LinkedList();
    ~LinkedList();
    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    // create default bool value for printlist
    void printList(bool = false);
    int getCount();
    void clearList();
    bool exists(int);
};

#endif //LINKEDLIST_H