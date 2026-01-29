/*
Question:
Sort an array using Randomized Quick Sort.
Also find the number of comparisons and swaps.

Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

long long comparisons = 0;
long long swapsCount = 0;

void swapElements(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    swapsCount++;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swapElements(arr[i], arr[j]);
        }
    }
    swapElements(arr[i + 1], arr[high]);
    return i + 1;
}

int randomPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swapElements(arr[randomIndex], arr[high]);
    return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(0));

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        comparisons = 0;
        swapsCount = 0;

        quickSort(arr, 0, n - 1);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "swaps = " << swapsCount << endl;
    }

    return 0;
}
