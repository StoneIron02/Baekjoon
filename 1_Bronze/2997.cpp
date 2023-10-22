#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int & i : arr)
        cin >> i;
    sort(arr, arr + 3);

    int d1 = arr[1] - arr[0];
    int d2 = arr[2] - arr[1];

    if (d1 == d2) {
        cout << arr[2] + d2;
    } else if (d1 * 2 == d2) {
        cout << arr[1] + d1;
    } else {
        cout << arr[0] + d2;
    }
}