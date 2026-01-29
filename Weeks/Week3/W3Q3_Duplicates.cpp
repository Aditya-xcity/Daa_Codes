// II. Given an unsorted array of positive integers, design an algorithm and implement it using a
// program to find whether there are any duplicate elements in the array or not. (use sorting)
// Name - ADITYA BHARDWAJ
// Section - D2
// Roll No - 07
// Course – B TECH
// Branch – CSE

#include <iostream>
#include <algorithm>
using namespace std;

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

        sort(arr, arr + n);

        bool hasDuplicate = false;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                hasDuplicate = true;
                break;
            }
        }

        if (hasDuplicate)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
