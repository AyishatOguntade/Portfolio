#include <iostream>
#include <vector>
#include <algorithm>
//d
// this is the sodoku problem
// you are given a gride and then have to figure out if
// it follow the rules of sodoku
// output solution is good! if the follow the rules 
// output solution is bad if it dose not 

// ideas 
// create a 9 by 9 array or vecotor 
// figure out a way to store the input into this vector 
// then find a way to impliment these rules 
// prob gonna use a function to seach each line by line 
// to see if this is the same number in each row
// find an if statement that checks to see if the rule follows 
    // Each column should contain the values 1-9
    //Each row should contain values 1-9
    //Each box should contain the values 1-9
    //Each value should appear exactly once in each of the above

// impliment function for each rule 
// check collums rows and squares(checking the 3 by 3 boxes) 

bool isgood(std:: vector <int> arr){
    int num [9] = {1,2,3,4,5,6,7,8,9};
    std:: sort(arr.begin(), arr.end());
    for(int i=0; i<9; i++){
        if(arr[i] != num[i]){
            return false;
        }
    }
    return true;

}
bool check_collums(int arr[][9]){ // change to vec
    // store the values of the array in the temp 
    // then compare , then clear it then go to the next collum 
    // then continue
    for(int r=0; r < 9; r++){
        std:: vector <int> check2;
        for(int c =0; c < 9; c++){
            check2.push_back(arr[c][r]);
        }
        if(!isgood(check2)){
            return false;
        }
    }return true;
}
bool check_rows(int arr[][9]){
    for(int r=0; r < 9; r++){
        std:: vector <int> check;
        for(int c =0; c < 9; c++){
            check.push_back(arr[r][c]);
        }
        if(!isgood(check)){
            return false;
        }
    }return true;
    
}
bool check_square(int arr[][9]){
    for(int i=0; i<9; i+=3){
        for (int j=0; j<9; j+=3){
            std:: vector <int> check3;
            for(int r =0; r< 3; r++){
                for(int c =0; c<3; c++){
                    check3.push_back(arr[i+r][j+c]);
                }
            }
            if(!isgood(check3)){
                return false;
            }
        }
    }return true;
}

int main(){
    // read in the board 
    int arr [9][9] ;
  
    for(int i =0; i < 9; i++){
        for(int j=0 ; j < 9; j++){
            std:: cin >> arr[i][j];
        }
    } 
    //std:: cout << check_rows(arr) << check_collums(arr) << check_square(arr);
    if(check_rows(arr)&& check_collums(arr)&& check_square(arr)){
        std:: cout << "Solution is good!"<< std:: endl;
    }
    else{
        std:: cout << "Wrong solution!"<< std:: endl;
    }

    //print what each funcion is saying 
    // figure out what one is printing false 
    // check aquare is this problem maybe 

    return 0;
}