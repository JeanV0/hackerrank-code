#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string input) {
    stringstream ss(input);
	char ch = ' ';
    vector<int> integers;
    string token;

    while(std::getline(ss, token, ',')) {
        integers.push_back(stoi(token));
    }

    return integers;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}