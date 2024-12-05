

def main():
    print("Day 2!")

    #Want to approach this one line by line and just have an undetermined sized 2d array
    file_path = "./inputs/day2.txt"

    array_xd = []
    # Open the file and read lines into a list
    with open(file_path, "r") as file:

        # For each line
        for line in file:

            #add the appropriate value to the correct locations array
            array_xd.append(line)


    #currently each slot in array_xd is unknown length. It is each line in the input
    #we like this

    #now we just need to check each index in array_xd and see if it meets the parameters

        #RULES
        #The levels are either all increasing or all decreasing.
        #Any two adjacent levels differ by at least one and at most three.


    #number of safe reports
    numSafe = 0

    print("==================================START========================================")
    #for each row in the report
    for report in array_xd:
            levelsInc = report.split()
            levelsDec = levelsInc.copy()
            numSafe += testInc(levelsInc, 0)
            numSafe += testDec(levelsDec, 0)
            
    print("The number of safe reports is " + str(numSafe))


#Helper function to test increasing reports
def testInc(levels, saves):

    #using 1 and zero so I can return that variable    

    safe = 1 
    index = 0

    #while this report is still safe and I am not out of bounds
    while safe == 1 and index < (len(levels) - 1):
         
        diff = int(levels[index]) - int(levels[index + 1])
        #if me - next > 0, we are not increasing. change safe and gtfo
        if ( diff >= 0 or diff < -3):

            #if we havent saved this jointer yet
            if (saves == 0):
                #remove this one, retry and see if it passes
                levels2 = levels.copy()
                del levels[index]

                #if trying again with the current level removed fixes it, ship it out
                if (testInc(levels, 1) == 1):
                    return 1
                #OTHERWISE try again but with the next one removed instead
                else:
                    del levels2[index + 1]
                    return testInc(levels2, 1)

            #If we have already saved this hoe, fail that bitch  
            else:
                safe = 0
                return safe

        index = index + 1

    return safe


#Helper function to test decreasing reports
def testDec(levels, saves):

    #using 1 and zero so I can return that variable

    safe = 1 
    index = 0

    #while this report is still safe and I am not out of bounds
    while safe == 1 and index < (len(levels) - 1):
         
        diff = int(levels[index]) - int(levels[index + 1])
        #if me - next > 0, we are not increasing. change safe and gtfo
        if ( diff <= 0 or diff > 3 ):

            #if we havent saved this jointer yet
            if (saves == 0):
                
                levels2 = levels.copy()
                del levels[index]

                #if trying again with the current level removed fixes it, ship it out
                if (testDec(levels, 1) == 1):
                    return 1
                #OTHERWISE try again but with the next one removed instead
                else:
                    del levels2[index + 1]
                    return testDec(levels2, 1)

            #If we have already saved this hoe, fail that bitch  
            else:
                safe = 0
                return safe

        index = index + 1

    return safe

main()