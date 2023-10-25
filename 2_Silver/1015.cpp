#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[50];
int result[50];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[i] = {num, i};
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        int origin = arr[i].second;
        result[origin] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
}