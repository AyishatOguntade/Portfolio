#pragma once
#include <vector>
#include <string>
#include<iostream>
#include "priority_node.h"
//#include <pair>

class PriorityQ{
    private:
        PNode* head;
        int size;


    public:

        PriorityQ();
        PriorityQ(int element, int priority);
        //pair for keepint track of data and 
        PriorityQ(std::vector<int> vec);
        ~PriorityQ();

        void enqueue(int element, int priority);
        void dequeue();
        void peek();
        std::string to_string();


};
