#include <iostream>
#include <set>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string n_str;
    cin >> n_str;
    set<int> nums;
    for (char c : n_str) {
        nums.insert(c - '0');
    }
    nums.erase(0);

    long long result = stoll(n_str);
    if (all_of(nums.begin(), nums.end(), [&result](int i) { return result % i == 0; })) {
        cout << result;
        return 0;
    }
    int limit = 10;
    int limitCnt = 1;
    while (true) {
        for (int i = 0; i < limit; i++) {
            string i_str = to_string(i);
            i_str = string(limitCnt - i_str.size(), '0') + i_str;
            long long cur = stoll(n_str + i_str);
            if (all_of(nums.begin(), nums.end(), [&cur](int i) { return cur % i == 0; })) {
                cout << cur;
                return 0;
            }
        }
        limit *= 10;
        limitCnt++;
    }

}