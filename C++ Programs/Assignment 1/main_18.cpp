#include <iostream>
#include <iomanip>

int main(){

int day ;
int month;
int year;

std:: cin >> day;
std:: cin>> month;
std:: cin >> year;

if (month == 1 || month == 2){
    month = month + 12;
    year = year -1;
}

int century;
century = year/100;
int yearApart;
yearApart = year % 100;


int weekdayNum;

weekdayNum = (day +(((month +1)*26)/10) + yearApart + (yearApart/4) +(century/4) + 5 *century ) %7;



if (weekdayNum ==0){
    std:: cout <<"Saturday";
}
else if(weekdayNum == 1){
    std:: cout << "Sunday";
}
else if(weekdayNum == 2){
    std:: cout<< "Monday";
}
else if(weekdayNum ==3){
    std:: cout << "Tuesday";
}
else if(weekdayNum == 4){
    std::cout << "Wednesday";
}
else if(weekdayNum == 5){
    std:: cout << "Thursday";
}
else if(weekdayNum == 6){
    std:: cout << "Friday";
}  
else{
    std:: cout<<"";
}
    
    return 0;
}