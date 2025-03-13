# Jason Fopiano
# CSC110-0001
# hw6_1
# Due 10.30.23

def openFile():
    goodFile = False
    while goodFile == False:
        fname = input("Please enter the name of the data file: ")
        try:
            inFile = open(fname, 'r')
            goodFile = True
        except IOError:
            print("Invalid file name, try again ...")
    return inFile

def getData():
    inFile = openFile()
    yearList = []
    maleList = []
    femaleList = []
    line = inFile.readline()

    for line in inFile:
        line.strip()
        year, male, female = line.split(",")

        yearList.append(int(year))
        maleList.append(male)
        femaleList.append(int(female))
    inFile.close()

    return yearList, maleList, femaleList

def getYear(yearList):
    yearFound = False
    
    while yearFound == False:
        try:
            year = int(input("Enter a year: "))
            high = int(yearList[len(yearList) -1])
            low = int(yearList[0])

            if year <= high and year >= low:
                yearFound = True
            else:
                print("Year not in range, try again...")
        except ValueError:
            print("Invalid entry, try again...")
    return year

def getYearLinear(yearList, year):
    compsLinear = 0
    pos = -1
    for i in range(len(yearList)):
        compsLinear += 1
        pos += 1
        if yearList[i] == year:
            print("Linear Search: comps = ", compsLinear)
            return int(pos)
    return

def getYearBinary(yearList, year):
    compsBinary = 0
    left = 0
    right = len(yearList) - 1

    while left <= right:
        compsBinary += 1
        m = (left + right) // 2
        if yearList[m] == year:
            print("Binary Search: comps = ", compsBinary)
            return int(m)
        elif int(yearList[m]) < year:
            left = m + 1
        else:
            right = m - 1
    return

def main():
    yearList, maleList, femaleList = getData()
    year = getYear(yearList)
    pos = 0
    compLin = getYearLinear(yearList, year)
    compBin = getYearBinary(yearList, year)
    pos = yearList.index(year)

    print("In ", year, "there were ", femaleList[pos], " women CS graduates.")
