#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  unordered_map<long long, int> cnt;
  for (int i = 0; i < n; i++) {
    long long num;
    cin >> num;
    cnt[num]++;
  }

  while (cnt.size() < k) {
    vector<long long> eraseList;
    for (auto& [num, tmp] : cnt) {
      cout << num << " ";
      tmp--;
      k--;
      if (tmp == 0) {
        eraseList.push_back(num);
      }
    }
    for (auto& i : eraseList) {
      cnt.erase(i);
    }
  }

  for (auto& [num, tmp] : cnt) {
    cout << num << " ";
    tmp--;
    k--;
    if (!k) break;
  }
}