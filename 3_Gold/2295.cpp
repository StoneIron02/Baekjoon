#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];
int sum[1000000];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // x + y + z = k -> x + y = k - z
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum[idx++] = arr[i] + arr[j];
        }
    }
    sort(sum, sum + idx);

    int maxK = -1;
    for (int k = 0; k < n; k++) {
        for (int z = 0; z < n; z++) {
            int num = arr[k] - arr[z];
            if (binary_search(sum, sum + idx, num)) {
                maxK = max(maxK, num + arr[z]);
            }
        }
    }
    cout << maxK;
}