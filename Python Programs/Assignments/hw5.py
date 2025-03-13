#Homework 5
#Ayishat Oguntade
#Working with Files
#Due October 23

#Function that gets the file and asks the user to try again if they put in a incorrect one

def openFile():
    goodfile = False
    while goodfile == False:
        fname = input("Please enter the name of the data file: ")
        try:
            olympicfile = open(fname,'r')
            goodfile = True
        except IOError:
            print("Invalid file name, try again...")
    return olympicfile

#Function that gets the data from the file and stores it into diffrent lists to work with

def getData():
    olympicfile = openFile()

    yearList = []
    locList = []
    contList = []

    for line in olympicfile:
        line = line.strip()
        year, loc, cont = line.split(";")
        yearList.append(year)
        locList.append(loc)
        contList.append(cont)

    olympicfile.close()

    return yearList, locList, contList

#Function that gets the search name from the lists and ensures that its correct

def getSearchCont(contList):
    OK = False
    while OK == False:
        searchCont = input("Enter the continent you are searching for: ")
        if searchCont in contList:
            OK = True
        else:
            searchCont = input("Invalid entry -- Enter the continent you are searching for: ")
            if searchCont in contList:
                OK = True
    return searchCont

#Function that creates  and output file of all oplympic that took place for the given year

def writeToFile(searchCont, yearList, locList, contList):
    outName = searchCont +".txt"
    outFile = open(outName,'w')
    for i in range(len(yearList)):
        if contList[i] == searchCont:
            outFile.write(yearList[i] + ";" + locList[i]+ "\n")
    outFile.close()
    print("Your output has been written to ", outName)
    return

def main():
    yearList, locList, contList = getData()
    searchCont = getSearchCont(contList)
    writeToFile(searchCont, yearList, locList, contList)
