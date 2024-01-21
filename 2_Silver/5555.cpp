#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string P;
  cin >> P;
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    string T;
    cin >> T;
    bool found = false;
    for (int t = 0; t < T.size(); t++) {
      T = T.substr(1) + T[0];
      for (int j = 0; j <= T.size() - P.size(); j++) {
        bool flag = true;
        for (int k = 0; k < P.size(); k++) {
          if (T[j + k] != P[k]) {
            flag = false;
            break;
          }
        }
        if (flag) {
          found = true;
        }
      }
    }
    if (found) {
      cnt++;
    }
  }
  cout << cnt;
}