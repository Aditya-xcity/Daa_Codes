/*
Question:
Find Kth smallest or largest element in an unsorted array
with worst case time complexity O(n)

Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

#include <iostream>
#include <algorithm>
using namespace std;

int findMedian(int arr[], int n) {
    sort(arr, arr + n);
    return arr[n / 2];
}

int partition(int arr[], int l, int r, int x) {
    int i;
    for (i = l; i <= r; i++) {
        if (arr[i] == x)
            break;
    }
    swap(arr[i], arr[r]);

    i = l;
    for (int j = l; j < r; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int kthSmallest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {

        int n = r - l + 1;
        int i;
        int median[(n + 4) / 5];

        for (i = 0; i < n / 5; i++)
            median[i] = findMedian(arr + l + i * 5, 5);

        if (i * 5 < n) {
            median[i] = findMedian(arr + l + i * 5, n % 5);
            i++;
        }

        int medOfMed = (i == 1) ? median[0]
                                : kthSmallest(median, 0, i - 1, i / 2);

        int pos = partition(arr, l, r, medOfMed);

        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);

        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }

    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int k;
        cin >> k;

        if (k <= 0 || k > n) {
            cout << "not present" << endl;
        } else {
            int result = kthSmallest(arr, 0, n - 1, k);
            cout << result << endl;
        }
    }
    return 0;
}
