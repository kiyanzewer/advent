#include <iostream>
#include "../utils.h"
using namespace std;

void part1() {
    string file_path = "./input.txt";
    vector<string> lines = read_file(file_path);

    for ( const string& s: lines ) {
        cout << s << endl;
    }
}

void part2() {
    string file_path = "./input.txt";
    vector<string> lines = read_file(file_path);

    for ( const string& s: lines ) {
        cout << s << endl;
    }
}

int main() {
    part1();
    part2();
}
