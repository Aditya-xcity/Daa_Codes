

/*
Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    
    int candidate = -1, count = 0;

    for(int i = 0; i < n; i++) {
        if(count == 0) {
            candidate = arr[i];
            count = 1;
        } else if(arr[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    
    count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == candidate)
            count++;
    }

    if(count > n / 2)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    
    sort(arr.begin(), arr.end());

    int median = arr[n / 2]; 

    cout << median << endl;

    return 0;
}