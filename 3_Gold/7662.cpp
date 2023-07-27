#include <iostream>
#include <queue>
#include <map>
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
        map<int, int> removes_max;
        map<int, int> removes_min;
        int size = 0;

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
                size++;
            } else {
                if (!size) {
                    continue;
                }
                int delVal;
                if (num == 1) {
                    delVal = max_heap.top();
                } else {
                    delVal = min_heap.top();
                }
                removes_max[delVal]++;
                removes_min[delVal]++;
                size--;

                while (!max_heap.empty() && removes_max[max_heap.top()] > 0) {
                    int top = max_heap.top();
                    max_heap.pop();
                    removes_max[top]--;
                }
                while (!min_heap.empty() && removes_min[min_heap.top()] > 0) {
                    int top = min_heap.top();
                    min_heap.pop();
                    removes_min[top]--;
                }
            }
        }

        while (!max_heap.empty() && removes_max[max_heap.top()] > 0) {
            int top = max_heap.top();
            max_heap.pop();
            removes_max[top]--;
        }
        while (!min_heap.empty() && removes_min[min_heap.top()] > 0) {
            int top = min_heap.top();
            min_heap.pop();
            removes_min[top]--;
        }

        if (max_heap.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << max_heap.top() << " " << min_heap.top() << "\n";
        }
    }
}