#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {

    int queryCount;

    cin >> queryCount;

    set<int> setNumbers;

    for(int i = 0;i < queryCount; i++){
        int option, number;
        cin >> option >> number;
        
        switch(option){
            case 1:
                setNumbers.insert(number);
                break;
            case 2:
                setNumbers.erase(number);
                break;
            case 3:
                if(setNumbers.find(number) != setNumbers.end()){
                    cout << "Yes\n";
                } else {
                    cout << "No\n";
                }
                break;
        }
    }

    return 0;
}
