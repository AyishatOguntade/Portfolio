#Ayishat Oguntade
#CSC 110 - Homework 4 - Working with Python Functions
#Due October 9 11:55

#Bring in 4_2 hw
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

#Define new function

def allSumKDigits(num):
    num_str = str(num)

    sums = []

    for k in range(1,len(num_str)+1):
        p_sum = sumKDigits(num,k)
        sums.append(p_sum)

    return sums
        





#Perosnal Notes
#The loop starts with k equal to 1, which means first calculate the sum of the first digit.
#adding 1, checks that the loop includes the last possible 
