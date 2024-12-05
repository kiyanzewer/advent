#include "../utils.h"
#include <vector>
#include <iostream>
using namespace std;

string KEYWORD = "XMAS";
vector<pair<int, int> > directions = {
    {0, 1},   // Right
    {0, -1},  // Left
    {1, 0},   // Down
    {-1, 0},  // Up
    {1, 1},   // Down-Right
    {-1, -1}, // Up-Left
    {1, -1},  // Down-Left
    {-1, 1}   // Up-Right
};

bool isValid(int x, int y, int ROW, int COL) {
    return x >= 0 && x < ROW && y >= 0 && y < COL;
}

bool checkWord(vector<vector<char>> &grid, int x, int y, int dx, int dy, string word) {
    int ROW = grid.size();
    int COL = grid[0].size();
    int n = word.size();

    for (int i = 0; i < n; i++) {
        if (!isValid(x, y, ROW, COL) || grid[x][y] != word[i]) {
            return false;
        }
        x += dx;
        y += dy;
    }
    return true;
}

bool checkGrid( vector<vector<char>> &grid, int x, int y ) {
    string downRight = string(1, grid[x][y]) + grid[x+1][y+1] + grid[x+2][y+2];
    string upRight = string(1,grid[x+2][y])+ grid[x+1][y+1] + grid[x][y+2];
    return (downRight == "SAM" || downRight == "MAS") && (upRight == "SAM" || upRight == "MAS");
}

int countWordOccurrences(vector<vector<char>> &grid, string word) {
    int count = 0;
    int ROW = grid.size();
    int COL = grid[0].size();

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            for (auto dir : directions) {
                if (checkWord(grid, i, j, dir.first, dir.second, word)) {
                    count++;
                }
            }
        }
    }
    return count;
}

int countXOccurrences( vector<vector<char>> &grid, string word ) {
    int count = 0;
    int ROW = grid.size();
    int COL = grid[0].size();

    for( int i = 0; i < ROW - 2; i++ ) {
        for ( int j = 0; j < COL - 2; j++ ) {
            if ( checkGrid( grid, i , j ) ) {
                count++;
            }
        }
    }

    return count;
}

void part1() {
    // string file_path = "./small_input.txt";
    string file_path = "./input.txt";
    vector<string> lines = read_file(file_path); 

    int ROW = lines.size();
    int COL = lines[0].size();
    vector<vector<char>> grid(ROW, vector<char>(COL));

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j] = lines[i][j];
        }
    }
    cout << "Number of XMAS Occurrences: " << countWordOccurrences(grid, KEYWORD) << endl;
}

void part2() {
    // string file_path = "./small_input.txt";
    string file_path = "./input.txt";
    vector<string> lines = read_file(file_path); 

    int ROW = lines.size();
    int COL = lines[0].size();
    vector<vector<char>> grid(ROW, vector<char>(COL));

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j] = lines[i][j];
        }
    }
    cout << "Number of X Occurrences: " << countXOccurrences(grid, KEYWORD) << endl;
}

int main() {
  part1();
  part2();
}
