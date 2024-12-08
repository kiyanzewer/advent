#include "../utils.h"

#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

int ROWS;
int COLS;
vector<vector<char>> grid;

bool validPoint(int x, int y) {
  return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}

void part1() {
  // string file_path = "./small_input.txt";
  string file_path = "./input.txt";

  vector<string> lines = read_file(file_path);
  ROWS = lines.size();
  COLS = lines[0].size();

  // Globals
  vector<vector<char>> grid(ROWS, vector<char>(COLS));
  unordered_map<char, vector<pair<int, int>>> points;

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      grid[i][j] = lines[i][j];
      char sym = grid[i][j];
      if (sym != '.') {
        points[sym].push_back({i, j});
      }
    }
  }

  set<pair<int, int>> antinodes;

  // Print results
  for (const auto &[key, val] : points) {
    for (int i = 0; i < val.size(); i++) {
      for (int j = i + 1; j < val.size(); j++) {
        int x1 = val[i].first, y1 = val[i].second;
        int x2 = val[j].first, y2 = val[j].second;
        int x_before, x_after, y_before, y_after;

        // Vertical Line
        if (x2 == x1) {
          int step = y2 - y1;

          x_before = x1;
          x_after = x2;
          y_before = y1 - step; // Move in y direction
          y_after = y2 + step;  // Move in y direction

        } else {

          // Regular: y = mx + b
          float slope = (float)(y2 - y1) / (x2 - x1);

          float intercept = y1 - slope * x1;
          int step = x2 - x1; // Step size

          x_before = x1 - step; // Extend backwards
          x_after = x2 + step;  // Extend forwards
          y_before = round(slope * x_before + intercept);
          y_after = round(slope * x_after + intercept);
        }

        // Check if points are valid
        if (validPoint(x_before, y_before)) {
          antinodes.insert({x_before, y_before});
        }
        if (validPoint(x_after, y_after)) {
          antinodes.insert({x_after, y_after});
        }
      }
    }
  }

  cout << "Antinodes Size: " << antinodes.size() << endl;
}

void part2() {
  // string file_path = "./small_input.txt";
  string file_path = "./input.txt";

  vector<string> lines = read_file(file_path);
  ROWS = lines.size();
  COLS = lines[0].size();

  // Globals
  vector<vector<char>> grid(ROWS, vector<char>(COLS));
  unordered_map<char, vector<pair<int, int>>> points;

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      grid[i][j] = lines[i][j];
      char sym = grid[i][j];
      if (sym != '.') {
        points[sym].push_back({i, j});
      }
    }
  }

  set<pair<int, int>> antinodes;

  // Print results
  for (const auto &[key, val] : points) {
    for (int i = 0; i < val.size(); i++) {
      for (int j = i + 1; j < val.size(); j++) {
        int x1 = val[i].first, y1 = val[i].second;
        int x2 = val[j].first, y2 = val[j].second;

        if (x2 == x1) {
          // Vertical line case
          int step = y2 - y1;
          int current_y = y1;

          // Extend upwards
          while (validPoint(x1, current_y)) {
            antinodes.insert({x1, current_y});
            current_y -= step;
          }

          // Extend downwards
          current_y = y2;
          while (validPoint(x1, current_y)) {
            antinodes.insert({x1, current_y});
            current_y += step;
          }

        } else {
          // Regular line case: y = mx + b
          float slope = (float)(y2 - y1) / (x2 - x1);
          float intercept = y1 - slope * x1;

          int step = x2 - x1;
          int current_x = x1;

          // Extend leftwards
          while (validPoint(current_x, round(slope * current_x + intercept))) {
            int current_y = round(slope * current_x + intercept);
            antinodes.insert({current_x, current_y});
            current_x -= step;
          }

          // Extend rightwards
          current_x = x2;
          while (validPoint(current_x, round(slope * current_x + intercept))) {
            int current_y = round(slope * current_x + intercept);
            antinodes.insert({current_x, current_y});
            current_x += step;
          }
        }
      }
    }
  }

  cout << "Antinodes Size: " << antinodes.size() << endl;
}

int main() {
  part1();
  part2();
}
