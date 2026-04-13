// Question: Minimum Cost File Merging using Greedy Algorithm (Min Heap)

// Name - ADITYA BHARDWAJ
// Section - D2
// Roll No - 07
// Course – B TECH
// Branch – CSE

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of files: ";
    cin >> n;

    // Min heap (priority queue)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    cout << "Enter file sizes:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        minHeap.push(x);
    }

    int totalCost = 0;

    // Keep merging two smallest files until one file remains
    while (minHeap.size() > 1) {
        // Pick two smallest
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();

        int mergeCost = first + second;
        totalCost += mergeCost;

        // Push merged file back
        minHeap.push(mergeCost);
    }

    cout << "\nMinimum computation cost: " << totalCost << "\n";

    return 0;
}