def openFile():
    while True:
        try:
            fname = input("Please enter the name of the data file (e.g., cs-grads.csv): ")
            with open(fname, 'r') as gradFile:
                return gradFile.readlines()
        except FileNotFoundError:
            print("Invalid file name, try again...")

def getData(lines):
    yearList = []
    femList = []

    # Skip the header line
    header = lines[0]
    lines = lines[1:]

    for line in lines:
        year, fem, _ = line.strip().split(',')
        yearList.append(int(year))
        femList.append(int(fem))

    return yearList, femList

def getYearLinear(yearList, femList, year):
    position = -1  # Initialize position to -1 (not found)
    comparisons = 0

    for i in range(len(yearList)):
        comparisons += 1  # Increment comparison count
        if year == yearList[i]:
            position = i
            break

    print("Linear Search Comparisons:", comparisons)
    return position

def getYearBinary(yearList, femList, year):
    left = 0
    right = len(yearList) - 1
    position = -1  # Initialize position to -1 (not found)
    comparisons = 0

    while left <= right:
        comparisons += 1  # Increment comparison count
        mid = (left + right) // 2
        if yearList[mid] == year:
            position = mid
            break
        elif yearList[mid] < year:
            left = mid + 1
        else:
            right = mid - 1

    print("Binary Search Comparisons:", comparisons)
    return position

def main():
    lines = openFile()
    yearList, femList = getData(lines)

    year = int(input("Enter a year to search: "))
    
    linear_position = getYearLinear(yearList, femList, year)
    binary_position = getYearBinary(yearList, femList, year)

    if linear_position != -1:
        print(f"Linear Search: In {year}, there were {femList[linear_position]} women CS graduates.")
    else:
        print(f"Linear Search: Year {year} not found in the data.")

    if binary_position != -1:
        print(f"Binary Search: In {year}, there were {femList[binary_position]} women CS graduates.")
    else:
        print(f"Binary Search: Year {year} not found in the data.")

if __name__ == "__main":
    main()
