//node.h
//Amrit Pandher
//12/4/2020
//node header file

#ifndef NODE
#define NODE

#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next = NULL;
};
#endif