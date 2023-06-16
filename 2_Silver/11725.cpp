#include <iostream>
#include <vector>

using namespace std;

int n;
int parent[100'001];
vector<int> adjacent[100'001];

void find(int cur, int pre) {
    parent[cur] = pre;
    for (auto v : adjacent[cur]) {
        if (v == pre)
            continue;
        find(v, cur);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }

    find(1, -1);
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << "\n";
    }
}