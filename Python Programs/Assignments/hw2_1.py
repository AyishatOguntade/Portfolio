#Ayishat Oguntade
#Due: Sep. 18 at 11:59
#Programming in Python

#Create the variable to go get the final sale number from user

finalSale= float(input("Enter amount of sale $"))

#First step in calculating the discount 

discount1= finalSale * 0.3
discount2 = finalSale * 0.2
discount3 = finalSale * 0.1
discount4 = finalSale * 0.05

#Apply the discounts to the final sale number entered by the user

if finalSale > 600:
    finalSale = finalSale - discount1
elif finalSale <= 600 and finalSale > 300:
    finalSale = finalSale - discount2
elif finalSale <= 300 and finalSale > 100:
    finalSale = finalSale -  discount3

else:
    finalSale = finalSale -  discount4

#Display the final amount 

print("The final sale amount is $", "{:,.2f}".format(finalSale))
