#Ayishat Oguntade
#CSC 110 - Homework 4 - Working with Python Functions
#Due October 9 11:55

#Define the function

def sumKDigits (number,k):
    
#convert the number into a string
    
    number_str = str(number)

#If k is greater than the number of digits in the integer, the function should return 0.

    if k > len(number_str):
        return 0
    
#Define the total
    
    t = 0

    for i in range(k):
        digit = int(number_str[i])
        t = t + digit

    return t 
