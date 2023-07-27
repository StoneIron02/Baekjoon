#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int a, b;

int BFS() {
    queue<pair<int, int>> queue;
    queue.push({a, 1});

    while (!queue.empty()) {
        auto top = queue.front();
        queue.pop();

        auto num = top.first;
        auto cnt = top.second;

        if (num == b)
            return cnt;

        int x2 = num * 2;
        if (x2 <= b) {
            queue.push({x2, cnt + 1});
        }

        long long p1 = (long long)num * 10 + 1;
        if (p1 <= b) {
            queue.push({p1, cnt + 1});
        }
    }
    return -1;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> a >> b;
    cout << BFS();
}