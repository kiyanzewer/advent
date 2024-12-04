#Answer for day 1 advent of code

def main():

    print ("Day 1!")

    #Part 1

    #our two location arrays
    locations1 = []
    locations2 = []

    file_path = "../inputs/day1.txt"
    # Open the file and read lines into a list
    with open(file_path, "r") as file:

        # For each line
        for line in file:

            # Split each line into columns
            col1, col2 = line.split()

            #add the appropriate value to the correct locations array
            locations1.append(col1)
            locations2.append(col2)

    #Sort both arrays
    locations1.sort()
    locations2.sort()

    #answer integer
    locDiff = 0

    #Can loop through locations1 length because we know both lists are the same length
    for index in range(0, len(locations1)):
        currDiff =  abs((int(locations1[index]) - int(locations2[index])))
        locDiff += currDiff


    print ("The total difference between the two lists is: " + str(locDiff))

    #Part 2

    # sorting and stuff does not matter, so we can just leave the two lists as is.
    simScore = 0

    for val in locations1:

        #how many times does this appear in locations2?
        numFinds = 0
        for val2 in locations2:
            if val2 == val:
                numFinds += 1

        simScore += (int(val) * numFinds)


    print("The similarity score for these two lists is: " + str(simScore))
#calling method
main()