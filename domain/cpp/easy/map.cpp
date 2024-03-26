#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int queryCount;
    cin >> queryCount;

    map<string, int> mapStudent;

    for (int i = 0; i < queryCount; i++) {
        int option, points;
        string name;
        cin >> option;

        switch (option) {
            case 1:
                cin >> name >> points;
                mapStudent[name] += points;
                break;
            case 2:
                cin >> name;
                mapStudent.erase(name); 
                break;
            case 3:
                cin >> name;
                cout << mapStudent[name] << endl;
                break;
        }
    }
    return 0;
}
