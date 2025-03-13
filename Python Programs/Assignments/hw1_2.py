#Ayishat Oguntade
#Due 9/11/23
#Homework 1-2



#Grade Computation
homework_c = 0.4
midterm_c = 0.3
finalexam_c = 0.3

# Get grade from user

homework = float(input("Enter homework grade: "))
midterm = float(input("Enter midterm grade: "))
finalexam= float(input("Enter final exam grade: "))

# Compute the grades values

homework_g = homework * homework_c
midterm_g = midterm * midterm_c
finalexam_g = finalexam * finalexam_c

finalgrade= homework_g + midterm_g + finalexam_g

# Print Results
print("Your final grade is: ", round(finalgrade,2))
