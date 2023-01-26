#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> lectures(n);
    for (int i = 0; i < n; i++) {
        int no, start, end;
        cin >> no >> start >> end;
        lectures[i] = {start, end};
    }
    sort(lectures.begin(), lectures.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (pair<int, int> lecture : lectures) {
        if (pq.empty()) {
            pq.push({lecture.second, lecture.first});
            continue;
        }

        if (pq.top().first <= lecture.first) {
            pq.pop();
        }
        pq.push({lecture.second, lecture.first});
    }
    cout << pq.size();
}