#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void printMaxOfSubarrays(int arr[], int n, int k) {
    deque<int> dq;

    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        
        dq.push_back(i);
    }

    for (int i = k; i < n; i++) {
        cout << arr[dq.front()] << " ";

        // Remove elements that are outside the current window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        
        // Remove elements smaller than the current element from the back
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        
        dq.push_back(i);
    }

    cout << arr[dq.front()] << endl; // Print the maximum of the last window
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        printMaxOfSubarrays(arr, n, k);
    }
    return 0;
}
