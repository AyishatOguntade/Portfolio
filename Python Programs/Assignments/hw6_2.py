#Homework 6_2
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
        femList.append(int(fem))
        maleList.append(int(male))

    gradFile.close()

    return yearList, femList, maleList


#Make a function that computes the percent of female CS grads in each year and stores as a result
def findpercent(yearList,maleList,femList):
    percentList = []
    for i in range(len(yearList)):
        total = maleList[i] + femList[i]
        percent = (femList[i]/total)
        percentList.append(percent)
    return percentList

def dualSort(list1,list2):
    #Use this code and modify it so that it dose the work for 2 lists
    #Then return both Lists
    #list1 = yearList
    #list 2 = percentList
    #
    for i in range(1, len(list1)):
        year = list1[i]
        percentfem = list2[i]
        j = i
        while j > 0 and percentfem > list2[j - 1] :
            # comparison
            list1[j] = list1[j - 1]
            list2[j] = list2[j - 1]
            j = j - 1
	    # swap
        list1[j] = year
        list2[j] = percentfem

    return list1, list2

#Output results to a file
def outputResults(list1,list2):
    outName=("pctWomen-sorted.csv")
    outFile = open(outName,'w')
    outFile.write("year"+","+"pctWomen"+"\n")
    for i in range(len(list1)):
        outFile.write(str(list1[i])+','+str(list2[i]) +'\n')
    outFile.close()
#out function can only write strings
    return

#Make the main function
def main():
    yearList, femList, maleList = getData()
    percentList = findpercent(yearList,maleList,femList)
    list1,list2 = dualSort(yearList,percentList)
    outputResults(list1,list2)
    print("Your output has been saved in pctWomen-sorted.csv")
