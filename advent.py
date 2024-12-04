one = []
two = []
with open('inputs.txt', 'r') as file:
    for line in file:
        item1, item2 = line.strip.split()
        one.append(item1)
        two.append(item2)

print(one)
print(two)