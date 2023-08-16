#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string T, P;
    getline(cin, T);
    getline(cin, P);
    int n = T.size();
    int m = P.size();

    int cnt = 0;
    for (int i = 0; i < n - m + 1; i++) {
        for (int j = 0; j < m; j++) {
            if (T[i + j] == P[j]) {
                if (j == m - 1) {
                    cnt++;
                    i += m - 1;
                }
            } else {
                break;
            }
        }
    }
    cout << cnt;
}