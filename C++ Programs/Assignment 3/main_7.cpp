#include<iostream> 
#include <vector>
#include <utility>
#include<cmath>
// confused about tthe input and how to calculate the diameter 
//what would be the output?
// might work 
// d
int main(){
    int x;
    int y;

    //std:: pair <int , int> quards = {x,y};
    std:: vector < std:: pair <int,int>> quards;

    while(std::cin >> x >> y){
        std:: pair <int , int> pair (x,y);
        quards.push_back(pair);
        //int i = 0;
        //int diameter =0;
        //diameter = pow((quards[i+1].first - quards[i].first),2) +(pow((quards[i+1].second - quards[i].second),2));
        //std:: cout << "diameter# = "<< diameter;
    }
    int diameter = 0;
    std:: vector <int> values;
    for(int i = 0; i < quards.size()-1; i ++){
        for(int j=i+1; j<quards.size(); j++){
            diameter = sqrt(pow((quards[j].first - quards[i].first),2) +(pow((quards[j].second - quards[i].second),2)));
            values.push_back(diameter);
        }
        //diameter = pow((quards[i+1].first - quards[i].first),2) +(pow((quards[i+1].second - quards[i].second),2));
    
    }
    int highest=0;
    for(int x : values){
        if( x > highest){
            highest = x;
        }
    }
    std:: cout << highest;

    return 0;

}