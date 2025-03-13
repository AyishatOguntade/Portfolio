#include "priority_queue.h"
#include <iostream> 
#include<vector>

// default constuctor
PriorityQ::PriorityQ(){
    this->head = nullptr;
    this->size = 0;

}
// constuctor with only one element/priority
//should I use std::pair here
PriorityQ::PriorityQ(int element, int priority){
    PNode* nn = new PNode(element, priority);
    this->head = nn;
    this->size = 1;
}

// constuctor to take in a vecor of pairs
PriorityQ::PriorityQ(std::vector<int> vec){
    if(vec.size() == 0){
        this->head = nullptr;
        this->size =0;
    }
    else{
        PNode* nn = new PNode(vec[0],0);
        this->head = nn;
        PNode* temp = this->head;
        for(int i = 1; i < vec.size();i++){
            temp->next = new PNode(vec[i], i);
            temp = temp->next;
        }

    }
    this->size = vec.size();

}

// deconstuctor 
PriorityQ::~PriorityQ(){
    PNode* temp = this->head;
    while(temp != nullptr){
        PNode* next = temp->next;
        delete temp;
        temp = next;
    }
    this->size = 0;
    this-> head = nullptr;

}
// shoudld this take in a pair as a paremeter or just an int 
void PriorityQ::enqueue(int element , int priority){
    PNode* nn = new PNode(element, priority);
    if(this->head == nullptr){
        this->head = nn;
        this->size++;
        return;
    }
    else if(nn->priority < head->priority){
        nn->next = this->head;
        this-> head = nn;
        this->size++;
        return;
    }
    PNode* temp = this->head;
    while(temp != nullptr){
        if(temp->next != nullptr && temp->next->priority > nn->priority){
            nn->next = temp->next;
            temp->next = nn;
            break;
        }
        else if(temp->next == nullptr){
            temp->next = nn;
            break;
        }
        temp = temp->next;//increment to next
    }
    this->size++;

}

void PriorityQ::dequeue(){
    if(head == nullptr){
        return;
    }
    this->head = this->head->next;// keep track or its gone
    this->size--;
}


//return the first element, maybe return a pair 
void PriorityQ::peek(){
    if(this->head == nullptr){
        std:: cout <<""<< std::endl;
    }
    else{
        std::cout << "("<< std::to_string(this->head->data) << ","<< std::to_string(this->head->priority)<<")"<<std::endl;
    }
}
//create the string that holds the list
std::string PriorityQ::to_string(){
    std::string stringified;
    PNode* tmp = this->head;

    while (tmp != nullptr) {
        stringified += "(" + std::to_string(tmp->data) + "," +std::to_string(tmp->priority) +") "; 
        tmp = tmp->next; 
    }

    return stringified;
}




