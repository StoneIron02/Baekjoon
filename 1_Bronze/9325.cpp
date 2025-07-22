#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;

  while (T--) {
    int s;
    cin >> s;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
      int q, p;
      cin >> q >> p;
      s += q * p;
    }

    cout << s << '\n';
  }
}