#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1'000'000];
int L[1'000'000];

int LIS() {
    int len = 0;
    for (int i = 0; i < n; i++) {
        auto pos = lower_bound(L, L + len, arr[i]);
        if (pos == L + len)
            len++;
        L[pos - L] = arr[i];
    }
    return len;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << LIS();
}