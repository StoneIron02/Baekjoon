#include <iostream>

using namespace std;

int matrix[50][50];
int answer[50][50];

void change(int r, int c) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[r + i][c + j] == 0)
                matrix[r + i][c + j] = 1;
            else
                matrix[r + i][c + j] = 0;
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num = cin.get() - '0';
            matrix[i][j] = num;
        }
        cin.ignore();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num = cin.get() - '0';
            answer[i][j] = num;
        }
        cin.ignore();
    }

    int cnt = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (matrix[i][j] != answer[i][j]) {
                change(i, j);
                cnt++;
            }
        }
    }

    bool flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != answer[i][j]) {
                flag = false;
                break;
            }
        }
    }
    if (flag)
        cout << cnt;
    else
        cout << -1;
}