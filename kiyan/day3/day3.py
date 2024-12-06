import re

# Part 1
total = 0
with open('input.txt', 'r') as file:
    for line in file:
        line = line.strip()
        # regex to grab the numbers inside mul
        nums = re.findall(r'mul\((\d+),(\d+)\)', line)
        # loop through list of tuples and add the mult
        total += sum(int(val1) * int(val2) for val1, val2 in nums)
print(total)

# Part 2
total = 0
valid = True
with open('input.txt', 'r') as file:
    # iterate by line
    for line in file:
        # grab line
        line = line.strip()
        # regex for each mul, do, dont
        nums = re.findall(r'(mul\((\d+),(\d+)\)|don\'t\(\)|do\(\))', line)
        # loop through list of string, val1, val2
        for string, val1, val2 in nums:
            # if it says don't it is no longer valid so go until you find do
            if 'don\'t' in string:
                valid = False
                continue
            if 'do()' in string:
                valid = True
                continue
            # if valid and has both value then add the sum
            if valid and val1 and val2:
                total += int(val1) * int(val2)

print(total)