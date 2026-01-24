/*Given an array of nonnegative integers, design a linear algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)


Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key, int &comparisons)
{
    comparisons = 0;

    for (int i = 0; i < n; i++)
    {
        comparisons++;
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}


int main()
{
    int test;
    cout << "Please enter the number of test cases: ";
    cin >> test;

    while (test--)
    {
        int n, key;
        cout << "Please enter the number of elements in the array: ";
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cout << "Enter element " << i + 1 << ": ";
            cin >> arr[i];
        }

        cout << "Please enter the element to search: ";
        cin >> key;

        int comparisons = 0;
        int index = linearSearch(arr, n, key, comparisons);

        if (index != -1)
        {
            cout << "Element found at index: " << index << endl;
        }
        else
        {
            cout << "Element not found!" << endl;
        }

        cout << "Number of comparisons: " << comparisons << endl;

       
    }

    return 0;
}

