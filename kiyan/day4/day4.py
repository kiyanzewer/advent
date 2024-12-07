with open('input.txt', 'r') as file:
    grid = [line.strip() for line in file.readlines()]

rows = len(grid)
cols = len(grid[0])
count_part1 = 0
count_part2 = 0 

for i in range(rows):
    for j in range(cols):
        # part 1
        if j + 3 < cols and grid[i][j] == 'X' and grid[i][j+1] == 'M' and grid[i][j+2] == 'A' and grid[i][j+3] == 'S':  # Horizontal Right
            count_part1 += 1
        if j - 3 >= 0 and grid[i][j] == 'X' and grid[i][j-1] == 'M' and grid[i][j-2] == 'A' and grid[i][j-3] == 'S':  # Horizontal Left
            count_part1 += 1
        if i + 3 < rows and grid[i][j] == 'X' and grid[i+1][j] == 'M' and grid[i+2][j] == 'A' and grid[i+3][j] == 'S':  # Vertical Down
            count_part1 += 1
        if i - 3 >= 0 and grid[i][j] == 'X' and grid[i-1][j] == 'M' and grid[i-2][j] == 'A' and grid[i-3][j] == 'S':  # Vertical Up
            count_part1 += 1
        if i + 3 < rows and j + 3 < cols and grid[i][j] == 'X' and grid[i+1][j+1] == 'M' and grid[i+2][j+2] == 'A' and grid[i+3][j+3] == 'S':  # Diagonal Down Right
            count_part1 += 1
        if i + 3 < rows and j - 3 >= 0 and grid[i][j] == 'X' and grid[i+1][j-1] == 'M' and grid[i+2][j-2] == 'A' and grid[i+3][j-3] == 'S':  # Diagonal Down Left
            count_part1 += 1
        if i - 3 >= 0 and j + 3 < cols and grid[i][j] == 'X' and grid[i-1][j+1] == 'M' and grid[i-2][j+2] == 'A' and grid[i-3][j+3] == 'S':  # Diagonal Up Right
            count_part1 += 1
        if i - 3 >= 0 and j - 3 >= 0 and grid[i][j] == 'X' and grid[i-1][j-1] == 'M' and grid[i-2][j-2] == 'A' and grid[i-3][j-3] == 'S':  # Diagonal Up Left
            count_part1 += 1

        # part 2
        # M A S M S
        if i + 2 < rows and j + 2 < cols and grid[i][j] == 'M' and grid[i+1][j+1] == 'A' and grid[i+2][j+2] == 'S' and grid[i+2][j] == 'M' and grid[i][j+2] == 'S':
            count_part2 += 1

        # M A S S M
        if i + 2 < rows and j + 2 < cols and grid[i][j] == 'M' and grid[i+1][j+1] == 'A' and grid[i+2][j+2] == 'S' and grid[i+2][j] == 'S' and grid[i][j+2] == 'M':
            count_part2 += 1

        # S A M M S
        if i + 2 < rows and j + 2 < cols and grid[i][j] == 'S' and grid[i+1][j+1] == 'A' and grid[i+2][j+2] == 'M' and grid[i+2][j] == 'M' and grid[i][j+2] == 'S':
            count_part2 += 1
        
        # S A M S M
        if i + 2 < rows and j + 2 < cols and grid[i][j] == 'S' and grid[i+1][j+1] == 'A' and grid[i+2][j+2] == 'M' and grid[i+2][j] == 'S' and grid[i][j+2] == 'M':
            count_part2 += 1

# Output the result for both parts
print(count_part1)
print(count_part2)
