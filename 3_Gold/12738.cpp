#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[1'000'001];
vector<int> ord;

// ord[i] = 길이가 i인 가장 긴 증가하는 부분 수열을 만들 수 있는 마지막 원소의 최솟값
// ord.size() = 가장 긴 증가하는 부분 수열의 길이

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        auto pos = lower_bound(ord.begin(), ord.end(), arr[i]);
        if (pos == ord.end()) {
            ord.push_back(arr[i]);
        } else {
            *pos = arr[i];
        }
    }
    cout << ord.size();
}