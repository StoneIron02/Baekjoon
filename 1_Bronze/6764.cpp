#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int arr[4];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    if (arr[0] < arr[1] && arr[1] < arr[2] && arr[2] < arr[3]) {
        cout << "Fish Rising";
    }
    else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] > arr[3]) {
        cout << "Fish Diving";
    }
    else if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3]) {
        cout << "Fish At Constant Depth";
    }
    else {
        cout << "No Fish";
    }
}