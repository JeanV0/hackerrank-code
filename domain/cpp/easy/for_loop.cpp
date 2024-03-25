#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main() {

    int start;
    int end;

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

    cin >> start >> end;

    for(int i = start;i <= end; i++ ){
        if(1 <= i && i <= 9){
            map<int, string>::iterator it = numberMap.find(i);
            if (it != numberMap.end()) cout << it->second << '\n';
        } else if(i >= 10) {
            if(i%2 == 0) {
                cout << "even\n";
            } else {
                cout << "odd\n";
            }
        }
    }

    return 0;
}