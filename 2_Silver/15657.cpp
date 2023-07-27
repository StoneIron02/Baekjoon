#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
int selectNum[8];

void backtracking(int cur, int before) {
    if (cur == m) {
        for (int i = 0; i < m; i++)
            cout << selectNum[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] < before) continue;
        selectNum[cur] = arr[i];
        backtracking(cur + 1, selectNum[cur]);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    backtracking(0, -1);
}