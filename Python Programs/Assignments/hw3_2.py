#Ayishat Oguntade
#Homework 3_2 Python Lists
#Due sep 25 11:55pm

#Get the data from users
num_golfers = int(input("How many golfers are in the tournament?"))

#Make a list to store score and names 
golfer_score= []
golfer_name= []
lowest_score = 1000000000000000000
lowest_score_name = ""

#Initalize counter
i = 0


#Make a loop to get data and add the information to the list

for i in range(num_golfers):
    golfer_name_entires = input("Enter name of golfer " + str(i+1) + ":")
    golfer_name.append(golfer_name_entires)

    golfer_score_entries = int(input("Enter score for golfer " + str(i +1) + ":"))
    golfer_score.append(golfer_score_entries)
#Get the leader aka the lowest score and name     
    if golfer_score_entries < lowest_score:
        lowest_score = golfer_score_entries
        lowest_score_name = golfer_name_entires
        

#Print both values
print("The current leader of the tournament is" ,lowest_score_name,"with a score of",lowest_score)

