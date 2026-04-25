// Write a C++ program to select maximum number of non-conflicting activities

/*
Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish, index;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cin >> n;

    vector<int> start(n), finish(n);

    for(int i = 0; i < n; i++)
        cin >> start[i];

    for(int i = 0; i < n; i++)
        cin >> finish[i];

    vector<Activity> activities(n);

    for(int i = 0; i < n; i++) {
        activities[i] = {start[i], finish[i], i + 1};
    }

   
    sort(activities.begin(), activities.end(), compare);

    vector<int> selected;

    
    selected.push_back(activities[0].index);
    int lastFinish = activities[0].finish;

    for(int i = 1; i < n; i++) {
        if(activities[i].start >= lastFinish) {
            selected.push_back(activities[i].index);
            lastFinish = activities[i].finish;
        }
    }

    
    cout << "No. of non-conflicting activities: " << selected.size() << endl;
    cout << "List of selected activities: ";

    for(int i = 0; i < selected.size(); i++) {
        cout << selected[i];
        if(i != selected.size() - 1)
            cout << ", ";
    }

    return 0;
}