#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }

    for (int query = 0; query < m; query++) {
        int i, j, k;
        cin >> i >> j >> k;
        int temp[n + 1];
        for (int index = 1; index <= n; index++) {
            temp[index] = arr[index];
        }

        int pointer = i;
        for (int index = k; index <= j; index++) {
            temp[pointer++] = arr[index];
        }
        for (int index = i; index < k; index++) {
            temp[pointer++] = arr[index];
        }

        for (int index = 1; index <= n; index++) {
            arr[index] = temp[index];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
}