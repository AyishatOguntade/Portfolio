#include <iostream>

//NEW NODE

class BSTNode {
    private:
        int data;
        BSTNode *left;
        BSTNode *right;
    public:
        BSTNode(int d);
        ~BSTNode();
    friend class BSTree;
};


//NEW TREE

class BSTree{
    private:
        BSTNode *root;

        void destroyH(BSTNode *p);
        void preorderH(BSTNode* temp, std::ostream& os);//may change
        void postorderH(BSTNode* temp, std::ostream& os);
        void inorderH(BSTNode* temp, std::ostream& os);
        BSTNode* removeH(BSTNode * temp, int data);
        int heightH(BSTNode * temp);
        BSTNode* insertH(BSTNode * temp, int data);
        bool searchH(BSTNode* temp,int data);
    public:
        BSTree();
        ~BSTree();
        
        void insert(int data);
        void remove(int data);
        bool search(int data);
        void destroy();
        int height();
        void preorder(std::ostream& os = std::cout);
        void postorder(std::ostream& os = std::cout);
        void inorder(std::ostream& os = std::cout);
        //BSTNode *search(int d);
};




