# Name:        Ayishat Oguntade
# Class:       CSC 110 - Fall 2023
# Assignment:  Programming Project Design
# Due Date:    December 8 2023

#Program Title: Movie Data

#Project Description:
#--------------------
#This program will read in a data file with movies that were released
#between 2006 and 2016 and display information requested by the user.
#This program will present the user with a list of options and will
#display the results of the action chosen by the user.
#The program will continue to run until the user chooses to quit.  

#General Solution:
#-----------------
#From the file provided create diffrent lists then use those lists
#to compute the math or information needed to get the information desired by the user.
#Then return the values so that the main function will be able to compute the print statements.


#Psudocode for main function:
#----------------------------
#Call the getdata function
#Then create a while loop for if the choice selected is not equal to 7
#Then create a long if and elif statement
#with diffrent parameter for the diffrent choices
#in each of the if/elif statements they will call that function to get those return values
#that are needed to get the correct information for the user
#Then print the results for each selection




#Function Design:
#-----------------
def openFile():
    goodFile = False
    while goodFile == False:
        fname = input("Please enter a file name: ")
        # Begin exception handling
        try:
            # Try to open the file with the given name
            movieFile = open(fname, 'r')
            goodFile = True
        except IOError:
            # If file name is not valid IOError exception is raised
            print("Invalid file name try again...")
    return movieFile

def getData(movieFile):
    #This function will use the movie data file and make 6 diffrent lists
    #It will format the information to what is needed
    #Then it will return all those lists made
    titleList = []
    genreList = []
    directorList = []
    yearList = []
    runtimeList = []
    revenueList = []
    line = movieFile.readline()
    line = movieFile.readline()
    while line != "":
        line = line.strip()
        title,genre,director,year,runtime,revenue = line.split(',')
        titleList.append(title)
        genreList.append(genre)
        directorList.append(director)
        yearList.append(int(year))
        runtimeList.append(int(runtime))
        revenueList.append(float(revenue))
        line = movieFile.readline()
    movieFile.close()
    return titleList, genreList, directorList, yearList, runtimeList, revenueList


def findFlimDirectorinfo(titleList, genreList, directorList, yearList, runtimeList, revenueList):
    #This funtion will ask the user for the correct name usaing all the exceptions
    foundTitlesList = []
    foundGenreList = []
    foundDirectorList = []
    foundYearList = []
    foundRuntimeList = []
    foundRevenueList = []

    OK = False
    multiIndex = []
    while OK == False:
        directorName = input("Enter director:")
        
        for i in range(len(directorList)):
            if directorList[i] == directorName:
                multiIndex.append(i)
                OK = True
                
        if OK == True:
            directorName = directorName
        else: 
            print("Invalid entry - Try again")
    #Then it will use that name to and the index of the name to find all the correct info from the other lists
    #Then store it in lists
    for i in multiIndex:
        foundTitlesList.append(titleList[i])
        foundGenreList.append(genreList[i])
        foundDirectorList.append(directorList[i])
        foundYearList.append(yearList[i])
        foundRuntimeList.append(runtimeList[i])
        foundRevenueList.append(revenueList[i])
    return foundTitlesList, foundGenreList, foundDirectorList, foundYearList, foundRuntimeList, foundRevenueList

def findHighestGrossFilm(titleList, genreList, directorList, yearList, runtimeList, revenueList):
    #This function will find the information needed to display
    #the hisghest grossing film in the spesified year
    OK = False
    while OK == False:
        try:
            year = int(input("Enter year:"))

            if 2006 <= year and year <= 2016:
                maxRev = 0
                maxRevI = 0
                for i in range(len(yearList)):
                    if yearList[i] == year and revenueList[i] > maxRev:
                        maxRev = revenueList[i]
                        maxRevI = i
                   
                    highestGrossTitle = titleList[maxRevI]
                    highestGrossGenre = genreList[maxRevI]
                    highestGrossDirector = directorList[maxRevI]
                    highestGrossYear = yearList[maxRevI]
                    highestGrossRuntime = runtimeList[maxRevI]
                    highestGrossRevenue = revenueList[maxRevI]
                    OK = True    
            else:
                print("Year out of range, must be between 2006 and 2016")
        except ValueError:
            print("Invalid entry - Try again")
    #This function will also do all the year checking to make sure its correct.
    #Then search in the provided lists to find the info
    return highestGrossTitle, highestGrossGenre , highestGrossDirector, highestGrossYear, highestGrossRuntime, highestGrossRevenue

def getYears():
    OK = False
    
    while OK == False:
        try:
            yearx= int(input("Year1:"))
            if 2006<= yearx and yearx <= 2016:
                year1 = yearx
                OK = True
            else:
                print("Year out of range, must be between 2006 and 2016")
        except ValueError:
            print("Invalid entry - Try again")
            
    ZK = False
    while ZK == False:
        try:
            yeark = int(input("Year2:"))
            if yeark > yearx:
                year2 =yeark
                ZK = True
            else:
                print("Second year should be after first year - try again")
                year1 = int(input("Year1:"))
        except ValueError:
            print("Invalid entry - Try again")
            
    return year1,year2

def getgenre(genreList):
    OK = False
    while OK == False:
        genre = input("Enter genre:")
        if genre in genreList:
            return genre
        else:
            print("Invalid entry - Try again")


def findFilmByYearAndGenre(titleList, genreList, directorList, yearList, runtimeList, revenueList):
    year1,year2 = getYears()
    genre = getgenre(genreList)
   
    newtitleList = []
    newgenreList = []
    newdirectorList = []
    newyearList = []
    newruntimeList = []
    newrevenueList = []

    for i in range(len(titleList)):
        if year1 <= yearList[i] <= year2 and genre in genreList[i]:
            newtitleList.append(titleList[i])
            newgenreList.append(genreList[i])
            newdirectorList.append(directorList[i])
            newyearList.append(yearList[i])
            newruntimeList.append(runtimeList[i])
            newrevenueList.append(revenueList[i])

    return newtitleList, newgenreList, newdirectorList, newyearList, newruntimeList, newrevenueList

def searchByTitle(searchname,titleList, genreList, directorList, yearList, runtimeList, revenueList):
    #Work on this assignment
    x = 0
    while x < len(titleList):
        for i in range(len(titleList)):
            if titleList[i] == searchname:    
                index = i
                ftitle = titleList[index]
                fgenre = genreList[index]
                fdirector = directorList[index]
                fyear = yearList[index]
                fruntime = runtimeList[index]
                frevenue = revenueList[index]
                x = len(titleList)
                return ftitle, fgenre, fdirector, fyear, fruntime, frevenue
            x = x + 1
    return ''
        


    #It will get all the correct information for the given title, by finding the index
    #return ftitle, fgenre, fdirector, fyear, fruntime, frevenue

def findAverageRuntime(titleList, genreList, directorList, yearList, runtimeList, revenueList):
    #This function will ask the user for the revenue limit
    limit = int(input("Enter revenue limit (millions): $"))
     
    limitRevList = []
    for i in range(len(revenueList)):
        if revenueList[i] > limit:
            limitRevList.append(revenueList[i])

    if limitRevList == []:
        totalaverage = 0
        limit = limit
        return totalaverage,limit
    else:    
        limitRunList =[]
        for i in range(len(revenueList)):
            if revenueList[i] > limit:
                limitRunList.append(runtimeList[i])
                
        total = 0
        for i in range(len(limitRunList)):
            total = total + limitRunList[i]
                       
        totalaverage = total / len(limitRunList)
                
                    

        #Then compute the average of all the numbers equal to and higher than the limit
        #Then return the correct number 
        return totalaverage,limit

def sortedfile(titleList, genreList, directorList, yearList, runtimeList, revenueList):
    indexes = list(range(len(revenueList)))
    for i in range(len(revenueList)):
        min_index = i
        for j in range(i+1,len(revenueList)):
            if revenueList[indexes[j]] < revenueList[indexes[min_index]]:
                min_index = j
        indexes[i], indexes[min_index] = indexes[min_index], indexes[i]
    return indexes

def writetofile(titleList, genreList, directorList, yearList, runtimeList, revenueList):
    #This function will sort the lists by revenue
    indexes = sortedfile(titleList, genreList, directorList, yearList, runtimeList, revenueList)
    outName = ("movies-sorted-rev.csv")
    outFile = open(outName,'w')
    for i in indexes:
        outFile.write(titleList[i]+',' + genreList[i]+',' + directorList[i]+',' + str(yearList[i])+',' + str(runtimeList[i])+',' + str(revenueList[i])+'\n')
    outFile.close()
    #Then write it into a new file
    return

def getChoice():
    # This function displays the menu of choices for the user
    # It reads in the user's choice and returns it as an integer
    print("")
    print("Please choose one of the following options:")
    print("1 -- Find all films made by a specified director")
    print("2 -- Find the highest grossing film made in a specific year")
    print("3 -- Find all films made in a given year range in a specified genre")
    print("4 -- Search for a film by title")
    print("5 -- Find average runtime of films with higher revenue than specified value")
    print("6 -- Sort all lists by revenue and write the results to a new file")
    print("7 -- Quit")
    #work of the exeption handling for the input choice
    
    OK = False
    while OK == False:
        try:
            choice = int(input("Choice ==> "))
            if choice >= 1 and choice <= 7:
                OK = True
            else:
                print("Choice must be between 1 and 7")
                print("")
                   
        except ValueError:
            print("Invalid entry - Try again")
        
    return choice

def printFunction(titles, genres, directors, years, runtimes, revs):
    for i in range(len(titles)):
        print(titles[i].ljust(45), genres[i].ljust(35), directors[i].ljust(24), str(years[i]).ljust(8), str(runtimes[i]).ljust(8), ("$"+str(revs[i])).rjust(12))
    return

def main():
    #The main function will implement the pseudocode by using the functions defined above
    movieFile = openFile()
    choice = getChoice()
    titleList, genreList, directorList, yearList, runtimeList, revenueList = getData(movieFile)
    #how to adjust
    #print(titles[i].ljust(45), genres[i].ljust(35), directors[i].ljust(24), str(years[i]).ljust(8), str(runtimes[i]).ljust(8), ("$"+str(revs[i])).rjust(12))

    while choice != 7:
        if choice == 1:
            print("")
            foundTitlesList, foundGenreList, foundDirectorList, foundYearList, foundRuntimeList, foundRevenueList =  findFlimDirectorinfo(titleList, genreList, directorList, yearList, runtimeList, revenueList)
            print("")
            print("The films that meet your criteria are:")
            print("")
            print("TITLE".ljust(45), "GENRE".ljust(35), "DIRECTOR".ljust(24), "YEAR".ljust(8), "RUNTIME".ljust(8), "REVENUE(mil)".rjust(12))
            printFunction(foundTitlesList, foundGenreList, foundDirectorList, foundYearList, foundRuntimeList, foundRevenueList)
            choice = getChoice()
        elif choice == 2:
            print("")
            highestGrossTitle, highestGrossGenre , highestGrossDirector, highestGrossYear, highestGrossRuntime, highestGrossRevenue = findHighestGrossFilm(titleList, genreList, directorList, yearList, runtimeList, revenueList)
            print("")
            print("The film that meets your criteria is:")
            print("")
            print("TITLE".ljust(45), "GENRE".ljust(35), "DIRECTOR".ljust(24), "YEAR".ljust(8), "RUNTIME".ljust(8), "REVENUE(mil)".rjust(12))
            print(highestGrossTitle.ljust(45), highestGrossGenre.ljust(35) , highestGrossDirector.ljust(24), str(highestGrossYear).ljust(8), str(highestGrossRuntime).ljust(8), ("$"+str(highestGrossRevenue)).rjust(12))
            choice = getChoice()
        elif choice == 3:
            print("")
            print("Enter year range to search (oldest year first)")
            newtitleList, newgenreList, newdirectorList, newyearList, newruntimeList, newrevenueList = findFilmByYearAndGenre(titleList, genreList, directorList, yearList, runtimeList, revenueList)
            print("The films that meet your criteria are:")
            print("")
            print("TITLE".ljust(45), "GENRE".ljust(35), "DIRECTOR".ljust(24), "YEAR".ljust(8), "RUNTIME".ljust(8), "REVENUE(mil)".rjust(12))
            printFunction( newtitleList, newgenreList, newdirectorList, newyearList, newruntimeList, newrevenueList)
            choice = getChoice()
        elif choice == 4:
            print("")
            searchname = input("Enter title:")
            if searchname in titleList:
                ftitle, fgenre, fdirector, fyear, fruntime, frevenue = searchByTitle(searchname,titleList, genreList, directorList, yearList, runtimeList, revenueList)
                print("The film that meets your criteria  is:")
                print("")
                print("TITLE".ljust(45), "GENRE".ljust(35), "DIRECTOR".ljust(24), "YEAR".ljust(8), "RUNTIME".ljust(8), "REVENUE(mil)".rjust(12))
                print(ftitle.ljust(45), fgenre.ljust(35), fdirector.ljust(24), str(fyear).ljust(8), str(fruntime).ljust(8), ("$"+str(frevenue)).rjust(12))
            else:
                print("")
                print("No such film exists.")
            
            choice = getChoice()
        elif choice == 5:
            print("")
            totalaverage,limit = findAverageRuntime(titleList, genreList, directorList, yearList, runtimeList, revenueList)
            if totalaverage > 0 :
                print("The average runtime for films with revenue higher than $",limit,".00 million is",round(totalaverage,2), "minutes.")
                
            else:
                print("No films have revenue higher than $",limit,".00 million.")
            #round this number 2 places
            choice = getChoice()
        elif choice == 6:
            writetofile(titleList, genreList, directorList, yearList, runtimeList, revenueList)
            print("Sorted data has been written to the file: movies-sorted-rev.csv.")
            #Call the functions that dose this action
            choice = getChoice()
            
        else:
            print("Error in your choice")
            choice = getChoice()
    print("Good-bye")


    return 

