#include <iostream>
#include <vector>

using namespace std;

int n;
long long value[123'457];
vector<int> edges[123'457];

long long DFS(int s) {
    long long sum = value[s];
    for (auto v : edges[s]) {
        sum += DFS(v);
    }
    if (sum < 0)
        sum = 0;
    return sum;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 2; i <= n; i++) {
        char t;
        long long a;
        int p;
        cin >> t >> a >> p;
        if (t == 'S') {
            value[i] = a;
        }
        if (t == 'W') {
            value[i] = -a;
        }
        edges[p].push_back(i);
    }

    cout << DFS(1);
}