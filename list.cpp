//list.cpp
//Amrit Pandher
//12/4/2020
//list implementation file

#include "list.h"
#include "UPCEntry.h"

template <class T>
List<T>::~List(void)
{
    Node<T> *currNode = head, *nextNode = NULL;
    cout << "destroy size: " << size << ", deleting... ";
    int count = 0;
    while (currNode != NULL)
    {
        nextNode = currNode->next;
        // destroy the current node
        delete currNode;
        cout << count++ << " ";
        currNode = nextNode;
    }
    cout << endl;
}

template <class T>
List<T>::List(const List<T> &other)
{
    Node<T> *currNode = other.head;
    while (currNode != NULL)
    {
        this->AppendTail(currNode->data);
        currNode = currNode->next;
    }
}

template <class T>
List<T> &List<T>::operator=(const List<T> &other)
{
    Node<T> *currNode = other.head;
    while (currNode != NULL)
    {
        this->AppendTail(currNode->data);
        currNode = currNode->next;
    }
    return *this;
}

template <class T>
Node<T> *List<T>::InsertNode(int index, T x)
{
    if (index < 0)
        return NULL;

    int prevIndex = 0;
    Node<T> *prevNode = this->head;
    while (prevNode != NULL && index - 1 > prevIndex)
    {
        prevNode = prevNode->next;
        prevIndex++;
    }
    if (index > 0 && prevNode == NULL)
        return NULL;

    Node<T> *newNode = new Node<T>;
    newNode->data = x;
    if (index == 0)
    {
        newNode->next = this->head;
        this->head = newNode;
    }
    else
    {
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
    size++;
    if (index == size - 1)
        this->tail = newNode;
    return newNode;
}

template <class T>
int List<T>::FindNode(T x)
{
    Node<T> *currNode = this->head;
    int currIndex = 0;
    while (currNode && currNode->data != x)
    {
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode)
        return currIndex;
    return -1;
}

template <class T>
int List<T>::DeleteNode(T x)
{
    Node<T> *prevNode = NULL;
    Node<T> *currNode = head;
    int currIndex = 0;
    while (currNode != NULL && currNode->data != x)
    {
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode)
    {
        if (prevNode)
        {
            prevNode->next = currNode->next;
            if (currNode->next == NULL)
                tail = prevNode;
        }
        else
        {
            head = currNode->next;
            if (currNode->next == NULL)
                tail = NULL;
        }
        delete currNode;
        size--;

        return currIndex;
    }
    return -1;
}

template <class T>
void List<T>::AppendNode(T x)
{
    InsertNode(size, x);
}

template <class T>
void List<T>::AppendTail(T x)
{
    if (this->head == NULL)
    {
        InsertNode(0, x);
    }
    else
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = x;
        //if (tail != NULL)
        this->tail->next = newNode;
        this->tail = newNode;
        size++;
    }
}

// this has problem;
template <class T>
List<T> &List<T>::operator+=(const List<T> &other)
{
    // size += other.size;
    // if (head == NULL)
    // {
    //     head = other.head;
    //     tail = other.tail;
    // }
    // {
    //     tail->next = other.head;
    //     tail = other.tail;
    // }

    Node<T> *currNode = other.head;
    while (currNode != NULL)
    {
        this->AppendTail(currNode->data);
        currNode = currNode->next;
    }

    return *this;
}

template <class T>
void List<T>::DisplayList()
{
    Node<T> *currNode = head;
    cout << "head->";
    while (currNode != NULL)
    {
        cout << currNode->data << "->";
        currNode = currNode->next;
    }
    cout << "NULL. Size: " << size << endl;
}

template class List<UPCEntry>;