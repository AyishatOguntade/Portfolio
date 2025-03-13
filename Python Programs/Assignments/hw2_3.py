#Ayishat Oguntade
#Due: Sep 18 11:59
#Programming Concetps

#Initialize counter

i=1

#I was having trouble with this part therefore this is what I came up with when defining the min and max

max_r = 0
min_r = 100000000000000000000000000000000000000000000000000000000
while i<=12:
    rainfall = float(input("Rainfall for month" + str(i) + ":"))
    i=i+1
    if max_r < rainfall:
        max_r = rainfall
    if min_r > rainfall:
        min_r = rainfall

#Print the max and min values
        
print("The highest monthly rainfall was" ,max_r , "inches.")
print("The lowest monthly rainfall was", min_r, "inches.")
