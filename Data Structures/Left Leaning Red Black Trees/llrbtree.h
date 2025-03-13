
/*
create a node class
    ptr to the left 
    ptr to the right 
    bool for color 
    Note: what number will reperenset the black or red 
    base constuctor 
    constructor with a parameter 

create a LLRBT tree class
    a node that points to the root 
    constuctor to set the root to null 
    insert function 
    clear function 
    pre/post/inorder functions that output color 
    flip color function 
    height 


*/
#include <iostream>
#include <ostream>

// Defines MAX
// When used, MAX(a,b) will be replaced with ((a > b) ? a : b)
#ifndef MAX
#define MAX(a,b) ((a > b) ? a : b)
#endif



class RBTNode {
private:
    int data;
    RBTNode* left;
    RBTNode* right;
    bool red;

    void flipColors(){ 
        red = !red; 
        left->red = !left->red;
        right->red = !right->red;
    }

public:
    RBTNode();
    RBTNode(int data);
    ~RBTNode();

    friend class RBTree;
};

class RBTree {
private:
    RBTNode* root;

    void preorder(RBTNode* root, std::ostream& os);
    void inorder(RBTNode* root, std::ostream& os);
    void postorder(RBTNode* root, std::ostream& os);
    RBTNode* rotateLeft(RBTNode* root);
    RBTNode* rotateRight(RBTNode* root);
    void destroy(RBTNode* root);
    bool search(int data, RBTNode* root);
    bool isred(RBTNode* root);
    int height(RBTNode* root);
    RBTNode* insert(int data, RBTNode* root);

    // new remove functions 
    RBTNode* moveRedLeft(RBTNode* h);
    RBTNode* moveRedRight(RBTNode* h);
    RBTNode* fixUp(RBTNode* h);
    RBTNode* deleteMin(RBTNode* h);
    RBTNode* deleteNode(RBTNode* h, int data);

public:
    RBTree();
    ~RBTree();
    void insert(int data);
    void clear();
    bool search(int data);
    int height();
    void remove(int data);
    void deleteMin();
    void preorder(std::ostream& os = std::cout);
    void inorder(std::ostream& os = std::cout);
    void postorder(std::ostream& os = std::cout);
};





