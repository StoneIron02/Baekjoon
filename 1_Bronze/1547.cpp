#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int arr[4];
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a == b)
            continue;
        arr[0] = arr[a];
        arr[a] = arr[b];
        arr[b] = arr[0];
    }
    for (int i = 1; i <= 3; i++) {
        if (arr[i] == 1)
            cout << i;
    }
}