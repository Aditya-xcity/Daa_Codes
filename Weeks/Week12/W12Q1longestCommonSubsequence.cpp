// Question: Given two sequences, Design an algorithm and implement it using a program to find the length of longest subsequence present in both of them.

// Aim: To find the length of the Longest Common Subsequence (LCS) between two sequences using Dynamic Programming.

/*
Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    string seq1, seq2;

    cout << "Enter first sequence: ";
    cin >> seq1;

    cout << "Enter second sequence: ";
    cin >> seq2;

    int result = longestCommonSubsequence(seq1, seq2);

    cout << "Length of Longest Common Subsequence: " << result << endl;

    return 0;
}