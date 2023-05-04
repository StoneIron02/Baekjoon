#include <iostream>

using namespace std;

int sum[100'001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }
    for (int i = 1; i <= m; i++) {
        int start, end;
        cin >> start >> end;
        cout << (sum[end] - sum[start - 1]) << "\n";
    }
}