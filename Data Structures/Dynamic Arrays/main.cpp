#include <iostream> 
#include <fstream>
#include<sstream>
#include<vector>
#include<string> 
#include "DynamicArray.h"
// the command line will control the program

int main(int argc, char*argv[]){
    //argc is going to be the amount of arguments 
    //argc running ./hello is 1 then after that is 2 ect
    //std::string fname;
    float scaling_factor;
    int capacity;
    int length;
    int default_value;
    std::vector<int>file_numbers; 

    //read in file 
    // there will be at least 1 argument 
    std::string fname(argv[1]);
	std::ifstream inputFile(fname);

    int number;
    while(inputFile >> number){
        file_numbers.push_back(number);
    }
    DynamicArray *array1;
    //choosing the correct constuctor 
    if(argc == 2 ){
        array1 = new DynamicArray ;
    }   
    //fix the other declarations to the one above 
    else if(argc == 4){
        scaling_factor = std::stof(argv[2]);
        capacity = std::stoi(argv[3]);
        array1 = new DynamicArray(scaling_factor, capacity);
        //std::cout << scaling_factor<<std::endl;
        //std::cout << capacity <<std::endl;
    }
    else if(argc == 5){
        scaling_factor = std::stof(argv[2]);
        length = std::stoi(argv[3]);
        default_value = std::stoi(argv[4]);
        array1 = new DynamicArray(scaling_factor,length,default_value);
        //test to see if it works
        //std::cout << scaling_factor<<std::endl;
        //std::cout << length <<std::endl;
        //std::cout <<default_value<<std::endl;
    }

    // read in list of numbers 
    //test to see if  the above code is working 
    
    //for (int num : file_numbers) {
    //    std::cout << num << " ";
    //}
    /*
    std::cout << std::endl;
    std::cout<< capacity <<std::endl;
    std::cout << scaling_factor<< std::endl;
    */
    // start the coding 
    int half_size = file_numbers.size() / 2;
    int third_size = file_numbers.size() / 3;
    //is this how you handle odd numbers 
    //int half_size = (file_numbers.size() + 1) / 2; 
    //int third_size = (file_numbers.size() + 2) / 3;  
    unsigned int first_of_idx;
    unsigned int last_of_idx;

    // append
    for(unsigned int i=0; i < half_size; i++){
        array1 ->append(file_numbers[i]);
    }
    std::cout << array1 ->to_string() <<std::endl;
    // prepend
    for(unsigned int j = half_size; j <file_numbers.size(); j++){
        array1 -> prepend(file_numbers[j]);
    }
    std::cout << array1 -> to_string()<<std::endl;
    // work on these last two function 
    //find_first_of 
    
    bool value = array1->find_first_of(file_numbers[third_size], &first_of_idx);
    std::cout << value << "\t" << first_of_idx << std::endl;  
    //std::cout << array1->to_string() << std::endl;

// find_last_of
    bool value1;
    value1 = array1->find_last_of(file_numbers[third_size], &last_of_idx);
    std::cout << value1 << "\t" << last_of_idx << std::endl;
    // std::cout << array1 -> to_string()<<std::endl;

    // remove_last
    array1 -> remove_last();
    std::cout << array1 -> to_string()<<std::endl;
    // remove first
    array1 -> remove_first();
    std::cout << array1 -> to_string()<<std::endl;
    //clear 
    array1 -> clear();
    std::cout << array1 -> to_string()<<std::endl;


    //std:: cout << array1 ->to_string() <<"here";



    return 0;
}
