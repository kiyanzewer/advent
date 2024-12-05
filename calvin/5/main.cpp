#include <iostream>
#include <map>
#include "../utils.h"
using namespace std;

void parseRules( map<int,vector<int>> &rules, string rule ) {
    vector<string> parts = split(rule, "|");
    int key = stoi(parts[0]);
    int val = stoi( parts[1]);
    rules[key].push_back(val);
}

bool validOrdering( map<int, vector<int>> &rulesMap, vector<string> &order ) {
    for ( int i = 0; i < order.size(); i++ ) {
        for ( int j = i + 1; j < order.size(); j++ ) {
            vector<int> rules = rulesMap[stoi(order[i])];
            if (find( rules.begin(), rules.end(), stoi(order[j])) == rules.end() ) {
                return false;
            }
        }
    }
    return true;
}

int fixOrdering( map<int, vector<int>> &rulesMap, vector<string> &order ) {
    for ( int i = 0; i < order.size(); i++ ) {
        for ( int j = i + 1; j < order.size(); j++ ) {
            vector<int> rules = rulesMap[stoi(order[i])];
            if (find( rules.begin(), rules.end(), stoi(order[j])) == rules.end() ) {
                swap( order[i], order[j] );
                j -= 1;
            }
        }
    } 
    return stoi(order[order.size()/2]);;
}

void part1() {
    string file_path = "./input.txt";
    vector<string> lines = read_file(file_path);

    map<int, vector<int>> rulesMap;
    vector<string> pageOrdering;
    bool rules = true;
    for ( const string& s: lines ) {
        if ( s == "" ) {
            rules = false;
            continue;
        }
        if ( rules ) { 
            parseRules(rulesMap, s);
        }
        else {
            pageOrdering.push_back(s);
        }
    }

    int answer = 0;
    for ( string page: pageOrdering ) {
        vector<string> order = split( page, "," );
        if (validOrdering(rulesMap, order)) {
            answer += stoi(order[order.size()/2]);
        }
    }
    cout << "Answer: " << answer << endl;
}

void part2() {
    string file_path = "./input.txt";
    vector<string> lines = read_file(file_path);

    map<int, vector<int>> rulesMap;
    vector<string> pageOrdering;
    bool rules = true;
    for ( const string& s: lines ) {
        if ( s == "" ) {
            rules = false;
            continue;
        }
        if ( rules ) { 
            parseRules(rulesMap, s);
        }
        else {
            pageOrdering.push_back(s);
        }
    }

    int answer = 0;
    for ( string page: pageOrdering ) {
        vector<string> order = split( page, "," );
        if (!validOrdering(rulesMap, order)) {
            answer += fixOrdering(rulesMap, order);
        }
    }
    cout << "Answer: " << answer << endl;
}

int main() {
    part1();
    part2();
}
