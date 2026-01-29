/*
Question:
Given an unsorted array of integers, sort the array by dividing it into two subarrays
and combining them after sorting. Also find the number of comparisons and inversions.

Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

#include <iostream>
using namespace std;

long long comparisons = 0;
long long inversions = 0;

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        comparisons++;
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int x = left; x <= right; x++)
        arr[x] = temp[x];
}

void mergeSort(int arr[], int temp[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int arr[n], temp[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        comparisons = 0;
        inversions = 0;

        mergeSort(arr, temp, 0, n - 1);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "inversions = " << inversions << endl;
    }

    return 0;
}
