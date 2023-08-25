#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);

    string str;
    cin >> str;
    cout << arr[str[0] - 'A'] << " " << arr[str[1] - 'A'] << " " << arr[str[2] - 'A'];
}