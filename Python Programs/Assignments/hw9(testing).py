# Given: A list of processes with execution times
# Find: A schedule of the processes using time slices

import queue
import random

# Function to open the file using exception handling
def openFile():
    goodFile = False
    while goodFile == False:
        fname = input("Enter name of data file: ")
        try:
            inFile = open(fname, 'r')
            goodFile = True
        except IOError:
            print("Invalid filename, please try again ... ")
    return inFile


# Function to get the time slice value and the processes from the file into the queue
# Queue will contain a string with process ID and exec time separated by a comma

def getProcs(cpuQ):
    infile = openFile()
    # Get the first line in the file containing the time slice value
    line = infile.readline()                        
    # Strip the \n from the line and convert to an integer
    tslice = int(line.strip())
    line = infile.readline()
    allotedP = float(line.strip())
    # Loop through the file inserting processes into the queue
    for line in infile:                     
        proc = line.strip()
        cpuQ.put(proc)
    infile.close()
    return tslice, allotedP, cpuQ

# Function to print the contents of the queue

def printQueue(tslice, allotedP, cpuQ):
    print("The time slice is ",tslice)
    print("The alloted percentage is", allotedP)
    print("The contents of the queue are: ")
    for i in range(cpuQ.qsize()):
        proc = cpuQ.get()
        cpuQ.put(proc)
        print(proc)


# Function to execute the processes in the queue

def scheduleProcs(tslice, allotedP, cpuQ):
    while (cpuQ.empty() == 0):                  
	# Get next process from queue
        proc = cpuQ.get()                           
	# Separate the process ID and the execution time from the process info
        PID, exectime = proc.split(",")             
	# Convert exectime to an integer
        exectime = int(exectime)                    
        print("Getting next process - Process ", PID," has ", exectime," instructions to execute")
	# Initialize the timer
        timer = 0                                   
	# While proc still has time in slice and still has code to execute
        thr = 2 * tslice
        #print(thr)
        #make sure process dont run mroe than 3 times at a time,
        #ex 7 times 0.2 = 1.4 then it will run once and put it back in que 
        #print(exectime)
        if exectime >= thr:
            runt = exectime * allotedP
            x = int(runt)
            while x > 0:
                exectime = exectime - 1
                timer = timer + 1
                print("Executing instruction ", exectime," of process ", PID,".  Timer = ", timer)
                x = x - 1
            if exectime > 0:
                proc = PID + "," + str(exectime)        
                cpuQ.put(proc)
                print("Put process ", PID," back in queue with ", exectime," instructions left to execute")
            else:
                print("*** Process ", PID, " Complete ***")
        else:
            x = 3
            while x > 0:
                exectime = exectime - 1
                timer = timer + 1
                print("Executing instruction ", exectime," of process ", PID,".  Timer = ", timer)
                x = x - 1
                    
            if (exectime > 0):      
                proc = PID + "," + str(exectime)        
                cpuQ.put(proc)
                print("Put process ", PID," back in queue with ", exectime," instructions left to execute")
            else:
                print("*** Process ", PID, " Complete ***")
                    
	

	# If proc still has instructions to execute put it back in the queue
        #if (exectime > 0):                          
	    # Create string with new exec time and process ID
            #proc = PID + "," + str(exectime)        
	    # Put the process back in the queue
            #cpuQ.put(proc)
            #print("This is exectime" ,exectime)
            #print("Put process ", PID," back in queue with ", exectime," instructions left to execute")
        #else:
            #print("*** Process ", PID, " Complete ***")
    return


# Main function

def main():
    # Create the scheduling queue
    cpuQ = queue.Queue()

    # Get the processes from the data file
    tslice, allotedP, cpuQ = getProcs(cpuQ)

    # Print the queue
    printQueue(tslice, allotedP, cpuQ)

    # Schedule the processes
    scheduleProcs(tslice,allotedP, cpuQ)





    
