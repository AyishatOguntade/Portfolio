#pragma once
#include <iostream>


class PNode{
    private:
        int data;
        int priority; 
        PNode* next;


        friend class PriorityQ;
    public:
        PNode();
        // Overloading
        PNode(int data,int priority);
        PNode(int data,int priority, PNode* next);
        ~PNode();
        // should i still use setters and getters 
        /*
        int getData() const {return data;}
        PNode* getNext() const {return next;}
        void setNext(PNode* nextPNode){next = nextPNode;}
        */
        
};
