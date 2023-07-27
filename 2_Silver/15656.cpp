#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
int selectNum[8];

void backtracking(int cur) {
    if (cur == m) {
        for (int i = 0; i < m; i++)
            cout << selectNum[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        selectNum[cur] = arr[i];
        backtracking(cur + 1);
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

    backtracking(0);
}