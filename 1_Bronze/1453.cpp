#include <iostream>

using namespace std;

int arr[101];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int cnt = 0;
    while (n--) {
        int num;
        cin >> num;
        if (arr[num])
            cnt++;
        else
            arr[num] = true;
    }
    cout << cnt;
}