#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size;

    vector<int> numbers;

    cin >> size;

    for(int i = 0;i < size; i++){
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    int removeNumber;
    int range;

    cin >> removeNumber;

    numbers.erase(numbers.begin()+(removeNumber-1));

    cin >> removeNumber >> range;

    numbers.erase(numbers.begin()+(removeNumber-1), numbers.begin()+(range-1));

    cout << numbers.size() << endl;

    for(auto i: numbers){
        cout << i << " ";
    }

    return 0;
}
