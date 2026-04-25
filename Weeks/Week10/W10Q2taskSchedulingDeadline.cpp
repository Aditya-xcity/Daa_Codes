

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
#include <queue>
using namespace std;

struct Task {
    int time, deadline, index;
};

bool compare(Task a, Task b) {
    return a.deadline < b.deadline;
}

int main() {
    int n;
    cin >> n;

    vector<int> time(n), deadline(n);

    for(int i = 0; i < n; i++)
        cin >> time[i];

    for(int i = 0; i < n; i++)
        cin >> deadline[i];

    vector<Task> tasks(n);

    for(int i = 0; i < n; i++) {
        tasks[i] = {time[i], deadline[i], i + 1};
    }

    
    sort(tasks.begin(), tasks.end(), compare);

    priority_queue<pair<int, int>> pq; 
    int currentTime = 0;

    for(int i = 0; i < n; i++) {
        currentTime += tasks[i].time;
        pq.push({tasks[i].time, tasks[i].index});

        
        if(currentTime > tasks[i].deadline) {
            currentTime -= pq.top().first;
            pq.pop();
        }
    }

    
    vector<int> selected;

    while(!pq.empty()) {
        selected.push_back(pq.top().second);
        pq.pop();
    }

    sort(selected.begin(), selected.end());

    
    cout << "Max number of tasks = " << selected.size() << endl;
    cout << "Selected task numbers : ";

    for(int i = 0; i < selected.size(); i++) {
        cout << selected[i];
        if(i != selected.size() - 1)
            cout << ", ";
    }

    return 0;
}