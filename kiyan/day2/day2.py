def is_safe(numbers):
    # Check for dupes
    if len(numbers) != len(set(numbers)):
        return False
    # Diff is between 1 and 3
    if any(abs(numbers[i] - numbers[i - 1]) > 3 for i in range(1, len(numbers))):
        return False
    # Check for all increase or decreasing
    return numbers == sorted(numbers) or numbers == sorted(numbers, reverse=True)

safe_part_1 = 0
safe_part_2 = 0

with open('input.txt', 'r') as file:
    for line in file:
        # Separate lines
        numbers = [int(i) for i in line.strip().split()]

        if is_safe(numbers):
            safe_part_1 += 1
            safe_part_2 += 1
        else:
            # Part 2
            safe_found = False
            for i in range(len(numbers)):
                new_numbers = numbers[:i] + numbers[i+1:]
                if is_safe(new_numbers):
                    safe_part_2 += 1
                    safe_found = True
                    break
            if safe_found:
                continue

print(f"Part 1: {safe_part_1}")
print(f"Part 2: {safe_part_2}")