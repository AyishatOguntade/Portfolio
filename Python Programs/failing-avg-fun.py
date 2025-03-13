# Average Failing Grades

# Given: List of student grades and a failing grade threshold
# Find: Average of all failing grades

# Function to get the grades from the user and store them in a list
# Parameters: None
# Return: List of grades (integers)
def getGrades():
    numGrades = int(input("Enter number of grades: "))
    gradeList = []
    for i in range(numGrades):
        grade = int(input("Enter grade: "))
        gradeList.append(grade)
    return gradeList

# Function to find all failing grades
# Parameters: List of grades (integers)
# Return: List of failing grades (integers)
def findFailing(gradeList):
    threshold = int(input("Enter failing grade threshold: "))
    failingList = []
    for i in range(len(gradeList)):
        if gradeList[i] < threshold:
            failingList.append(gradeList[i])
    return failingList

# Function to compute the average of the failing grades
# Parameters: List of failing grades (integers)
# Return: Average of failing grades (float)
def computeAverage(failingList):
    if len(failingList) == 0:
        return -1
    else:
        total = 0
        for i in range(len(failingList)):
            total = total + failingList[i]
        average = total/len(failingList)
    return average

# Function to print the results
# Parameters: Average of failing grades (float)
# Return: None
def printResults(average):
    if average == -1:
        print("There are no failing grades")
    else:
        print("The average of the failing grades is ", average)
    return

# Main function
def main():
    gradeList = getGrades()
    failingList = findFailing(gradeList)
    average = computeAverage(failingList)
    printResults(average)
