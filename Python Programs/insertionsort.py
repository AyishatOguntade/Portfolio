def insertionSort(theList):
    # Step 1: Initial state
    print(f"Initial state: {theList}")

    for i in range(1, len(theList)):
        save = theList[i]
        j = i

        # Step 2: Inside the outer loop (i={i})
        print(f"\nOuter Loop (i={i}):")
        print(f"  save = {save}")
        print(f"  Sublist: {theList[:i]} | Unsorted: {theList[i:]}")

        while j > 0 and theList[j - 1] > save:
            # Step 3: Inside the inner loop
            print(f"\n  Inner Loop (j={j}):")
            print(f"    Comparing {theList[j - 1]} > {save}")
            
            # Comparison: Swap elements
            theList[j] = theList[j - 1]
            j = j - 1

            # Swap
            print(f"    Swapped: {theList}")
        
        # Swap
        theList[j] = save
        print(f"\n  Sublist after sorting: {theList[:i+1]} | Unsorted: {theList[i+1:]}")
    
    # Step 4: Final sorted list
    print(f"\nFinal sorted list: {theList}")
    return theList

# Example usage
insertionSort([5, 3, 6, 2, 1, 4])
