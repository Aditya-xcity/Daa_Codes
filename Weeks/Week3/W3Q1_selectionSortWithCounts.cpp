// Given an unsorted array of integers, design an algorithm and implement a program to sort this
// array using selection sort.
// Name - ADITYA BHARDWAJ
// Section - D2
// Roll No - 07
// Course – B TECH
// Branch – CSE

#include <iostream>
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

        int comparisons = 0;
        int swaps = 0;

        // Selection Sort
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;

            for (int j = i + 1; j < n; j++) {
                comparisons++;
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            if (minIndex != i) {
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
                swaps++;
            }
        }

        // Output sorted array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "swaps = " << swaps << endl;
    }

    return 0;
}
