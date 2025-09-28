#include <iostream>
#include <vector>
using namespace std;

int t[100];
int res[100];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> t[i];
  }

  int p = n;
  while (p > 0) {
    int want = 0;
    for (int i = 0; i < m; ++i) if (res[i] < t[i]) ++want;

    if (want == 0) break;

    if (p >= want) {
      for (int i = 0; i < m; ++i)
        if (res[i] < t[i]) ++res[i];
      p -= want;
    } else {
      for (int i = 0; i < m && p > 0; ++i) {
        if (res[i] < t[i]) {
          ++res[i];
          --p;
        }
      }
      break;
    }
  }

  for (int i = 0; i < m; ++i) {
    cout << res[i] << "\n";
  }
}