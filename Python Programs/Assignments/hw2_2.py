#Ayishat Oguntade
#Due: Sep 18 at 11:55
#Programming in Python

#Get the number of toys in the catolog

num_toys = int(input("How many toys are in the catalog?"))

#Get the price total

total_price  = 0


# Ask them to enter each price of the toys
# Make the statement repeat for the number of items in the catalog 


for i in range(num_toys):
    price_toys = float(input("Enter toy price $"))
    i+1
    total_price = total_price + price_toys

# Calculate the average price

if num_toys > 0:
    averagePrice= total_price / num_toys 
    print("The average price of toys in the catalog is: $ " ,round(averagePrice, 2))





