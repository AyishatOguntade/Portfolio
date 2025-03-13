#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
// find the assignment that you calculated the euclidian distance 
// using 2D Cartesian points and Euclidean distance measurement to calculate closeness.

// how should I go about storing the input 
// also need clarification on what its asking me to do 
struct Point{
    double x;
    double y;
    char color;
    double dist; 
};
void sortPointsByDistance(std::vector<Point>& points) {
    int n = points.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (points[j].dist > points[j + 1].dist) {
                std::swap(points[j], points[j + 1]);
            }
        }
    }
}

int main(){
    // ask for clarification on what its even asking me to do 
    // get information and store it 
    std:: string line;
    std:: getline(std::cin,line);
    std:: istringstream inputStream(line);
    int n;
    int k;
    std:: vector <Point> arr;
    inputStream >>n>>k;
    for(int i=0; i<n; i++){
        Point newPoint;
        std:: cin >> newPoint.x >> newPoint.y >> newPoint.color;
        arr.push_back(newPoint);
    }

    double x; 
    double y;
    std:: cin >> x >> y;
    
    for(int v=0; v < n; v++){
        arr[v].dist = sqrt( pow((arr[v].x - x),2) + pow((arr[v].y - y),2));
    }
    // work on getting the smalest dis.
    sortPointsByDistance(arr);
    int Rcount =0;
    int Bcount =0;
    // test this
    for(int b =0; b<k; b++){
        if(arr[b].color == 'R'){
            Rcount ++;
        }
        if(arr[b].color == 'B'){
            Bcount ++;
        }
    }
    if( Rcount > Bcount){
        std:: cout << "R" << std:: endl; 
    }
    else{
        std:: cout << "B" << std:: endl;
    }
    

    return 0;
}