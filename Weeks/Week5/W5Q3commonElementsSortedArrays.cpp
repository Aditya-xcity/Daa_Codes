// Question: Find common elements in two sorted arrays using O(m+n)


#include <iostream>
using namespace std;

int main() {
    int m, n;

    cout << "Enter size of first array: ";
    cin >> m;

    int arr1[m];
    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> n;

    int arr2[n];
    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    int i = 0, j = 0;
    bool found = false;

    cout << "Common elements are: ";

    while (i < m && j < n) {
        if (arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            found = true;
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    if (!found) {
        cout << "No Common Elements";
    }

    return 0;
}
