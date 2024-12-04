safe = 0
with open('input.txt', 'r') as file:
    for line in file:
        numbers = [int(i) for i in line.strip().split()]

        # Check for duplicates
        if len(numbers) != len(set(numbers)):
            continue
        
        # Check that diff between each item is 1-3
        if any(abs(numbers[i] - numbers[i - 1]) > 3 for i in range(1, len(numbers))):
            continue
        
        # Check if the list is all increasing or decreasing
        if numbers == sorted(numbers) or numbers == sorted(numbers, reverse=True):
            safe += 1

print(safe)