// Question:
// Given an already sorted array of positive integers, design an algorithm and implement it
// to find whether a given key element is present using Jump Search. Also count comparisons.

/*
Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

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

        int key;
        cin >> key;

        int comparisons = 0;
        int i = 0;

   
        while (i < n && arr[i] < key) {
            comparisons++;
            i += 2;
        }

        int start = i - 2;
        if (start < 0) start = 0;

        int end = (i < n) ? i : n - 1;

        bool found = false;

     
        for (int j = start; j <= end; j++) {
            comparisons++;
            if (arr[j] == key) {
                found = true;
                break;
            }
        }

        if (found)
            cout << "Present " << comparisons << endl;
        else
            cout << "Not Present " << comparisons << endl;
    }

    return 0;
}
