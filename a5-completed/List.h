/*
 * Purpose of the class: The template class for a linked list.
 *
 * Node: The inner class that represents a node in the linked list.
 * Node *head: The head of the linked list.
 *
 * List(): The constructor for the List class.
 * ~List(): The destructor for the List class.
 * List<T> &operator+=(T): The overloaded += operator for the List class. Adds a new element to the end of the list.
 * void convertToArray(T *, int &): Converts the linked list to an array and outputs the size of the array.
 */

#ifndef LIST_H
#define LIST_H

template <class T>
class List
{
    class Node
    {
    public:
        T data;
        Node *next;
    };

public:
    List();
    ~List();
    List<T> &operator+=(T);
    void convertToArray(T *, int &);

private:
    Node *head;
};

#include <iostream>
using namespace std;

template <class T>
List<T>::List() : head(nullptr){

                  };

template <class T>
List<T>::~List()
{
    Node *currNode = head;
    Node *nextNode;

    while (currNode != nullptr)
    {
        nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }
}

template <class T>
List<T> &List<T>::operator+=(T s)
{
    Node *newNode = new Node;
    Node *currNode;
    Node *prevNode;

    newNode->data = s;
    newNode->next = nullptr;

    currNode = head;
    prevNode = nullptr;

    while (currNode != nullptr)
    {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (prevNode == nullptr)
    {
        head = newNode;
    }
    else
    {
        prevNode->next = newNode;
    }

    return *this;
};

template <class T>
void List<T>::convertToArray(T *arr, int &size)
{
    Node *currNode = head;
    size = 0;

    while (currNode != nullptr)
    {
        if (currNode->data != nullptr)
        {
            arr[size] = currNode->data;
        }
        currNode = currNode->next;
        size++;
    }
};

#endif
