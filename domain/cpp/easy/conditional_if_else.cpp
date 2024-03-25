#include <bits/stdc++.h>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int main()
{
    string n_temp;
    getline(cin, n_temp);

    map<int, string> numberMap = {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {0, "zero"}
    };

    int n = stoi(ltrim(rtrim(n_temp)));

    if(9 < n){
        cout << "Greater than 9" << '\n';
        return 0;  
    } else {
        map<int, string>::iterator it = numberMap.find(n);
        if (it != numberMap.end()) cout << it->second << '\n';
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
