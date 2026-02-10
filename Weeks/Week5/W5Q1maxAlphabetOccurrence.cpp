// Question: Find the alphabet with maximum occurrences using counting sort
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        char ch;
        int count[26] = {0};

        for (int i = 0; i < n; i++) {
            cin >> ch;
            count[ch - 'a']++;
        }

        int maxCount = 0;
        char maxChar = '\0';

        for (int i = 0; i < 26; i++) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                maxChar = i + 'a';
            }
        }

        if (maxCount == 1) {
            cout << "No Duplicates Present" << endl;
        } else {
            cout << maxChar << " - " << maxCount << endl;
        }
    }

    return 0;
}
