#include <iostream>

using namespace std;

int n, s;
int arr[20];
int cnt = 0;

void backtracking(int cur, int sum, int select) {
    if (cur == n) {
        if (sum == s && select > 0) {
            cnt++;
        }
        return;
    }

    backtracking(cur + 1, sum + arr[cur], select + 1);
    backtracking(cur + 1, sum, select);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    backtracking(0, 0, 0);
    cout << cnt;
}