# Midterm Fall 2023 - Practice Problem 3
 
# Given: A list of names, a list of phone numbers and a phone number to search for
 
# Function to read the names and phones into lists
def getLists():
    num = int(input("How many entries in your data? "))
    
    yearList = []
    categoryList = []
    winnerList = []

    for i in range(num):
        year = int(input("Enter year: "))
        category = input("Enter category: ")
        winner = input("Enter winner: ")
        yearList.append(year)
        catetoryList.append(category)
        winnerList.append(winner)
    return yearList, categoryList, winnerList
 


# Function to get all winners within a given year range
def findWinners(category, years, awards, winners):
    categoryWinners = []
    for i in range(len(winners)):
        if category in awards[i]:
            categoryWinners.append(winners[i])
    return categoryWinners

# Function to print the winners in the given range
def printWinners(winners):
    if len(winners) == 0:
        print("No winners in that category")
    else:
        print("WINNER")
        for i in range(len(winners)):
            print(winners[i])
    return
   
# Main Function
def main():
 
    # Get the lists
    
    years, awards, winners = getLists()
 
    # Get the category to search for
    category = input("Enter the award category to search for: ")

    # Get the winners in that year range
    myWinners = findWinners(category, years, awards, winners)
    
    # Print the winners that were found
    printWinners(myWinners)

    
