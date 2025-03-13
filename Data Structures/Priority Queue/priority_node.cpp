#include"priority_node.h"
#include<iostream>

PNode::PNode(){
    this->data = 0;
    this->priority =0;
    this->next = nullptr;
}

PNode::PNode(int data,int priority){
    this->data = data;
    this->priority = priority;
    this->next = nullptr;

}

PNode::PNode(int data,int priority, PNode* next){
    this->data = data;
    this->priority = priority; 
    this->next = next;
}

PNode::~PNode(){
    if(this->next != nullptr){
        delete this->next;
    }
}
