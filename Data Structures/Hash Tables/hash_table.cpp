#include "hash_table.h"
#include <vector>
#include <cmath>
#include <iostream>

// Helper function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= std::sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Constructor with default table size and mode
HashTable::HashTable(int m) {
    this->numElement = 0;
    this->mode = m;
    this->collisions = 0;

    if (m == 0 || m == 1) {
        this->table = std::vector<std::vector<int>>(1, std::vector<int>(1, 0));
    } else {
        this->table = std::vector<std::vector<int>>(1, std::vector<int>());
    }
}

// Constructor with specified table size and mode
HashTable::HashTable(int m, int n) {
    this->numElement = 0;
    this->mode = m;
    this->collisions = 0;

    if (m == 0 || m == 1) {
        this->table = std::vector<std::vector<int>>(n, std::vector<int>(1, 0));
    } else {
        this->table = std::vector<std::vector<int>>(n, std::vector<int>());
    }
}

// Function to find the largest prime less than or equal to a number
int HashTable::tablePrime(int num) {
    if(num == 1 || num == 0 || num == 2){
        return 1;
    }
    if (!isPrime(num)) {
        for (int i = num - 1; i > 1; --i) {
            if (isPrime(i)) return i;
        }
    }
    return num;
}

// Resize the hash table
void HashTable::resize(bool grow) {
    // Save the old table
    std::vector<std::vector<int>> oldTable = this->table;

    // Grow the table size if needed
    if (grow) {
        if (this->mode == 0 || this->mode == 1) {
            this->table = std::vector<std::vector<int>>(oldTable.size() * 2, std::vector<int>(1, 0));
        } else {
            this->table = std::vector<std::vector<int>>(oldTable.size() * 2, std::vector<int>());
        }
    }

    // Reset counters
    this->numElement = 0;

    // Reinsert all elements into the new table
    for (int i = 0; i < oldTable.size(); ++i) {
        for (int j = 0; j < oldTable[i].size(); ++j) {
            if (oldTable[i][j] != 0) { // Skip empty slots
                insert(oldTable[i][j]);
            }
        }
    }
}

// Hash function for linear probing
int HashTable::h1(int data) {
    return data % this->table.size();
}

// Secondary hash function for double hashing
int HashTable::h2(int data) {
    int tempPrime = tablePrime(this->table.size());
    return (data*data) % tempPrime;
    // before i had 
}

// Combined hash function for double hashing
int HashTable::dbl_hash(int data) {
    return (h1(data) + (this->collisions + h2(data))) % this->table.size();
}

// Insert using linear probing
void HashTable::insertLinear(int data) {
    int colT = 0;
    int key = h1(data);

    while (this->table[key][0] != 0) { // Collision handling
        colT++;
        key = h1(key + 1);
    }

    this->collisions += colT;
    this->table[key][0] = data;
}

// Insert using double hashing
void HashTable::insertDouble(int data) {
    int colT = 0;
    //int key = 0;
    int key = (h1(data) + (colT + h2(data))) % this->table.size();

    while (this->table[key][0] != 0) { // Collision handling
        colT++;
        // should i call double hash here 
        key = (h1(data) + (colT + h2(data))) % this->table.size();
    }

    this->collisions += colT;
    this->table[key][0] = data;
}

// Insert using chaining
void HashTable::insertChain(int data) {
    int key = h1(data);
    if (!this->table[key].empty()) { // Collision occurs if the bucket isn't empty
        this->collisions++;
    }
    this->table[key].push_back(data); // Append the data to the chain
}

// Public insert function
void HashTable::insert(int num) {
    if ((double)this->numElement / this->table.size() >= 0.7) { // Resize if load factor exceeds 0.7
        this->resize(true);
    }

    if (this->mode == 0) {
        insertLinear(num);
    } else if (this->mode == 1) {
        insertDouble(num);
    } else if (this->mode == 2) {
        insertChain(num);
    }

    this->numElement++;
}

// Get the number of collisions
int HashTable::get_num_collisions() {
    return this->collisions;
}

// Print the hash table (supports chaining)
void HashTable::print_table() {
    for (size_t i = 0; i < this->table.size(); i++) {
        std::cout << i << ": ";
        for (int value : this->table[i]) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

