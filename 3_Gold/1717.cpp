#include <iostream>

using namespace std;

int n, m;
int parent[1'000'001];

void initialize() {
    for (int i = 0; i <= n; i++)
        parent[i] = i;
}

int find(int cur) {
    if (parent[cur] != cur)
        parent[cur] = find(parent[cur]);
    return parent[cur];
}

void union_set(int a, int b) {
    int aParent = find(a);
    int bParent = find(b);

    if (aParent < bParent)
        parent[bParent] = aParent;
    else if (aParent > bParent)
        parent[aParent] = bParent;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    initialize();
    for (int i = 0; i < m; i++) {
        int op;
        int a, b;
        cin >> op >> a >> b;

        if (op == 0)
            union_set(a, b);
        else {
            int aParent = find(a);
            int bParent = find(b);
            if (aParent == bParent)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}