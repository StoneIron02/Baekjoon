#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int matrix[101][101];

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int a = x1; a <= x2; a++) {
            for (int b = y1; b <= y2; b++) {
                matrix[a][b]++;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (matrix[i][j] > m) {
                cnt++;
            }
        }
    }
    cout << cnt;
}