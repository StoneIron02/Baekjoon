#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        priority_queue<int, vector<int>, less<>> max_heap;
        priority_queue<int, vector<int>, greater<>> min_heap;
        multiset<int, greater<>> max_removes;
        multiset<int, less<>> min_removes;
        int num_inserts = 0;

        int k;
        cin >> k;
        while (k--) {
            string op;
            cin >> op;
            int num;
            cin >> num;
            if (op == "I") {
                max_heap.push(num);
                min_heap.push(num);
                num_inserts++;
            } else {
                if (!num_inserts) {
                    continue;
                }
                int delVal;
                if (num == 1) {
                    delVal = max_heap.top();
                } else {
                    delVal = min_heap.top();
                }
                max_removes.insert(delVal);
                min_removes.insert(delVal);
                num_inserts--;
                while (!max_heap.empty() && max_heap.top() == *max_removes.begin()) {
                    max_heap.pop();
                    max_removes.erase(max_removes.begin());
                }
                while (!min_heap.empty() && min_heap.top() == *min_removes.begin()) {
                    min_heap.pop();
                    min_removes.erase(min_removes.begin());
                }
            }
        }

        while (!max_heap.empty() && max_heap.top() == *max_removes.begin()) {
            max_heap.pop();
            max_removes.erase(max_removes.begin());
        }
        while (!min_heap.empty() && min_heap.top() == *min_removes.begin()) {
            min_heap.pop();
            min_removes.erase(min_removes.begin());
        }

        if (max_heap.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << max_heap.top() << " " << min_heap.top() << "\n";
        }
    }
}