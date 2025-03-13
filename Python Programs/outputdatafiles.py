#In class reference 10/19/23
#How to Output data into a file and not print on the screen

#Output results of file

def outputResults(nameList, gradeList, indexList):
    outName= input("Enter output file name:")
    outFile = open(outName,'w')
    for i in range(len(indexList)):
        x = indexList[i]
        outFile.write(nameList[x]+','+str(gradeList[x]) +'\n')
    outFile.close()
#out function can only write strings
    return
