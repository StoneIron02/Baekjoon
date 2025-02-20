#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  unordered_map<string, int> umap;

  for (int i = 0; i < n; i++) {
    string name;
    int cnt;
    cin >> name >> cnt;
    umap[name] += cnt;
  }

  vector<pair<string, int>> arr(umap.begin(), umap.end());

  sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
    if (a.first.size() != b.first.size()) {
      return a.first.size() < b.first.size();
    }
    return a.first < b.first;
  });

  for (const auto& p : arr) {
    cout << p.first << " " << p.second << "\n";
  }
}