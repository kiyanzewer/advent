#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "../utils.h"
using namespace std;

const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const char WALL = '#';

vector<vector<char>> grid;
int rows, cols;
pair<int, int> startPos;
int startDirection;

void loadGrid(vector<string> &input) {
  rows = input.size();
  cols = input[0].size();
  grid = vector<vector<char>>(rows, vector<char>(cols));

  startDirection = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      grid[i][j] = input[i][j];
      if (input[i][j] == '^') {
        startPos = {i, j};
      }
    }
  }
}

bool isValidPosition(int x, int y) {
  return x >= 0 && x < rows && y >= 0 && y < cols;
}

int countDistinctPositions() {
  set<pair<int, int>> visited;
  pair<int, int> current = startPos;
  int direction = startDirection;

  while (true) {
    visited.insert(current);

    pair<int, int> next = {current.first + DIRECTIONS[direction].first,
                           current.second + DIRECTIONS[direction].second};

    if (!isValidPosition(next.first, next.second)) {
      break;
    }

    if (grid[next.first][next.second] == WALL) {
      direction = (direction + 1) % 4;
    } else {
      current = next;
    }
  }

  return visited.size();
}

bool wouldCreateLoop(const vector<vector<char>> &testGrid) {
  pair<int, int> current = startPos;
  int direction = startDirection;
  set<pair<pair<int, int>, int>> visited;

  while (true) {
    auto state = make_pair(current, direction);

    if (visited.count(state)) {
      return true;
    }

    visited.insert(state);

    pair<int, int> next = {current.first + DIRECTIONS[direction].first,
                           current.second + DIRECTIONS[direction].second};

    // Check if next position is outside grid
    if (!isValidPosition(next.first, next.second)) {
      break;
    }

    if (testGrid[next.first][next.second] == WALL) {
      direction = (direction + 1) % 4;
    } else {
      current = next;
    }
  }

  return false;
}

int countLoopPositions() {
  int loopPositions = 0;

  for (int x = 0; x < rows; ++x) {
    for (int y = 0; y < cols; ++y) {
      // Skip the starting position
      if (x == startPos.first && y == startPos.second)
        continue;

      // Try blocking this position
      if (grid[x][y] == '.') {
        vector<vector<char>> testGrid = grid;
        testGrid[x][y] = WALL;

        if (wouldCreateLoop(testGrid)) {
          loopPositions++;
        }
      }
    }
  }

  return loopPositions;
}

int main() {
  string inputFile = "input.txt";
  // string inputFile = "small_input.txt";

  vector<string> input = read_file(inputFile);
  loadGrid(input);

  int distinctPositions = countDistinctPositions();
  cout << "Part 1: " << distinctPositions << endl;

  int loopPositions = countLoopPositions();
  cout << "Part 2: " << loopPositions << endl;

  return 0;
}