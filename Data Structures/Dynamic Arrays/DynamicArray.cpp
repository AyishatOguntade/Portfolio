#include "DynamicArray.h"
#include <cstring>

// "Fancy" way to write a default constructor.
// Note: The other constructors can *NOT* be written this way!
DynamicArray::DynamicArray()
    : m_length(0), m_capacity(1), m_scaling_factor(2.0), m_data(new int[1]) {
}

DynamicArray::DynamicArray(double scaling_factor, unsigned int capacity) {
    //..............
    // TODO
    this-> m_scaling_factor = scaling_factor;
    this-> m_capacity = capacity; 
    this-> m_length =0;
    this-> m_data = new int [capacity]; 
    //..............
}


DynamicArray::DynamicArray(double scaling_factor, unsigned int length, int default_value) {
    //..............
    // TODO
    this-> m_scaling_factor = scaling_factor;
    this-> m_length = length;
    this->m_capacity = length;
    int default_value_t = default_value;// why do we need this 
    this-> m_data = new int[this->m_capacity];
    for(unsigned int i=0; i <m_capacity; i ++){
        m_data[i]= default_value_t;
    }
    //..............
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    // use the assignment operator
    (*this) = other; 
}

// Destructor: destroys the dynamically allocated array on the heap
DynamicArray::~DynamicArray() {
    delete[] m_data;
}

unsigned int DynamicArray::get_length() {
    return m_length;
}

unsigned int DynamicArray::get_capacity() {
    return m_capacity;
}

double DynamicArray::get_scaling_factor() {
    return m_scaling_factor;
}

void DynamicArray::set_scaling_factor(double value) {
    m_scaling_factor = value;
}
//should I pass through a refrence vector as a parameter (the one filled with al the numbers) 
std::string DynamicArray::to_string() {
	// Initialize an empty string
    std::string str("");
	
	//..............
    // TODO
    for(unsigned i=0; i < m_length; i++){
        std:: string str_temp = std::to_string(m_data[i]);
        str += str_temp;
        str += " ";
    }
    //..............

    return str;
}

bool DynamicArray::find_first_of(int value, unsigned int *index) {
    bool found = false;
    //..............
    // TODO
    for(unsigned int i =0; i < m_length;  i++){
        if(m_data[i] == value){
            *index = i; 
            return 1;
        }
    }
    //..............
    return 0;

}

bool DynamicArray::find_last_of(int value, unsigned int *index) {
    bool found = false;
    //..............
    // TODO
    for(unsigned int i = m_length -1; i >=0; i-- ){
        if(m_data[i] == value){
            *index =i;
            return 1;
        }
    }
    //..............
    return 0;
}

void DynamicArray::append(int value) {
    //..............
    // TODO
    if(m_capacity == m_length){
        int new_capacity = static_cast<int>(m_capacity * m_scaling_factor);
        int *new_data = new int [new_capacity];
        //copy the old things to the new array 
        std::memcpy(new_data, m_data, sizeof(int) * m_length);
        delete[]m_data;
        // inialized 
        m_data = new_data;
        m_capacity = new_capacity;
    }
    m_data[m_length ++] = value;
    

    //..............
}

void DynamicArray::prepend(int value) {
    //..............
    // TODO
    if(m_length == m_capacity){
        int new_capacity= static_cast<int> (m_capacity* m_scaling_factor);
        int *new_data = new int[new_capacity];
        std::memcpy (new_data +1, m_data, sizeof(int) * m_length);
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
    else{
        for(unsigned int i= m_length; i >0; --i){
            m_data[i] = m_data[i-1];
        }
    }
    m_data[0] = value;
    m_length ++;  
    //..............
}

void DynamicArray::remove_last() {
    //..............
    // TODO
    if(m_length >0){
        m_length --; 
        if(m_length < m_capacity/ m_scaling_factor){
            int new_capacity = static_cast<int> (m_capacity/m_scaling_factor);
            if(new_capacity < 1){
                new_capacity = 1;
            }
            int *new_data = new int[new_capacity];
            std::memcpy(new_data,m_data, sizeof(int) * m_length);
            delete[]m_data;
            m_data = new_data;
            m_capacity = new_capacity; 
        }

    }
    //..............
}

void DynamicArray::remove_first() {
    //..............
    // TODO
    if(m_length > 0){
        for(unsigned int i =0; i < m_length -1; i++){
            m_data[i] =m_data[i+1];
        }
        m_length --;
        if( m_length < m_capacity/m_scaling_factor){
            int new_capacity = static_cast<int>(m_capacity/m_scaling_factor);
            if(new_capacity < 0){
                new_capacity =1;
            }
            int *new_data = new int [new_capacity];
            std::memcpy(new_data, m_data, sizeof(int) * m_length);
            delete[] m_data;
            m_data = new_data;
            m_capacity= new_capacity;
        }
    }
    //..............
}

void DynamicArray::clear() {
    //..............
    // TODO
    delete[] m_data;
    m_data= nullptr; 
    m_capacity =0;
    m_length =0;
    //..............
}

// Examples of "operator overloading"
int& DynamicArray::operator[](unsigned int index) {
    return m_data[index];
}

DynamicArray& DynamicArray::operator=(const DynamicArray &other) {
    m_length = other.m_length;
    m_capacity = other.m_capacity;
    m_scaling_factor = other.m_scaling_factor;
    m_data = new int[m_capacity];
    std::memcpy(m_data, other.m_data, sizeof(int) * m_length);
    // this allows statements such as (a = b = c) assuming a, b, and c are all the DynamicArray type
    return (*this); 
}
