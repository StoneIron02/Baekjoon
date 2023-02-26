#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str, ',');
        nums[i] = stoi(str);
    }

    for (int cnt = 0; cnt < k; cnt++, n--) {
        for (int i = 0; i < n - 1; i++) {
            nums[i] = nums[i + 1] - nums[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << nums[i];
        if (i < n - 1)
            cout << ",";
    }
}