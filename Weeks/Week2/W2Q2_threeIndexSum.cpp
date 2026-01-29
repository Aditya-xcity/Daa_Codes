/*Given a sorted array of positive integers, design an algorithm and implement it using a program
to find three indices i, j, k such that arr[i] + arr[j] = arr[k].

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

        bool found = false;

        for (int k = n - 1; k >= 2 && !found; k--)
        {
            int i = 0;
            int j = k - 1;

            while (i < j)
            {
                int sum = arr[i] + arr[j];

                if (sum == arr[k])
                {
                    cout << "Indices found: ";
                    cout << i << ", " << j << ", " << k << endl;
                    found = true;
                    break;
                }
                else if (sum < arr[k])
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }
        }

        if (!found)
        {
            cout << "No sequence found." << endl;
        }
    }

    return 0;
}
