#pragma once
#include "node.h"
#include <vector>
#include <string>

class Queue{
    private:
    Node *head;
    Node *tail;
    unsigned int size;



    public:
    Queue();
    Queue(int data);
    Queue(std::vector<int> vec);
    ~Queue();

    void enqueue(int data);
    void dequeue();
    int peek();
    int get_size();
    std::string to_string();


};
