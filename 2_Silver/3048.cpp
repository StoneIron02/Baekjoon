#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n1, n2;
  cin >> n1 >> n2;
  string s1, s2;
  cin >> s1 >> s2;
  vector<pair<char, bool>> arr;
  for (auto it = s1.rbegin(); it != s1.rend(); it++) {
    arr.emplace_back(*it, true);
  }
  for (auto it = s2.begin(); it != s2.end(); it++) {
    arr.emplace_back(*it, false);
  }

  int T;
  cin >> T;
  while (T--) {
    for (int i = 1; i < arr.size(); i++) {
      if (arr[i - 1].second && !arr[i].second) {
        auto tmp = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = tmp;
        i++;
      }
    }
  }

  for (auto& [ch, tmp] : arr) {
    cout << ch;
  }
}