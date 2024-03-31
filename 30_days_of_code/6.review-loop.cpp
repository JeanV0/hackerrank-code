#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T, N;
    string word;

    cin >> T;

    for (int i = 0; i < T; i++) {
        string temp1, temp2, final; 

        cin >> word;
        N = word.size();
        for (int j = 0; j < N; j++) {
            if (j % 2 == 0)
                temp1.push_back(word[j]);
            else {
                temp2.push_back(word[j]);
            }
        }
        final = temp1 + " " + temp2;
        cout << final << endl;
    }

    return 0;
}