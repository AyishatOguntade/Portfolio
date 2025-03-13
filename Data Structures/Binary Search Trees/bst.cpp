#include "bst.h"
// BSTNode class implimentation 

//costructor
BSTNode::BSTNode(int d){
    this->data = d;
    this->left = nullptr;
    this->right = nullptr;
}
//deconstructor
BSTNode::~BSTNode(){
}

// Binary tree class implimentation

BSTree::BSTree(){
    this->root = nullptr;

}
//am i missing in destroy
void BSTree::destroyH(BSTNode *p){
    if(p == nullptr){
        return;
    }
    destroyH(p->left);
    destroyH(p->right);
    delete p;

}
void BSTree::destroy(){
    this->destroyH(this->root);
    this->root = nullptr;
}
BSTree::~BSTree(){
    // call destroy from here
    destroy(); 

}
//
BSTNode* BSTree::insertH(BSTNode * temp, int data){
    if(temp == nullptr){
        temp = new BSTNode(data);
    }
    else if(data <= temp->data){
        temp->left = insertH(temp->left,data);
    }
    else{
        temp->right = insertH(temp->right,data);
    }
    return temp;

}
void BSTree::insert(int data){
    this->root = insertH(this->root, data);
}
//
//note: height on an empty tree should return -1
//a tree with one node is height of 0 
int BSTree::heightH(BSTNode* temp){
    if(temp == nullptr){
        return -1;
    }
    else if(temp->right == nullptr && temp->left == nullptr){
        return 0;
    }
    int left = heightH(temp->left);
    int right = heightH(temp->right);
    int maxVal = std::max(left,right);
    return maxVal+1;
}
int BSTree::height(){
    return heightH(this->root);
}
//
// note dont forget to adjust the node connection before you delete them node
BSTNode* BSTree::removeH(BSTNode* temp, int data) {
    if (temp == nullptr) {
        return nullptr;// not found 
    }

    if (data < temp->data) {
        temp->left = removeH(temp->left, data);// left side
    } else if (data > temp->data) {
        temp->right = removeH(temp->right, data);// right side 
    } else {//found 
        //zero kids or one found 
        if (temp->left == nullptr) { 
            BSTNode* rightChild = temp->right;
            delete temp;
            return rightChild;
        } else if (temp->right == nullptr) {
            BSTNode* leftChild = temp->left;
            delete temp;
            return leftChild;
        } else {
            // has 2 kids 
            BSTNode* successor = temp->right;
            while (successor->left) {
                successor = successor->left;
            }
            temp->data = successor->data; //replace
            temp->right = removeH(temp->right, successor->data); //delete 
        }
    }
    return temp;
}

void BSTree::remove(int data){
    this->root = removeH(this->root, data);
}
//


bool BSTree::searchH(BSTNode* temp,int data){
    if(temp == nullptr){
        return false;
    }
    if(temp->data == data){
        return true;
    }

    if(temp->data > data){
        return searchH(temp->left, data);
    }
    else{
        return searchH(temp->right,data);
    }

}

bool BSTree::search(int data){
    return this->searchH(this->root, data);
}

//
void BSTree::preorderH(BSTNode* temp, std::ostream& os){
    if(temp == nullptr){
        return;
    }
    os<< temp->data << " ";
    preorderH(temp->left,os);
    preorderH(temp->right,os);
}
void BSTree::preorder(std::ostream& os){
    preorderH(this->root,os);
    os<< std::endl;
}
//
void BSTree::postorderH(BSTNode* temp, std::ostream& os){
    if(temp == nullptr){
        return;
    }
    else{
        postorderH(temp->left,os);//do i need to include the other parameter 
        postorderH(temp->right,os);
        os << temp->data <<" ";// do i need and endl
    }
}
void BSTree::postorder(std::ostream& os){
    postorderH(this->root,os);
    os<< std::endl;
}
//
void BSTree::inorderH(BSTNode* temp, std::ostream& os){
    if(temp == nullptr){
        return;
    }
    inorderH(temp->left,os);
    os<< temp->data << " ";
    inorderH(temp->right,os);

}
void BSTree::inorder(std::ostream& os){
    inorderH(this->root,os);
    os<< std::endl;
}

