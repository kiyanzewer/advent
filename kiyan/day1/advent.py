# Read
with open('inputs.txt', 'r') as file:
    one, two = zip(*((int(x), int(y)) for x, y in (line.strip().split() for line in file)))

# Sort
one = sorted(one)
two = sorted(two)

# Find sum
sum = sum(abs(i - j) for i, j in zip(one, two))

print(sum)