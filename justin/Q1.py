list1 = []
list2 = []
with open('D1-Input.txt', 'r') as file:
    for line in file:
        parts = line.split()
        if len(parts) == 2:
            list1.append(parts[0])
            list2.append(parts[1])
list1.sort()
list2.sort()
i = 0
distances = []
for x in list1:
    distances.append(abs(int(x) - int(list2[i])))
    i+=1
print(sum(distances))

#part 2
similarities = []
for x in list1:
    count = 0
    for y in list2:
        if x == y:
            count += 1
        if int(y) > int(x):
            break 
    similarities.append(int(x) * count)       
print(sum(similarities))