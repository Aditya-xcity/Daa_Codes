/*Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case.

Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE*/

#include <iostream>
using namespace std;

int main()
{
    int n, key;
    int comparisons = 0;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter key element to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    bool found = false;

    while (low <= high)
    {
        comparisons++;
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            found = true;
            break;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (found)
        cout << "Key element found.\n";
    else
        cout << "Key element not found.\n";

    cout << "Total comparisons: " << comparisons << endl;

    return 0;
}
