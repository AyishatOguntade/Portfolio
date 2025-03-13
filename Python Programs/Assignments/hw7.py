#Ayishat Oguntade
#CSC 110 - HW 7 Cryptography
#11/6/23 11:59 pm

#Import the Random Feature

import random

alphabet =['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

def caesarRandom(plaintext, seedIn):
    random.seed(seedIn)
    ciphertext = ""
    plaintext = plaintext.lower()
    plaintext = plaintext.replace(" ","")
    for i in range(len(plaintext)):
        letter = plaintext[i]
        num = random.randint(0,len(alphabet) - 1 )
        shiftNum =  (alphabet.index(letter)+ num) % (len(alphabet))
        cipherLetter = alphabet[shiftNum]
        ciphertext = ciphertext + cipherLetter
    return ciphertext

def unCaesarRandom(ciphertext, seedIn):
    random.seed(seedIn)
 
    plaintext = ""
    for i in range(len(ciphertext)):
        letter = ciphertext[i]
        num = random.randint(0,len(alphabet) - 1 )
        shiftNum =  (alphabet.index(letter)- num) % (len(alphabet))
        OgLetter = alphabet[shiftNum]
        plaintext = plaintext + OgLetter

    return plaintext

#Analysis:
#The primary advantage of the Caesar Random Cipher is that it introduces an,
#element of randomness into the encryption process
#This randomness is based on the seed value, making it more secure than the classical Caesar cipher,
#which always shifts letters by a fixed amount.Because the shift value is generated randomly for each letter,
#it becomes much more challenging for an attacker to decrypt the message without knowing the correct seed value. 


#Just like the classical Caesar cipher, the Caesar Random Cipher can be broken through brute force if the seed value is unknown.
#An attacker would need to try all possible seed values, which is a very long and tedious process but possible for shorter messages or weak seeds.
