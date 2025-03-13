# Compute average of failing grades
# Using data files and exception handling

# Function to open data file
def openFile():
    goodFile = False
    while goodFile == False:
        fname = input("Enter name of output file: ")
        # Begin exception handling
        try:
            # Try to open the file with the given name
            gradeFile = open(fname, 'r')
            goodFile = True
        except IOError:
            # If file name is not valid IOError exception is raised
            print("Invalid file name, please try again...")
    return gradeFile


# Function to read data file
def getGrades():
    # Open data file
    gradeFile = openFile()
    gradeList = []
    line = gradeFile.readline()
    # Loop through the file to read each line
    while line != "":
        grade = line.strip()
        grade = int(grade)
        gradeList.append(grade)
        line = gradeFile.readline()

    gradeFile.close()
    return gradeList

# Function to get failing grade - uses exception handling
def getFailingGrade():
    OK = False
    while OK == False:
        try:
            failingGrade = int(input("Enter failing grade threshold: "))
            OK = True
        except ValueError:
            print("Failing grade must be an integer, please try again...")
    return failingGrade

# Function to compute the average of the failing grades

def computeFailingAverage(myList):
    #Get failing grade threshold
 
    failingGrade = getFailingGrade()
 
    # Compute average of failing grades
 
    totalFailing = 0
    countFailing = 0
 
    # For loop that uses i to increment through list
 
    for i in range(len(myList)):
        if myList[i] < failingGrade:
            totalFailing = totalFailing + myList[i]
            countFailing = countFailing + 1
 
    # Compute Average
    if countFailing > 0:
        averageFailing = totalFailing/countFailing
    else:
        averageFailing = -1
    
    return averageFailing
 

# Function to print the resulting average 
def printAverage(average):
    if average == -1:
        print("No failing grades!")
    else:
        print("The average of the failing grades is: " + str(average))
    
    return
 
 
def main():
    gradeList = getGrades()
    avg = computeFailingAverage(gradeList)
    printAverage(avg)
