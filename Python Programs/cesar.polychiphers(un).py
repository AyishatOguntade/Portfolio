#Initialice ciphertext
#for each letter in plaintext
#find the numerical equivilent of the letter
#add shfit to numerical equivilent (mod by 26)
#find character equivilent of chifted number
#add character to the cipheretxt 


alphabet =['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

#write the whole alphabet 

def ceasarCipher(plaintext,key):
    ciphertext = ""
    for i in range(len(plaintext)):
        letter = plaintext[i]
        #This is the first letter of the given word
        num = alphabet.index(letter)
        shiftNum = (num + key) % len(alphabet)
        #It would be mod 26 too
        cipherLetter = alphabet[shiftNum]
        ciphertext = ciphertext + cipherLetter
        #add each letter to the word 
    return ciphertext

#Just change the plus to a minus 

def UnceasarCipher(plaintext,key):
    ciphertext = ""
    for i in range(len(plaintext)):
        letter = plaintext[i]
        #This is the first letter of the given word
        num = alphabet.index(letter)
        shiftNum = (num - key) % len(alphabet)
        #It would be mod 26 too
        cipherLetter = alphabet[shiftNum]
        ciphertext = ciphertext + cipherLetter
        #add each letter to the word 
    return ciphertext


def polyCipher(plaintext,keyword):
    chiphertext = ""
    for i in range(len(plaintext)):
        letter = plaintext[i]
        num = alphabet.index(letter)
        j = i % len(keyword)
        #This helps fix the error so that it keeps wriaping the keyword
        keyLetter = keyword[i]
        keynum = alphabet.index(keyLetter)
        shiftNum = (num + keynum) % len(alphabet)
        cipherLetter = alphabet[shiftNum]
        ciphertext = ciphertext + cipherLetter
    return ciphertext

#Just change the plus to a minus

def UnpolyCipher(plaintext,keyword):
    chiphertext = ""
    for i in range(len(plaintext)):
        letter = plaintext[i]
        num = alphabet.index(letter)
        j = i % len(keyword)
        #This helps fix the error so that it keeps wriaping the keyword
        keyletter = keyword[i]
        keynum = alphabet.index(keyLetter)
        shiftNum = (num - keynum) % len(alphabet)
        cipherLetter = alphabet[shiftNum]
        ciphertext = ciphertext + cipherLetter
    return ciphertext
