#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int nums[8];
int selectNum[8];

void backtracking(int cur) {
    if (cur == m) {
        for (int i = 0; i < m; i++) {
            cout << selectNum[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        selectNum[cur] = nums[i];
        backtracking(cur + 1);
        while (i + 1 < n && nums[i + 1] == selectNum[cur])
            i++;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    backtracking(0);
}