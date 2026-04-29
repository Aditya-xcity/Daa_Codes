// Question: Given a string, print all permutations in lexicographic order.

// Aim: To generate all permutations of a string using recursion and backtracking in lexicographic order.

/*
Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

#include <iostream>
#include <algorithm>
using namespace std;

void generatePermutations(string &s, int index) {
    if (index == s.length()) {
        cout << s << endl;
        return;
    }

    for (int i = index; i < s.length(); i++) {
        
        bool shouldSwap = true;
        for (int j = index; j < i; j++) {
            if (s[j] == s[i]) {
                shouldSwap = false;
                break;
            }
        }

        if (shouldSwap) {
            swap(s[index], s[i]);
            generatePermutations(s, index + 1);
            swap(s[index], s[i]); 
        }
    }
}

int main() {
    string str;

    cout << "Enter string: ";
    cin >> str;

    sort(str.begin(), str.end()); 

    generatePermutations(str, 0);

    return 0;
}