#include "MyStack.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "Coordinate.h"

template<class T>
MyStack<T>::MyStack(){
    head=NULL;
    size=0;
}

template<class T>
MyStack<T>::~MyStack(){
    while(size)
        pop();
}

template<class T>
void MyStack<T>::push(T& input){
    Node* temp= new Node(input, head);
    head=temp;
    size++;
}

template<class T>
void MyStack<T>::pop(){
    Node* temp=head->next;
    delete head;
    size--;
    head=temp;
}

template<class T>
T& MyStack<T>::top(){
    return head->value;
}

template<class T>
size_t MyStack<T>::getSize()const{
    //return size;
    return size;
}

template<class T>
bool MyStack<T>::empty()const{

    return size==0/*!size*/;
}

template<class T>
MyStack<T>::Node::Node(T& value, Node* next):value(value){
    this->next=next;
}

template class MyStack <char >;
template class MyStack <Coordinate >;

/**
#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED
#include <cstddef> // for std:size_t
using namespace std;

template <class T>
class MyStack{
public:
    MyStack();
    ~MyStack();
    void push(T&);
    void pop();
    T& top();
    size_t getSize() const;
    bool empty() const;
private:
    class Node {
        friend class MyStack<T>;
    public:
        Node(T&, Node*);
    private:
        T &value;   // the value of the node
        Node *next; // a pointer to the next node
    };
    Node *head;  // a pointer to the head of the linked list
                 // also a pointer to the top of the stack
    size_t size; // the number of elements in the stack
};
#endif // MYSTACK_H_INCLUDED
*/
