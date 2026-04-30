// Aim: To find two distinct pairs (a,b) and (c,d) such that a*b = c*d

// Name - ADITYA BHARDWAJ
// Section - D2
// Roll No - 07
// Course – B TECH
// Branch – CSE

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, pair<int, int>> mp;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int product = arr[i] * arr[j];

            if (mp.find(product) != mp.end()) {
                pair<int, int> p = mp[product];

                // Ensure all elements are distinct
                if (p.first != arr[i] && p.first != arr[j] &&
                    p.second != arr[i] && p.second != arr[j]) {

                    cout << p.first << " " << p.second << endl;
                    cout << arr[i] << " " << arr[j] << endl;
                    return 0;
                }
            } else {
                mp[product] = {arr[i], arr[j]};
            }
        }
    }

    cout << "No such pairs found" << endl;
    return 0;
}