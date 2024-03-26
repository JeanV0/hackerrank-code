#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int size, query;
    cin >> size;

    vector<int> numbers(size);
    for(int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    cin >> query;

    for(int i = 0; i < query; i++) {
        int numberToFind;
        cin >> numberToFind;

        int index = lower_bound(numbers.begin(), numbers.end(), numberToFind) - numbers.begin();
        if (index < size && numbers[index] == numberToFind) {
            cout << "Yes " << index + 1 << endl;
        } else {
            int majorNumber = 0;
            for (int j = 0; j < size; j++) {
                if (numbers[j] > numberToFind) {
                    majorNumber = j + 1;
                    break;
                }
            }
            cout << "No " << majorNumber << endl;
        }
    }

    return 0;
}
