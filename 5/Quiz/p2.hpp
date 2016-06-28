#include <bits/stdc++.h>
#include<iostream>
template<class Type, int MaxSize>
class Stack{
    std::vector <Type> body;
	//variables you need.
public:
	Stack(); //constructor of class Stack.
	void push(Type);//push function.
	Type pop();	//pop function.
	bool empty();	//return true if there has nothing in Stack.
	bool full();	//return true if Stack is full.
	void dump();	//print the items of Stack.
};

template<class Type, int MaxSize>
Stack<Type, MaxSize>::Stack(){}

template<class Type, int MaxSize>
void Stack<Type,MaxSize>::push(Type element){
    if(body.size()<MaxSize)
        body.push_back(element);
    else
        printf("Stack is already full.\n");
}

template<class Type, int MaxSize>
Type Stack<Type,MaxSize>::pop(){
    int output=body.back();
    if(!body.empty())
        body.pop_back();
    return output;
}

template<class Type, int MaxSize>
bool Stack<Type,MaxSize>::empty(){
    return body.empty();
}

template<class Type, int MaxSize>
bool Stack<Type,MaxSize>::full(){
    return body.size()>=MaxSize;
}

template<class Type, int MaxSize>
void Stack<Type,MaxSize>::dump(){
    int siz=body.size();
    for(int cnt=0;cnt<siz;cnt++){
        if(cnt>0) printf(" ");
        std::cout<<body[siz-1-cnt];
    }
}
