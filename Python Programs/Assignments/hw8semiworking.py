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

    #print(bList)
    #print(checksum)

    return bList
#work on this fucntion 
def k_Fletcher32(plaintext, k):
    #aList = translateLetter(plaintext)
    bList = fletcher32(plaintext)
    bList.remove(0)
    x = 0
    kList = [0]
    while x < k:
        i = 0
        while i < len(bList):
            t = (bList[i] + kList[i]) % 65535
            kList.append(t)
            i = i + 1
        x = x + 1
        bList = kList.copy()
        kList = [0]
    checksum = sum(kList)
    print(kList)
    print(bList)


    return checksum
