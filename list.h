//list.h
//Amrit Pandher
//12/4/2020
//list header file

#ifndef LIST
#define LIST

#include "node.h"
#include <iostream>
using namespace std;

template <class T>
class List
{
public:
    List(void)
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }            // constructor
    ~List(void); // destructor
    List(const List<T> &other);
    List<T> &operator=(const List<T> &other);

    bool IsEmpty()
    {
        return head == NULL;
    }
    Node<T> *InsertNode(int index, T x);
    int FindNode(T x);
    int DeleteNode(T x);
    void DisplayList(void);
    void AppendNode(T x);
    void AppendTail(T x); //faster way to append
    List<T> &operator+=(const List<T> &other);

    int size;
private:
    Node<T> *head = NULL;
    Node<T> *tail = NULL;
    
};

#endif