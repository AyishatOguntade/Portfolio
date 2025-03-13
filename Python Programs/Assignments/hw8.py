#Homework 8
#Ayishat Oguntade
#Digital Forensics
#Due Novemeber 13 11:59

#Translate each letter in the plaintext to there numerical value
def translateLetter(plaintext):
    aList = []

    for i in range(len(plaintext)):
        letterNum = ord(plaintext[i])
        aList.append(letterNum)
    return aList

#Create the regular fletcher32 algorithm 

def fletcher32(plaintext):
    aList = translateLetter(plaintext)
    bList = [0]
    t = 0
    for i in range(len(aList)):
        t = (aList[i] + bList[i]) % 65535
        bList.append(t)
    checksum = sum(bList)

    return bList

#This function will take the plaintext and translate each leter and do the fletcher 32 algorithm k times

def k_Fletcher32(plaintext, k):
    bList = fletcher32(plaintext)
    zList = bList
    zList.remove(0)
    x = 0
    kList = [0]
    while x < k:
        i = 0
        while i < len(zList):
            t = (zList[i] + kList[i]) % 65535
            kList.append(t)
            i = i + 1
        x = x + 1
        zList = kList.copy()
        kList = [0]
    y = len(zList) -1
    checksum = zList[y]

    return checksum
