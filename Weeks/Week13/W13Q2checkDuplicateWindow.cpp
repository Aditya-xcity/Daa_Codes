// Aim: To check whether an array contains duplicate elements within a window of size k

// Name - ADITYA BHARDWAJ
// Section - D2
// Roll No - 07
// Course – B TECH
// Branch – CSE

#include <bits/stdc++.h>
using namespace std;

bool checkDuplicate(int arr[], int n, int k) {
    unordered_set<int> window;

    for (int i = 0; i < n; i++) {
        if (window.find(arr[i]) != window.end()) {
            return true;
        }

        window.insert(arr[i]);

        if (window.size() > k) {
            window.erase(arr[i - k]);
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int k;
        cin >> k;

        if (checkDuplicate(arr, n, k)) {
            cout << "Duplicate present in window " << k << endl;
        } else {
            cout << "Duplicate not present in window " << k << endl;
        }
    }

    return 0;
}