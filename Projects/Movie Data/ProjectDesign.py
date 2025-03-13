# Name:        Ayishat Oguntade
# Class:       CSC 110 - Fall 2023
# Assignment:  Programming Project Design
# Due Date:    October 27 2023

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

#Psudocode for main function:
#----------------------------
#call the getdata function
#Then create a while loop for if the choice selected is not equal to 7
#Then create a long if and elif statement
#with diffrent paremeter for the diffrent choices
#in each of the if/elif statements they will call that function to get those return values
#and print the results for each selection




#Function Design:
#-----------------

def getData():
    #This function will use the movie data file and make 6 diffrent lists
    #It will format the information to what is needed
    #Then it will return all those lists made
    return titleList, genreList, directorList, yearList, runtimeList, revenueList

def findFlimDirectorinfo(titleList, genreList, directorList, yearList, runtimeList, revenueList):
    #This funtion will ask the user for the correct name usaing all the exceptions
    #Then it will use that name to and the index of the name to find all the correct info from the other lists
    #Then store it in lists 
    return foundTitlesList, foundgGenreList, foundDirectorList, foundYearList, foundRuntimeList, foundrevenueList

def findHighestGrossFilm(titleList, genreList, directorList, yearList, runtimeList, revenueList):
    #This function will find the information needed to display
    #the hisghest grossing film in the spesified year
    #This function will also do all the year checking to make sure its correct.
    #Then search in the provided lists to find the info
    return highestGrossTitle, highestGrossGenre , highestGrossDirector, highestGrossYear, highestGrossRuntime, highestGrossRevenue

def findFilmByYearAndGenre(titleList, genreList, directorList, yearList, runtimeList, revenueList):
    #This function will ask the user for the correct years and all the exception needed
    #Then ask the user for the correct genre
    #If the genre is not avalible then it will ask the user to try again
    #Then it will create the lists of the correct information in the year ranges so it can print later
    return newtitleList, newgenreList, newdirectorList, newyearList, newruntimeList, newrevenueList

def searchByTitle(titleList, genreList, directorList, yearList, runtimeList, revenueList):
    #This function will ask the user for the correct title and if it is invalid
    #Then it will print that no such file exisits then it will retun the choices again
    #Then it will get all the correct information for the given titile
    return ftitle, fgenre, fdirector, fyear, fruntime, frevenue

def findAverageRuntime(titleList, genreList, directorList, yearList, runtimeList, revenueList):
    #This function will ask the user for the revenue limit
    #Then compute the average of all the numbers equal to and higher than the limit
    #Then return the correct number 
    return totalaverage

def writetofile(titleList, genreList, directorList, yearList, runtimeList, revenueList):
    #This function will sort the lists by revenue
    #Then write it into a new file
    return

def getChoice():
    # This function displays the menu of choices for the user
    # It reads in the user's choice and returns it as an integer
    print("")
    print("Please choose one of the following options:")
    print("1 - Find all films made by a specified director")
    print("2 - Find the highest grossing film made in a specific year")
    print("3 - Find all films made in a given year range in a specified genre")
    print("4 - Search for a film by title")
    print("5 - Find average runtime of films with higher revenue than spesified value")
    print("6 - Sort all lists by revenue and write the results to a new file")
    print("7 - Quit")
    OK = False
    while OK == False:
        choice = int(input("Choice ==> "))
        if choice < 1 and choice > 7
        print("Menu choice must be a number between 1 and 7, please try again...")
        print("")
    return choice

def main():
    #The main function will implement the pseudocode by using the functions defined above
