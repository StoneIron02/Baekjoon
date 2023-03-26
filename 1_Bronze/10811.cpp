#include <iostream>

using namespace std;

int arr[2][101];
bool arrNum = 0;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int j = 1; j <= n; j++) {
        arr[arrNum][j] = j;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        bool curNum = arrNum;
        bool nextNum = !arrNum;
        for (int j = 1; j <= n; j++) {
            arr[nextNum][j] = arr[curNum][j];
        }
        for (int j = a, k = b; j <= b; j++, k--) {
            arr[nextNum][k] = arr[curNum][j];
        }
        arrNum = !arrNum;
    }
    for (int j = 1; j <= n; j++) {
        cout << arr[arrNum][j] << " ";
    }
}