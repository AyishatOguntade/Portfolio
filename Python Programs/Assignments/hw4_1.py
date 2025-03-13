#Ayishat Oguntade
#CSC 110 - Homework 4 - Working with Python Functions
#Due October 9 11:55

#Make the get toys function

def getToys():
    toys = []
    price = []
    num_sold = []

    num_toys = int(input("How many toys are in your catalog?"))
    

#Get the user to input the information the amount of num_toys 

    for i in range(num_toys):
        toy_name = input("Enter toy name:")
        toy_price = float(input("Enter toy price:"))
        toy_sold= int(input("Enter number sold:"))

        toys.append(toy_name)
        price.append(toy_price)
        num_sold.append(toy_sold)

    return toys,price,num_sold

#Make the search Toy function  

def searchToy(toys,search_name):
    
    for i in range(len(toys)):
        if toys[i] == search_name:
            return i
    return -1

#Make the sold more function

def soldMore(toys,num_sold,index):
    sold_more_toys = []
    
    for i in range(len(toys)):
        if i != index and num_sold[i] > num_sold[index]:
            sold_more_toys.append(toys[i])


    return sold_more_toys 

#Make the print results function

def printResults(index, toy_names, price, more_sold_toys):
    print("The price of", toy_names[index], " is ${:,.2f}".format(price[index]))

    if len(more_sold_toys) > 0 :
        print("The toys that have more sold than", toy_names[index] + " are:")

        for toy in more_sold_toys:
           print(toy)
    else:
        print("No toys have sold more than", toy_names[index])

#Make the main function where all this works

def main():
    toys, price, num_sold = getToys()
    search_name = input("Enter a toy to find the price of: ")
    index = searchToy(toys, search_name)

    if index != -1:
        more_sold_toys = soldMore(toys, num_sold, index)
        printResults(index, toys, price, more_sold_toys)
    else:
        print("The toy name you entered is not in our catalog.")



