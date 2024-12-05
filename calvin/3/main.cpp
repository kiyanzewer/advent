#include "../utils.h"
#include <iostream>
using namespace std;

int parseMultiplication(string input) {
  vector<string> tokens = split(input, ",");
  return stoi(tokens[0]) * stoi(tokens[1]);
}

bool validateEquation(string input) {
  for (auto c : input) {
    if (!isdigit(c) && c != ',') {
      return false;
    }
  }
  return true;
}

void part1() {
  string file_path = "./input.txt";
  vector<string> lines = read_file(file_path);
  int ans = 0;

  for (auto line : lines) {
    vector<string> tokens = split(line, "mul(");
    for (auto str : tokens) {
      if (str.find(")") != string::npos) {
        string temp = str.substr(0, str.find(")"));
        if (temp == "") {
          continue;
        }
        if (validateEquation(temp)) {
          ans += parseMultiplication(temp);
        }
      }
    }
  }
  cout << "Answer: " << ans << endl;
}

void part2() {
  string file_path = "./input.txt";
  vector<string> lines = read_file(file_path);

  string doStr = "do()";
  string dontStr = "don't()";

  int ans = 0;
  bool doInstruction = true;

  for (auto line : lines) {
    vector<string> tokens = split(line, "mul(");
    for (auto str : tokens) {
      if (doInstruction && str.find(")") != string::npos) {
        string temp = str.substr(0, str.find(")"));
        if (validateEquation(temp)) {
          ans += parseMultiplication(temp);
        }
      }

      if (str.find(doStr) != string::npos) {
        doInstruction = true;
      } else if (str.find(dontStr) != string::npos) {
        doInstruction = false;
      }
    }
  }
  cout << "Answer: " << ans << endl;
}

int main() {
  part1();
  part2();
}