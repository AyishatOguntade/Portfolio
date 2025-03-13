#Ayishat Oguntade
#Homework 3_3 Python Lists
#Due Sep 25 11:55pm

#Get the amount of golf scores collected

num_of_scores = int(input("How many golf scores have you collected?"))

#Make a list to store the scores

golf_scores= []

#Make the program ask the user the abount of times needed for each score
#Initalize counter
i = 0

for i in range(num_of_scores):
    golf_scores_entries = int(input("Enter score:"))
    golf_scores.append(golf_scores_entries)



#Get and store sample rate k

sample_rate = int(input("Enter sample rate (k):"))

#Do something that has to do with the golf_scores and the sameple rate ????
#Most likley need to store scores

sampled_scores = []
x = 0

while len(golf_scores) > x:
    sampled_scores.append(golf_scores[x])
    x = x + sample_rate
    

#Print the sampled scores

print("The sampled scores are:")
print(sampled_scores)

