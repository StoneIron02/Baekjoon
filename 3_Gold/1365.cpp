#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> lis;

    for (int i = 0; i < n; i++) {
        auto pos = lower_bound(lis.begin(), lis.end(), arr[i]);
        if (pos == lis.end()) {
            lis.push_back(arr[i]);
        } else {
            *pos = arr[i];
        }
    }
    cout << (n - lis.size());
}