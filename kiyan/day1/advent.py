# Part 1

# Read
with open('inputs.txt', 'r') as file:
    one, two = zip(*((int(x), int(y)) for x, y in (line.strip().split() for line in file)))

# Sort
one = sorted(one)
two = sorted(two)

# Find sum
sum = sum(abs(i - j) for i, j in zip(one, two))

print(sum)

# Part 2
# Go through one first
occurrences_one = {}
for i in one:
    if i in occurrences_one:
        occurrences_one[i] += 1
    else:
        occurrences_one[i] = 1

# Calculate similarity
similarity = 0
for i in two:
    if i in occurrences_one:
        similarity += i * occurrences_one[i]

print(similarity)

