#include "queue.h"
#include <iostream>

//base constuctor 
Queue::Queue() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

// constuctor with one element 
Queue::Queue(int data) {
    Node* nn = new Node(data);
    this->head = nn;
    this->tail = nn;
    this->size = 1;
}
// constuctor with a vector 
Queue::Queue(std::vector<int> vec) {
    if (vec.size() == 0) {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    } else {
        Node* nn = new Node(vec[0]);
        this->head = nn;
        Node* temp = this->head;

        for (int i = 1; i < vec.size(); i++) {
            temp-> next = new Node(vec[i]); // Use setter to set next
            temp = temp->next; // Use getter to get next
        }
        //update the tail with the last node
        this->tail = temp;
        this->size = vec.size();
        } 
}
// deconstuctor 
Queue::~Queue() {
    delete this->head;
    this->head = nullptr;
}

void Queue::enqueue(int data) {
    Node* nn = new Node(data);
    if (this->head == nullptr) {
        this->head = nn;
        this->tail = nn;
        this->size++;
        return;
    } else {
        this->tail->next = nn; // Use setter to set next
        this->tail = nn; // Use getter to get next
        this->size++;
    }
   
}


void Queue::dequeue() {
    if (this->head == nullptr) {
        return; // Nothing to dequeue
    } else if (this->size == 1) {
        delete this->head; 
        this->head = nullptr;
        this->tail = nullptr;
    } else {
        Node* temp = this->head;
        this->head = this->head->getNext(); 
        temp->setNext(nullptr);
        delete temp; 
    }
    this->size--;
}

int Queue::peek() {
    if (this->head == nullptr) {
        return -100; // Specification for this lab is [-99, 99]
    } else {
        return this->head->getData(); // Use getter to access data
    }
}


int Queue::get_size() {
    return this->size;
}


std::string Queue::to_string() {
    std::string stringified;
    Node* tmp = this->head;

    while (tmp != nullptr) {
        stringified += std::to_string(tmp->getData()) + " "; 
        tmp = tmp->getNext(); 
    }

    return stringified;
}
