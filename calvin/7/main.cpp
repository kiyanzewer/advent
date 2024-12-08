#include "../utils.h"
#include <iostream>
using namespace std;

bool recur( long answer, long curr, vector<string> &vars, int index) {
    if ( curr > answer ) { return false; }
    if ( index == vars.size() ) {
        return answer == curr;
    }
    long nextVal = stol(vars[index]);
    return recur(answer, curr * nextVal, vars, index + 1) || 
           recur(answer, curr + nextVal, vars, index + 1);
}

bool recurConcat( long answer, string curr, vector<string> &vars, int index ) {
    if ( stol(curr) > answer ) {
        return false;
    }
    if ( index == vars.size() ) {
        return answer == stol(curr);
    }
    string add = to_string(stol(curr) + stol(vars[index]));
    string mul = to_string(stol(curr) * stol(vars[index]));
    string concat = curr + vars[index];

    return recurConcat(answer, add, vars, index + 1) ||
    recurConcat(answer, mul, vars, index + 1) ||
    recurConcat(answer, concat, vars, index + 1);
}

void part1() {
  // string file_path = "./small_input.txt";
  string file_path = "./input.txt";
  vector<string> lines = read_file(file_path);

  long sumOfValues = 0;

  for (const string &s : lines) {
    vector<string> equation = split(s, ": ");

    long answer = stol(equation[0]);
    vector<string> vars = split(equation[1], " ");

    long curr = stol(vars[0]);
    if ( recur( answer, curr, vars, 1)) {
        sumOfValues += answer;
    }
  }
  cout << "Sum of Valid Equations: " << sumOfValues << endl;
}

void part2() {
  // string file_path = "./small_input.txt";
  string file_path = "./input.txt";
  vector<string> lines = read_file(file_path);

  long sumOfValues = 0;

  for (const string &s : lines) {
    vector<string> equation = split(s, ": ");

    long answer = stol(equation[0]);
    vector<string> vars = split(equation[1], " ");

    if ( recurConcat( answer, vars[0], vars, 1)) {
        sumOfValues += answer;
    }
  }
  cout << "Sum of Valid Equations: " << sumOfValues << endl;
}

int main() {
  // part1();
  part2();
}
