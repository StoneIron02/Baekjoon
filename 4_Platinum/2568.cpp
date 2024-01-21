#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> arr(1);
vector<int> ord;
vector<int> indices(1);
set<int> result;

// ord[i] = 길이가 i인 가장 긴 증가하는 부분 수열을 만들 수 있는 마지막 원소의 최솟값
// ord.size() = 가장 긴 증가하는 부분 수열의 길이

void backtrace(int idx, int num) {
    if(idx == 0)
        return;
    if(indices[idx] == num) {
        backtrace(idx - 1, num - 1);
        result.insert(arr[idx].second);
    }
    else {
        backtrace(idx - 1, num);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end());

    for (int i = 1; i <= n; i++) {
        auto pos = lower_bound(ord.begin(), ord.end(), arr[i].second);
        if (pos == ord.end()) {
            ord.push_back(arr[i].second);
            indices.push_back(ord.size());
        } else {
            auto test = pos - ord.begin();
            *pos = arr[i].second;
            indices.push_back(pos - ord.begin() + 1);
        }
    }
    backtrace(n, ord.size());
    cout << (n - ord.size()) << "\n";
    for (int i = 1; i <= n; i++) {
        if (result.find(arr[i].second) == result.end()) {
            cout << arr[i].first << "\n";
        }
    }
}