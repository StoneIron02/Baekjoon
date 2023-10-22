#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int cnt = 0;
    int w = m;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (w + num > m) {
            cnt++;
            w = 0;
        }
        w += num;
    }
    cout << cnt;
}