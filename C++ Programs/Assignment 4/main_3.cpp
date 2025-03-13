#include <iostream>
#include <vector>

//how to store the numbers 
// how do the letters correleate with the given numbers 
// do you stop moving after the letters run out


int main(){
    // stores the start board
    int arr [3][3];
    // find zero 
    int zrow =0;
    int zcol =0;
    for(int i =0; i < 3; i++){
        for(int j=0; j< 3; j++){
            std:: cin >> arr[i][j];
            if(arr[i][j] == 0){
                //std:: cout << arr[i][j] << std:: endl;
                zrow =i;
                zcol =j;
            }
        }
    }
    // get and store the movies from the user 
    // figure out how to sttore the flimsy moves better 
    std:: vector <char> moves;
    char temp;
    while(std:: cin >> temp){
        moves.push_back(temp);
    }
   
    // loop through moves and apply them if i can 
 
    for(int x =0; x<moves.size(); x++){
        if(moves[x] == 'R' && zcol!= 2){
            std:: swap(arr[zrow][zcol+1], arr[zrow][zcol]);
            zcol+=1;
            //std:: cout << arr[zrow][zcol] <<std::endl;
        }
        if( moves[x] == 'L' && zcol!=0){
            std:: swap(arr[zrow][zcol-1], arr[zrow][zcol]);
            zcol-=1;
            //std:: cout << arr[zrow][zcol] <<std::endl;
        }
        if(moves[x] == 'U' && zrow != 0){
            std:: swap(arr[zrow-1][zcol], arr[zrow][zcol]);
            zrow-=1;
            //std:: cout << arr[zrow][zcol] <<std::endl;
        }
        if( moves[x] == 'D' && zrow!=2){
            std:: swap(arr[zrow +1][zcol], arr[zrow][zcol]);
            zrow+=1;
            //std:: cout << arr[zrow][zcol] <<std::endl;
        }

    }
    // create correct order 
    int carr[3][3] ={{1,2,3}
                    ,{4,5,6} 
                    ,{7,8,0}};

   
    int count =0;
    for (int z = 0; z < 3; z++) {
        for (int y = 0; y < 3; y++) {
            //std:: cout << arr[z][y];
            if(arr[z][y] == carr[z][y]){
                count ++;
            }

        }
        //std:: cout << std:: endl;
    }



    if(count == 9){
        std:: cout << "Solution is good!" << std:: endl;
    }
    else{
        std:: cout << "Wrong solution!" << std:: endl;
    }

    return 0;
}