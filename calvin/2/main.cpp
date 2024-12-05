#include "../utils.h"
#include <iostream>
using namespace std;

bool validReport(vector<string> report) {
  bool inc = stoi(report[0]) < stoi(report[1]);
  bool isValid = true;

  for (int i = 0; i < report.size() - 1; i++) {
    int curr = stoi(report[i]);
    int next = stoi(report[i + 1]);
    int diff = abs(curr - next);

    if (!(diff >= 1 && diff <= 3)) {
      isValid = false;
      break;
    }

    if (inc && curr < next) {
      continue;
    } else if (!inc && curr > next) {
      continue;
    } else {
      isValid = false;
      break;
    }
  }

  for (auto str : report) {
    cout << str << " ";
  }
  cout << isValid << endl;
  return isValid;
}

vector<string> newReport(vector<string> report, int i) {
  vector<string> newReport;
  for (int j = 0; j < report.size(); j++) {
    if (j == i) {
      continue;
    }
    newReport.push_back(report[j]);
  }
  return newReport;
}

void part1() {
  string file_path = "./input.txt";
  vector<string> lines = read_file(file_path);

  vector<vector<string>> reports;
  for (const string &s : lines) {
    vector<string> tokens = split(s, " ");
    reports.emplace_back(tokens);
  }

  int validReports = 0;
  for (auto report : reports) {
    if (validReport(report)) {
      validReports++;
    }
  }

  cout << "Valid reports: " << validReports << endl;
}

void part2() {
  string file_path = "./input.txt";
  vector<string> lines = read_file(file_path);

  vector<vector<string>> reports;
  for (const string &s : lines) {
    vector<string> tokens = split(s, " ");
    reports.emplace_back(tokens);
  }

  int validReports = 0;
  for (auto report : reports) {
    bool isValid = validReport(report);

    if (!isValid) {
      // Super Inefficient - O(n^2) for finding a bad spot ...
      for (int i = 0; i < report.size(); i++) {
        vector<string> updatedReport = newReport(report, i);
        if (validReport(updatedReport)) {
          isValid = true;
          break;
        }
      }
    }

    if (isValid) {
      validReports++;
    }
  }
  cout << "Valid reports: " << validReports << endl;
}

int main() {
  part1();
  part2();
}