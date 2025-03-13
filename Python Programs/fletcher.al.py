#Homework 8
#Ayishat Oguntade
#Digital Forensics
#Due Novemeber 13 11:59

def translateLetter(plaintext):
    aList = []

    for i in range(len(plaintext)):
        letterNum = ord(plaintext[i])
        aList.append(letterNum)
    return aList

def fletcher32(plaintext):
    aList = translateLetter(plaintext)
    bList = [0]
    t = 0
    for i in range(len(aList)):
        t = (aList[i] + bList[i]) % 65535
        bList.append(t)
    checksum = sum(bList)

    print(bList)
    print(checksum)

    return bList
#above is the regular fletcher algortith 
def k_Fletcher32(plaintext, k):
    bList = fletcher32(plaintext)
    


    return checksum
