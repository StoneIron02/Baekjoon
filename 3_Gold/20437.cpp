#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    vector<int> idx[26];
    for (int i = 0; i < str.size(); i++) {
      idx[str[i] - 'a'].push_back(i);
    }

    int k;
    cin >> k;
    int m = 99999, M = -1;
    for (auto & c : idx) {
      if (c.size() >= k) {
        for (int i = 0; i < c.size() - k + 1; i++) {
          m = min(m, c[i + k - 1] - c[i] + 1);
          M = max(M, c[i + k - 1] - c[i] + 1);
        }
      }
    }
    if (M == -1) {
      cout << -1 << "\n";
    } else {
      cout << m << " " << M << "\n";
    }
  }
}