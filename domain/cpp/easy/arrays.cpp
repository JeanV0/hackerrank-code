#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size;
    cin >> size;
    vector<int> numbers;
    for(int i = 0; i < size; i++){
        int number;
        cin >> number;
        numbers.push_back(number);
    } 

    numbers.resize(size);
    reverse(numbers.begin(),numbers.end());
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) 
        cout << *it << " "; 
    return 0;
}
