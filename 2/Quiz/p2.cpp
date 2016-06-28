#include "p2.hpp"
#include <iostream>
namespace oop{

	Node* push(Node *top,int n){
	    if(top==NULL){
            top=new Node;
            top->num=n;
            top->next=NULL;
	    }
	    else{
            Node* tracker=top;
            while(tracker->next!=NULL)
                tracker=tracker->next;
            tracker->next=new Node;
            tracker->next->num=n;
            tracker->next->next=NULL;
	    }
	    return top;
	}
    Node* pop(Node *top){
        if(top!=NULL){
            Node* tracker=top;
            if(tracker->next==NULL){
                delete top;
                return NULL;
            }
            else{
                while(tracker->next->next!=NULL)
                    tracker=tracker->next;
                delete tracker->next;
                tracker->next=NULL;
                return top;
            }
        }
        else
            return NULL;
	}
    void print(Node *top ){
     //Output specification: top->space->top->space->¡K¡K
     //std::cout<<top<<" "; //show example
        Node *dupli=NULL;
        while(top!=NULL){
            dupli=push(dupli,top->num);
            top=top->next;

        }
        while(dupli!=NULL){
            Node* tracker=dupli;
            while(tracker->next!=NULL)
                tracker=tracker->next;
            std::cout<<tracker->num<<" ";
            dupli=pop(dupli);
        }
        return;
    }
}

