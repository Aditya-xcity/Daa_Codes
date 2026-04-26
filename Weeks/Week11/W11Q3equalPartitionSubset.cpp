
/*
Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    
    if (sum % 2 != 0) {
        cout << "no";
        return 0;
    }

    int target = sum / 2;

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    if (dp[target])
        cout << "yes";
    else
        cout << "no";

    return 0;
}