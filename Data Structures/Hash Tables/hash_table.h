// for chaning use mutipe vectors to represent a the index in the orginal vector
#include <iostream> 

#include <vector>


class HashTable{

    private:
    int key;
    int data;
    int mode;//used to figure out what type of strategy to use
    //std::vector<int> values;
    int numElement;
    std::vector<std::vector <int>> table;
    int size;
    int collisions;//global 

    void insertLinear(int data);
    void insertDouble(int data);
    void insertChain(int data);

    void printTableChain();


    public:
    //constuctors
    HashTable(int m);
    HashTable(int m, int n);

    //for double hashing
    int tablePrime(int num);
    //int tableSize();

    //resolution stratagies 
    void linearProbing();
    void doubleHashing();
    void chaining();
    void resize(bool grow);

    int h1(int data);//linear and used to get doublehashing
    int h2(int data);//used to get double hashing
    int dbl_hash(int data);// call h1 and h2, local collision needed
    //int hashChain(int data); not needed
    
    int access(int data);
    //call vec
    void insert(int num);
    


    int accessLinear();//search
    int accessDouble();//search
    int accessChain();//search

    int get_num_collisions();
    void print_table();
};



