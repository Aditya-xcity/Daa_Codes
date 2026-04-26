
/*
Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n + 1);

    
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> p[i + 1];
    }

    
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));

    
    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }

    cout << m[1][n];

    return 0;
}