# Linear Search

# Given: A list of names, a list of phone numbers and a phone number to search for

# Get the lists
listSize = int(input("How many names in the list? "))
nameList = []
phoneList = []
for i in range(listSize):
    name = input("Name: ")
    phone = input("Phone: ")
    nameList = nameList + [name]
    phoneList = phoneList + [phone]

print(nameList, phoneList)

# Get phone number to search for

num = input("Enter number to search for: ")

# Search the list until the phone number is found

i = 0
found = 0
while i < listSize and found == 0:
    if phoneList[i] == num:
        found = 1
        foundIndex = i
    i = i + 1

# Print the name associated with the phone number
if found == 0:
    print("Phone number not found")
else:
    print("Phone number belongs to nameList[foundIndex])
    
