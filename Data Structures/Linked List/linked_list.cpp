#include "linked_list.h"
#include <iostream>


LinkedList::LinkedList(){ //this->head = nullptr
    this ->head = nullptr;
    this -> size = 0;
}


LinkedList::LinkedList(int data){
    this-> size = 0;
    push_back(data);

}


LinkedList::LinkedList(std::vector<int> vec){
    this-> head = new Node(vec[0]);
    for(int i = 0; i < vec.size(); i++){
        this -> push_back(vec[i]);
    }
    size = vec.size();

}

LinkedList::~LinkedList(){
    while(this->head != nullptr){
        Node* temp = head;
        head = head -> next;
        delete temp ;
    }
}


void LinkedList::push_front(int data){
    if(size ==0){
        head = new Node(data);
    }
    else{
        Node* temp = new Node(data);
        temp-> next = head; 
        head = temp; 
    }
    size++;
}

void LinkedList::push_back(int data){
    if(size ==0){
        head = new Node(data);
    }
    else{
        Node* temp = head;
        while( temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new Node(data);
    }
    size++; 
}

void LinkedList::insert(int data, int idx){
    if(size == 0 || idx >= size){
        push_back(data);
        return;
    }
    else if(idx == 0){
        push_front(data);
        return;
    }
    else{
        Node* temp = head;
        for(int i =0; i < idx-1; i ++){
            temp = temp-> next;
        }
        Node* node = new Node(data, temp->next);
        temp->next = node;
    }
    size++;
}

void LinkedList::remove(int data){
    Node* temp = this->head;
    Node* prev_temp = nullptr;

    while(temp != nullptr){
        if(temp->data == data){
            if(prev_temp == nullptr){
                this->head = temp->next;
            }
            else{
                prev_temp->next = temp->next;
            }
            this->size -=1;
            return;   
    }
        else{
            prev_temp = temp;
            temp = temp->next;
            }
    
    }
}



bool LinkedList::contains(int data){
    Node* temp = this -> head; 
    while(temp != nullptr){
        if(temp->data == data){
            return true;
        }
        temp = temp-> next; 

    }
    return false;
}


int LinkedList::get_size(){
    return this->size;
}

// O(n)
std::string LinkedList::to_string(){
    //std::cout <<"here4"<<std::endl;
    std::string stringified;
    //std::cout <<"here5"<<std::endl;
    Node* tmp = this->head;
    //std::cout <<"here6"<<std::endl;
    while(tmp != nullptr){
        //std::cout <<"here7"<<std::endl;
        stringified += std::to_string(tmp->data) + " ";
        //std::cout <<"here8"<<std::endl;
        tmp = tmp->next;
       // std::cout <<"here9"<<std::endl;
    }
    //here is where the problem is 
    //std::cout <<"here10"<<std::endl;
    return stringified;
}
