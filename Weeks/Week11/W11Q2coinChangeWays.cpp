
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

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int target;
    cin >> target;

    vector<int> dp(target + 1, 0);

    
    dp[0] = 1;

    
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= target; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[target];

    return 0;
}