#Homework 6_1
#Ayishat Oguntade
#Due 10/30/23
#Analysis of Algorithms

#Get the file and make sure its a correct input
def openFile():
    goodFile = False
    while goodFile == False:
        fname = input("Please enter the name of the data file: ")
        # Begin exception handling
        try:
            # Try to open the file with the given name
            gradFile = open(fname, 'r')
            goodFile = True
        except IOError:
            # If file name is not valid IOError exception is raised
            print("Invalid file name, try again...")
    return gradFile

#Make a function that gets the data from the file and stores it into diffrent lists
def getData():
    gradFile = openFile()
    yearList = []
    femList = []
    maleList = []
    line = gradFile.readline()

    for line in gradFile:
        line = line.strip()
        year,male,fem = line.split(',')
        yearList.append(int(year))
        femList.append(fem)
        maleList.append(male)

    gradFile.close()

    return yearList, femList, maleList

#Get a valid year from the user

def getYear():
    OK = False
    while OK == False:
        try:
            year = int(input("Enter a year:"))
            OK = True
            if year < 1965 or year > 2020:
                print("Year not in range, try again...")
                OK = False
        except ValueError:
            print("Invalid entry, try again...")
    
    return year

# Do the Linear function to use the user year  and return the position

def getYearLinear(yearList,year):
    position1 = 0
    work1 = 0
    for i in range(len(yearList)):
        work1= work1 + 1
        if year == yearList[i]:
            position1 = i
            break
    print("Linear Search: comps =", work1)
    return position1
        
#Do the binary function to use the user year and return the postiton

def getYearBinary(yearList,year):
    left = 0
    right = len(yearList) - 1
    comps = 0
    position = -1

    while left <= right :
        comps = comps + 1
        mid = (left + right) // 2
        if yearList[mid] == year:
            position = mid
            break
        elif yearList[mid] < year:
            left = mid + 1
        else:
            right = mid - 1
    print("Binary Search: comps =", comps)


    return position

#Write the main function

def main():
    yearList, femList, maleList = getData()
    year = getYear()
    print("")
    position = getYearBinary(yearList,year)
    print("")
    position1 = getYearLinear(yearList,year)
    print("In", year ,"there were",femList[position1], "women CS graduates.")


#Discussion (f)
#Linear search is generally less efficient than binary search, especially for large datasets.
#The worst-case scenario for linear search is when the desired year is at the end of the list, requiring n comparisons for a list of n elements.
#Binary search performs significantly better, especially for sorted data.
#The worst-case scenario for binary search is when the desired year is not in the list or located in the middle, requiring log2(n) comparisons for a list of n elements.
#Binary search is efficient when the list is sorted,
#while linear search doesn't require sorting but can be slower for large datasets.
    
    
