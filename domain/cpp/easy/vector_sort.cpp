#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int size;

    vector<int> sortVector;

    cin >> size;

    for(int i = 0; i < size; i++){
        int number;
        cin >> number;
        sortVector.push_back(number);
    }

    sort(sortVector.begin(),sortVector.end());

    cout << sortVector[0];

    for(int i = 1; i < size; i++){
        cout << " " << sortVector[i];
    }

    return 0;
}
