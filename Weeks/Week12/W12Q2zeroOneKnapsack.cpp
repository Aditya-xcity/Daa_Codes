// Question: Given a knapsack of maximum capacity W, find the list of selected items such that total weight <= W and total value is maximum (0/1 Knapsack).

// Aim: To implement 0/1 Knapsack using Dynamic Programming and also print selected items.

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
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]],
                               dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum value: " << dp[n][W] << endl;

    // Backtracking to find selected items
    int w = W;
    cout << "Selected items (index-based): ";

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i - 1 << " ";
            w -= wt[i - 1];
        }
    }

    cout << endl;

    return 0;
}