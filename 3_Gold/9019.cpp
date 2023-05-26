#include <iostream>
#include <queue>

using namespace std;

int dist[10001];

string BFS(int s, int d) {
    queue<pair<int, string>> queue;
    for (int i = 0; i <= 10000; i++)
        dist[i] = INT32_MAX;
    dist[s] = 0;
    queue.push({s, ""});

    while (!queue.empty()) {
        auto top = queue.front();
        queue.pop();
        auto num = top.first;
        auto op = top.second;

        if (num == d)
            return op;

        // D
        int dNum = (num * 2) % 10000;
        string dOp = op + "D";
        if (dist[dNum] > dist[num] + 1) {
            dist[dNum] = dist[num] + 1;
            queue.push({dNum, dOp});
        }

        // S
        int sNum = (num - 1 + 10000) % 10000;
        string sOp = op + "S";
        if (dist[sNum] > dist[num] + 1) {
            dist[sNum] = dist[num] + 1;
            queue.push({sNum, sOp});
        }

        // L
        int lNum = (num % 1000) * 10 + (num / 1000);
        string lOp = op + "L";
        if (dist[lNum] > dist[num] + 1) {
            dist[lNum] = dist[num] + 1;
            queue.push({lNum, lOp});
        }

        // R
        int rNum = (num / 10) + (num % 10) * 1000;
        string rOp = op + "R";
        if (dist[rNum] > dist[num] + 1) {
            dist[rNum] = dist[num] + 1;
            queue.push({rNum, rOp});
        }
    }
    return "";
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        cout << BFS(a, b) << "\n";
    }
}