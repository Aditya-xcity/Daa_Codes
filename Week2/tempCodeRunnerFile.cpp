// Given an array of nonnegative integers, design an algorithm and a program to count the number
// of pairs of integers such that their difference is equal to a given key, K.

// Name - ADITYA BHARDWAJ
// Section - D2
// Roll No - 07
// Course – B TECH
// Branch – CSE

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    while (T--)
    {
        int n;
        cout << "Enter size of array: ";
        cin >> n;

        int arr[n];
        cout << "Enter array elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int K;
        cout << "Enter the key (K): ";
        cin >> K;

        sort(arr, arr + n);

        int i = 0, j = 1;
        int count = 0;

        while (i < n && j < n)
        {
            if (i != j && arr[j] - arr[i] == K)
            {
                count++;
                i++;
                j++;
            }
            else if (arr[j] - arr[i] < K)
            {
                j++;
            }
            else
            {
                i++;
                if (i == j)
                    j++;
            }
        }

        cout << "Number of pairs with difference " << K << " is: ";
        cout << count << endl;
    }

    return 0;
}
