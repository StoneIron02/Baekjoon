#include <iostream>

using namespace std;

int arr[12];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i = 4; i <= 11; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }

    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        cout << arr[num] << "\n";
    }
}