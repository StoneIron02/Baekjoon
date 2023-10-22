#include <iostream>
#include <vector>
#include <set>

using namespace std;

int parent[51];
vector<int> party[51];
set<int> known;

void init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootY] = rootX;
    }
}

bool check(int p) {
    for (auto i : party[p]) {
        for (auto num : known) {
            if (find(num) == find(i)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    init(n);

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        known.insert(num);
    }
    for (int p = 0; p < m; p++) {
        int c;
        cin >> c;
        int before;
        cin >> before;
        party[p].push_back(before);
        for (int i = 1; i < c; i++) {
            int cur;
            cin >> cur;
            party[p].push_back(cur);
            unionSets(before, cur);
            before = cur;
        }
    }

    int cnt = 0;
    for (int p = 0; p < m; p++) {
        bool flag = true;
        for (auto i : party[p]) {
            if (check(p)) {
                flag = false;
                break;
            } // 거짓말 불가
        }

        if (flag) {
            cnt++;
        }
    }

    cout << cnt;
}