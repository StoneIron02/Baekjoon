#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1'000'000];
int L[1'000'000];
int P[1'000'000];

void LIS_arr(int index, int num) {
    if (index < 0) return;
    if (P[index] == num) {
        LIS_arr(index - 1, num - 1);
        cout << arr[index] << " ";
    } else {
        LIS_arr(index - 1, num);
    }
}

int LIS() {
    int len = 0;
    for (int i = 0; i < n; i++) {
        auto index = lower_bound(L, L + len, arr[i]) - L;
        if (index == len)
            len++;
        L[index] = arr[i];
        P[i] = index;
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
    int len = LIS();
    cout << len << "\n";
    LIS_arr(n - 1, len - 1);
}