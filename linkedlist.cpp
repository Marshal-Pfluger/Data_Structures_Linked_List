/*********************
 * Name:Marshal Pfluger
 * Coding 05
 * Purpose: Create a fully functional doubly linked list
 * class as described in class and in your text. Create a
 * linked list object from your class. Demonstrate complete
 * testing and full functionality of your linked list.
**********************/
#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = nullptr;
}

bool LinkedList::addNode(int id, string* str)
{
    Node *current = head;
    bool ret = false;
    //Check for invalid data(negative id, or empty string)
    if(id > 0 && str != nullptr)
    {
        //Check if head is nullptr
        if(head)
        {
            //start to find correct position for new node
            while(current->next != nullptr && id > current->data.id)
            {
                current = current->next;
            }//Check if correct position is a new head
            if(id < current->data.id && current->prev == nullptr && id != current->data.id)
            {
                addHead(id, str);
                ret = true;
            }else
            {//Check if correct position is a new middle node
                if(id < current->data.id && id != current->data.id && current->prev != nullptr)
                {
                    addMiddle(current, id, str);
                    ret = true;
                }
            }//Check if correct position is a new tail
            if(id > current->data.id && current->next == nullptr && id != current->data.id)
            {
                addTail(current, id, str);
                ret = true;
            }
        }else
        {//creates first node in a new list
            Node *newNode = memAllocator(id, str);
            head = newNode;
            ret = true;
        }
    }
    return ret;
}

//Private member function allocates memory for add node functions.
Node* LinkedList::memAllocator(int id, string* str) {
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *str;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

//Private member function to add new head.
void LinkedList::addHead(int id, string* str)
{
    Node *newNode = memAllocator(id, str);
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

//Private member function to add middle Node
void LinkedList::addMiddle(Node *current, int id, string* str)
{
    Node *newNode = memAllocator(id, str);
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
}

//Private member function to add tail
void LinkedList::addTail(Node *current, int id, string* str)
{
    Node *newNode = memAllocator(id, str);
    newNode->prev = current;
    current->next = newNode;
}

//Deletes node based on id passed from caller
bool LinkedList::deleteNode(int id)
{
    Node *current = head;
    bool ret = false;
    while (current && id != current->data.id)
    {
        current = current->next;
    }
    if (current && id == current->data.id)
    {
        if (current->next && current->prev)
        {
            current->next->prev = current->prev;
            current->prev->next = current->next;
            delete current;
            ret = true;
        } else if (current->prev)
        {
            current->prev->next = nullptr;
            delete current;
            ret = true;
        } else if (current->next)
        {
            head = current->next;
            current->next->prev = nullptr;
            delete current;
            ret = true;
        } else
        {
            delete current;
            head = nullptr;
            ret = true;
        }
    }
    return ret;
}

//Returns data from id passed from caller
bool LinkedList::getNode(int id, Data *tempdata)
{
    Node *current = head;
    bool ret = false;
    while(current)
    {
        if (id == current->data.id)
        {
            tempdata->id = current->data.id;
            tempdata->data = current->data.data;
            ret = true;
        }
        current = current->next;
    }
    if (!ret)
    {
        tempdata->id = -1;
        tempdata->data = " ";
    }
    return ret;
}

//Display contents of the list
void LinkedList::printList(bool backwards)
{
    Node *current = head;
    if (!backwards)
    {
        while(current)
        {
            std::cout << current->data.id << ": " << current->data.data << std::endl;
            current = current->next;
        }
    } else
    {
        while(current->next)
        {
            current = current->next;
        }
        while(current)
        {
            std::cout << current->data.id << ": " << current->data.data << std::endl;
            current = current->prev;
        }
    }
}

//determines the total number of nodes in the list
int LinkedList::getCount()
{
    Node *current = head;
    int count = 0;
    while(current)
    {
        count ++;
        current = current->next;
    }
    return count;
}

//deletes the contents of the entire list.
void LinkedList::clearList()
{
    Node *current = head;
    while(current)
    {
        head = head->next;
        delete current;
        current = head;
    }
    head = nullptr;
}

//checks if an id that is passed by caller is in list
bool LinkedList::exists(int id)
{
    Node *current = head;
    bool ret = false;
    while(current)
    {
        if(id == current->data.id)
        {
            ret = true;
        }
        current = current->next;
    }
    return ret;
}

//Destructor for program
LinkedList::~LinkedList()
{
    clearList();
}


