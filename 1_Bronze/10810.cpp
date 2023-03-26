#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int ball[101] {0};
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int start, end, k;
        cin >> start >> end >> k;
        for (int j = start; j <= end; j++) {
            ball[j] = k;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ball[i] << " ";
    }
}