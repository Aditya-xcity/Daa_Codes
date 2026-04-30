/*Question: Given an array of characters, find distinct characters and their frequency using hashing.

 Aim: To count frequency of characters using hashing (array) and print them in alphabetical order.




*/
/*
Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    char arr[n];
    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int freq[26] = {0};

    for (int i = 0; i < n; i++)
    {
        freq[arr[i] - 'a']++;
    }

    cout << "Output:\n";
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            char ch = 'a' + i;
            cout << ch << " " << freq[i] << endl;
        }
    }

    return 0;
}