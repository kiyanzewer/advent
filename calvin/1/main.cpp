#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../utils.h"
using namespace std;

void part1() {
  string file_path = "./input.txt";
  vector<string> lines = read_file(file_path);

  int distance = 0;
  vector<int> list1;
  vector<int> list2;

  for (const string &s : lines) {
    vector<string> tokens = split(s, "   ");
    for (int i = 0; i < tokens.size(); i++) {
      if (i == 0) {
        list1.push_back(stoi(tokens[i]));
      } else {
        list2.push_back(stoi(tokens[i]));
      }
    }
  }

  // Sort the two vectors
  sort(list1.begin(), list1.end());
  sort(list2.begin(), list2.end());

  while (!list1.empty()) {
    distance += abs(list1[0] - list2[0]);
    list1.erase(list1.begin());
    list2.erase(list2.begin());
  }
  cout << "Distance: " << distance << endl;
}

void part2() {
  // Create a freq dictionary of only list2 based on the values
  string file_path = "./input.txt";
  vector<string> lines = read_file(file_path);

  vector<int> list1;
  vector<int> list2;

  map<int, int> freq;

  for (const string &s : lines) {
    vector<string> tokens = split(s, "   ");
    for (int i = 0; i < tokens.size(); i++) {
      if (i == 0) {
        list1.push_back(stoi(tokens[i]));
      } else {
        freq[stoi(tokens[i])] += 1;
      }
    }
  }

  int simScore = 0;
  // Sim Score is list1[i] * freq[list2[i]]
  for (const int &i : list1) {
    if (freq.find(i) == freq.end()) {
      continue;
    }
    simScore += (i * freq[i]);
  }

  cout << "Sim Score: " << simScore << endl;
}

int main() {
  part1();
  part2();
}