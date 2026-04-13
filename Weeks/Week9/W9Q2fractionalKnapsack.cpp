// Question: Fractional Knapsack Problem (Greedy Algorithm)

// Name - ADITYA BHARDWAJ
// Section - D2
// Roll No - 07
// Course – B TECH
// Branch – CSE

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int index;
    int weight;
    int value;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;  // descending order of value/weight ratio
}

int main() {
    int N;
    cout << "Enter number of items: ";
    cin >> N;

    vector<Item> items(N);

    cout << "Enter weights:\n";
    for (int i = 0; i < N; i++) {
        items[i].index = i + 1;
        cin >> items[i].weight;
    }

    cout << "Enter values:\n";
    for (int i = 0; i < N; i++) {
        cin >> items[i].value;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    int W;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    // Sort by value/weight ratio descending
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int remaining = W;

    // Store selected items: {original index, weight taken}
    vector<pair<int,int>> selected;

    for (int i = 0; i < N && remaining > 0; i++) {
        if (items[i].weight <= remaining) {
            // Take full item
            selected.push_back({items[i].index, items[i].weight});
            totalValue += items[i].value;
            remaining -= items[i].weight;
        } else {
            // Take fraction
            totalValue += items[i].ratio * remaining;
            selected.push_back({items[i].index, remaining});
            remaining = 0;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nMaximum value : " << totalValue << "\n";

    cout << "item-weight\n";
    for (auto s : selected)
        cout << s.first << "-" << s.second << "\n";

    return 0;
}