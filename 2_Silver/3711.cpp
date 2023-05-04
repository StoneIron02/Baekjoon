#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int g;
        cin >> g;
        set<int> nums;
        for (int i = 0; i < g; i++) {
            int num;
            cin >> num;
            nums.insert(num);
        }
        for (int m = 1; m < 1000000; m++) {
            vector<bool> mods(m);
            bool flag = true;
            for (auto num : nums) {
                if (mods[num % m]) {
                    flag = false;
                    break;
                }
                mods[num % m] = true;
            }
            if (flag) {
                cout << m << "\n";
                break;
            } else {
                continue;
            }
        }
    }
}