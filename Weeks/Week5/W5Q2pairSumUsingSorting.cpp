// Question: Find whether two elements exist such that their sum equals the given key

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter key element: ";
    cin >> key;

    // Sort the array
    sort(arr, arr + n);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int left = 0, right = n - 1;
    bool found = false;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == key) {
            found = true;
            break;
        } else if (sum < key) {
            left++;
        } else {
            right--;
        }
    }

    if (found) {
        cout << "Pair Exists" << endl;
    } else {
        cout << "Pair Does Not Exist" << endl;
    }

    return 0;
}
