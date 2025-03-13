#Ayishat Oguntade
#Homework 3_1 Python Lists
#Due sep 25 11:55pm

#Get the data from users
num_golfers = int(input("How many golfers are in the tournament?"))

#Make a list to store data
golfer_score= []

#Initalize counter
i = 0

#Make a loop to get data 10 times and add the information to the list

for i in range(num_golfers):
    golfer_entries = int(input("Enter two-day score for golfer " + str(i +1 ) + ": "))
    golfer_score.append(golfer_entries)

#Get the cut off score from the user

cut_score = int(input("Enter the cut-off score: "))

# Find and remove the golfers who didnt make the cut due to the cut off score

new_golfer_scores = []
for i in range(len(golfer_score)):
    if golfer_score[i] < cut_score:
        new_golfer_scores.append(golfer_score[i])
    

#Find the percentage and print the result
#Calculate the percentage of golfers who made the cut
#Make a statement to print something if no golfers made the cut
        
if len(new_golfer_scores) == 0:
    print("No golfers made the cut")
else:
    percent = (len(new_golfer_scores) / num_golfers) * 100
    print("The percent of golfers that made the cut is" , percent,"%.")
