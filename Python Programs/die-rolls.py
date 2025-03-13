# Midterm - Practice Problem - Die Rolls

import random

# Function to roll a random number on a die
def roll():
    num = random.randint(1,6)
    return num

# Function to keep track of the number of times each number appears on the die
def countRolls(numTrials):
    countList = [0,0,0,0,0,0]
    for i in range(numTrials):
        trial = roll()
        countList[trial-1] += 1
    return countList

# Function to print the results
def printRolls(rollsList):
    print("Value   Number of Rolls")
    print("-------------------------")
    for i in range(len(rollsList)):
        print(i+1, "     ",rollsList[i])
    return
        
# Main Function
def main():
    numTrials = int(input("Enter number of trials: "))
    rollsList = countRolls(numTrials)
    printRolls(rollsList)

    
