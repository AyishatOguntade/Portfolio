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

# Function to execute the processes in the queue
def scheduleProcs(tslice, allotedP, cpuQ):
    while not cpuQ.empty():
            # Get next process from queue
        proc = cpuQ.get()
            # Separate the process ID and the execution time from the process info
        PID, exectime = proc.split(",")
            # Convert exectime to an integer
        exectime = int(exectime)
            
        print("Getting next process - Process", PID, "has", exectime, "instructions to execute")
            
            # Initialize the timer
        timer = 0
        thr = 2 * tslice
            
        if exectime >= thr:
                # If exectime is greater than or equal to 2 times the time slice
            runt = int(exectime * allotedP)
            for _ in range(runt):
                if exectime > 0:
                    exectime -= 1
                    timer += 1
                    print("Executing instruction", exectime, "of process", PID, ". Timer =", timer)
            if exectime > 0:
                    # If proc still has instructions to execute, put it back in the queue
                proc = f"{PID},{exectime}"
                cpuQ.put(proc)
                print("Put process", PID, "back in queue with", exectime, "instructions left to execute")
            else:
                print("*** Process", PID, "Complete ***")
        else:
                # If exectime is less than 2 times the time slice
            for _ in range(3):
                if exectime > 0:
                    exectime -= 1
                    timer += 1
                    print("Executing instruction", exectime, "of process", PID, ". Timer =", timer)
            if exectime > 0:
                    # If proc still has instructions to execute, put it back in the queue
                #proc = f"{PID},{exectime}"
                cpuQ.put(proc)
                print("Put process", PID, "back in queue with", exectime, "instructions left to execute")
            else:
                print("*** Process", PID, "Complete ***")
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





    
