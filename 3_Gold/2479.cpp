#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, k;
string code[1001];
bool visit[1001];
int prePath[1001];
vector<int> edges[1001];

bool isHammingPath(string str1, string str2) {
    bool flag = false;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) {
            if (!flag)
                flag = true;
            else
                return false;
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> code[i];

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (isHammingPath(code[i], code[j])) {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }

    int a, b;
    cin >> a >> b;
    queue<int> queue;
    queue.push(a);
    visit[a] = true;
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        if (u == b)
            break;

        for (int v : edges[u]) {
            if (!visit[v]) {
                queue.push(v);
                visit[v] = true;
                prePath[v] = u;
            }
        }
    }

    if (!visit[b]) {
        cout << "-1";
        exit(0);
    }

    int v = b;
    stack<int> path;
    while (v != a) {
        path.push(v);
        v = prePath[v];
    }
    path.push(a);

    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
}