#include "llrbt.h"

// node class
RBTNode::RBTNode(){
    this->data = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->red = true;
}

RBTNode::RBTNode(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->red = true;

}

RBTNode::~RBTNode(){

}
// remove functions 

// Move red left
RBTNode* RBTree::moveRedLeft(RBTNode* h) {
    h->flipColors();
    if (isred(h->right->left)) {
        h->right = rotateRight(h->right);
        h = rotateLeft(h);
        h->flipColors();
    }
    return h;
}

// Move red right
RBTNode* RBTree::moveRedRight(RBTNode* h) {
    h->flipColors();
    if (isred(h->left->left)) {
        h = rotateRight(h);
        h->flipColors();
    }
    return h;
}

// Fix up the tree to maintain LLRB properties
RBTNode* RBTree::fixUp(RBTNode* h) {
    if (isred(h->right)){
        h = rotateLeft(h);
    }
    if (isred(h->left) && isred(h->left->left)){
        h = rotateRight(h);
    } 
    if (isred(h->left) && isred(h->right)) {
        h->flipColors();
    }
    return h;
}
//public delete min 
void RBTree::deleteMin(){
    this->root = deleteMin(this->root);
    this->root->red = 0;
}

// Delete minimum node private
RBTNode* RBTree::deleteMin(RBTNode* h) {
    if (h->left == nullptr){
        return nullptr;
    }
    if (!isred(h->left) && !isred(h->left->left)){
         h = moveRedLeft(h);
    }
    h->left = deleteMin(h->left);
    return fixUp(h);
}


//delete private
RBTNode* RBTree::deleteNode(RBTNode* h, int data) {
    if (!h){
        return nullptr; // Base case node not found
    } 
    //left subtree if data is smaller than the current node's value
    if (data < h->data) { 
        // check the left child is red or has a red child rule 1
        if (h->left && !isred(h->left) && !isred(h->left->left)) {
            h = moveRedLeft(h);// Adjust tree structure to prepare for deletion
        }
        //Recursively delete the node from the left subtree
        h->left = deleteNode(h->left, data);
    } else {
        // If the left child is red, perform a right rotation for balance
        if (isred(h->left)) {
            h = rotateRight(h);
        }
        //If the current node matches data and has no right child, delete it
        if (data == h->data && h->right == nullptr) {
            //node found and no right child
            delete h;
            return nullptr; //Return null to replace the node in the parent
        }
        //Ensure the right child is red or has a red child rule 2 
        if (h->right && !isred(h->right) && !isred(h->right->left)) {
            h = moveRedRight(h); // Adjust tree structure to prepare for deletion
        }
        if (data == h->data) {
            // Find the minimum in the right subtree to replace this node
            RBTNode* minNode = h->right;
            while (minNode->left) {
                minNode = minNode->left;
            }
            h->data = minNode->data;  // Copy the minimum node's value to the current node
            h->right = deleteMin(h->right); // Remove the minimum node
        } else {
            // Recursively delete the node from the right subtree
            h->right = deleteNode(h->right, data);
        }
    }
    // Fix any violations 
    return fixUp(h);
}


//public 
void RBTree::remove(int data) {
    if (this->root) {
        this->root = deleteNode(this->root, data);
        if (this->root) {
            this->root->red = false; // Ensure the root is black
        }
    }
}





// tree class 
// private functions

RBTree::RBTree(){
    this->root = nullptr;
}

RBTNode* RBTree::insert(int data, RBTNode* root){
    if(!root){
        return new RBTNode(data);
    }

    // Go left if data < data at this Node
    if(data < root->data){
        root->left = insert(data, root->left);
    // Go right otherwise
    }else{
        root->right = insert(data, root->right);
    }
    // if the right is red
    if(!isred(root->left)&& isred(root->right)){
        root = rotateLeft(root);
    }
    //two reds in a subtree child and grandchild 
    if(isred(root->left)&& isred(root->left->left)){
        root= rotateRight(root);
    }
    //they are both red
    if(isred(root->left) && isred(root->right)){
        root->flipColors();
        //root->left->flipColors();
        //root->right->flipColors();
    }
    return root;
}

int RBTree::height(RBTNode*root){
    if(!root){
        return -1;
    }
    int left = height(root->left);
    int right = height(root->right);
    return (left > right ? left+1 :right +1);
}

void RBTree::clear(){
    this->destroy(this->root);
    this->root = nullptr;
}

void RBTree::preorder(RBTNode* root, std::ostream& os){
    if(!root){
        return;
    }

    os << root->data << ":"<< root->red << " ";
    this->preorder(root->left, os);
    this->preorder(root->right, os);

    return;
}

void RBTree::inorder(RBTNode* root, std::ostream& os){
    if(!root){
        return;
    }

    this->inorder(root->left, os);
    os << root->data << ":" << root->red << " ";
    this->inorder(root->right, os);

    return;
}

void RBTree::postorder(RBTNode* root, std::ostream& os){
    if(!root){
        return;
    }

    this->postorder(root->left, os);
    this->postorder(root->right, os);
    os << root->data << ":" << root->red<< " ";

    return;
}

void RBTree::destroy(RBTNode* root){
    if(!root){
        return;
    }

    this->destroy(root->left);
    this->destroy(root->right);
    delete root->left;
    delete root->right;
}

bool RBTree::search(int data, RBTNode* root){
    if(!root){
        return false;
    }

    if(data == root->data){
        return true;
    }

    if(data < root->data){
        return this->search(data, root->left);
    }else{
        return this->search(data, root->right);
    }
}

bool RBTree::isred(RBTNode* root){
    if(!root){
        return false;
    }
    else{
        return root->red;
    }
}
// public functions 


RBTree::~RBTree(){
    clear();
}

void RBTree::insert(int data){
    this->root = this->insert(data, this->root);
    if(this->root){
        this->root->red =false; // ensure the new root is black
    }
}


int RBTree::height(){
    return this->height(this->root);
}

void RBTree::preorder(std::ostream& os){
    this->preorder(this->root, os);
    os << "\n";
}

void RBTree::inorder(std::ostream& os){
    this->inorder(this->root, os);
    os << "\n";
}

void RBTree::postorder(std::ostream& os){
    this->postorder(this->root, os);
    os << "\n";
}

bool RBTree::search(int data){
    return this->search(data, this->root);
}





RBTNode* RBTree::rotateLeft(RBTNode* root){
    RBTNode* p = root->right;
    root->right = root->right->left;
    p->red = root->red;
    p->left = root;
    root->red = true;
    return p;
}


RBTNode* RBTree::rotateRight(RBTNode* root){
    RBTNode* p = root->left;
    root->left = root->left->right;
    p->red = root->red;
    p->right = root;
    root->red = true;
    return p;
}

/*
void flipColors(){
    if(root->red){
        root->left = red
        root->red = false;
    }
    else{
        root->red = true;
    }
    //might not work
    // possibly change to void flipColors(){ red = !red}
}
*/










