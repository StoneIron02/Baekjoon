#include <iostream>
#include <algorithm>

using namespace std;

int n;
int board[100'001][3];
int dp_m[2][3];
int dp_M[2][3];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> board[i][j];
    }

    dp_m[0][0] = 0;
    dp_m[0][1] = 0;
    dp_m[0][2] = 0;
    dp_M[0][0] = 0;
    dp_M[0][1] = 0;
    dp_M[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        dp_m[1][0] = min(dp_m[0][0], dp_m[0][1]) + board[i][0];
        dp_m[1][1] = min({dp_m[0][0], dp_m[0][1], dp_m[0][2]}) + board[i][1];
        dp_m[1][2] = min(dp_m[0][1], dp_m[0][2]) + board[i][2];
        dp_M[1][0] = max(dp_M[0][0], dp_M[0][1]) + board[i][0];
        dp_M[1][1] = max({dp_M[0][0], dp_M[0][1], dp_M[0][2]}) + board[i][1];
        dp_M[1][2] = max(dp_M[0][1], dp_M[0][2]) + board[i][2];

        dp_m[0][0] = dp_m[1][0];
        dp_m[0][1] = dp_m[1][1];
        dp_m[0][2] = dp_m[1][2];
        dp_M[0][0] = dp_M[1][0];
        dp_M[0][1] = dp_M[1][1];
        dp_M[0][2] = dp_M[1][2];
    }

    cout << max({dp_M[1][0], dp_M[1][1], dp_M[1][2]}) << " " << min({dp_m[1][0], dp_m[1][1], dp_m[1][2]});
}