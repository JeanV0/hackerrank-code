#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> make_vector(int numbers){
    vector<int> temp;

    for(int i = 0; i < numbers ; i++){
        int input;
        cin >> input;
        temp.push_back(input);
    }

    return temp;
}

int main() {

    vector<vector<int>> vetor;

    int size, search;

    cin >> size >> search;

    for (int i = 0; i < size; i++) {
        int size_line;
        cin >> size_line;
        vetor.push_back(make_vector(size_line));
    }

    for (auto i = 0; i < search ; i++){
        int index, variable_index;
        cin >> index >> variable_index;
        auto index_vetor = vetor[index];
        cout << index_vetor[variable_index] << endl;
    }

    return 0;
}