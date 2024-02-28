#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, h;
vector<int> arr[2];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n >> h;
  for (int i = 1; i <= n; i++) {
    int num;
    cin >> num;
    arr[i % 2].push_back(num);
  }

  sort(arr[0].begin(), arr[0].end());
  sort(arr[1].begin(), arr[1].end());

  int minVal = INT_MAX;
  int minValCnt = 0;
  for (int i = 1; i <= h; i++) {
    int cnt1 = lower_bound(arr[1].begin(), arr[1].end(), i) - arr[1].begin();
    int cnt0 = lower_bound(arr[0].begin(), arr[0].end(), h - i + 1) - arr[0].begin();
    int val = arr[1].size() + arr[0].size() - cnt0 - cnt1;
    if (minVal > val) {
      minVal = val;
      minValCnt = 0;
    }
    if (minVal == val) {
      minValCnt++;
    }
  }

  cout << minVal << " " << minValCnt;
}