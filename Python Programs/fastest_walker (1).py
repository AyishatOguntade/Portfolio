# Given:  Distances and times for n walkers
# Find: Which walker is the fastest (by number)

# Get the number of walkers in the group

num_walkers = int(input("How many walkers in your group? "))

# Get the first distance and time

dist = float(input("Enter the distance for walker 1: "))
time = float(input("Enter the time for walker 1: "))

# Compute the speed

speed = dist/time

# Intialize counter for loop

i = 1

# Initialize the value for the highest speed

high_speed = speed
fastest_walker = 0

# Loop through to compute speeds and find the highest

while i < num_walkers:
    # Get the distance and time for the ith walker
    dist = float(input("Enter the distance: "))
    time = float(input("Enter the time: "))

    # Compute the speed for the ith walker
    speed = dist/time

    # Test to see if this speed is higher than the max speed so far

    if speed > high_speed:
        high_speed = speed
        fastest_walker = i

    # Increment counter

    i = i + 1

# Print the highest speed

print("The fastest speed in the walking group is: ",high_speed)
print("This is the speed of walker ", fastest_walker)


        

