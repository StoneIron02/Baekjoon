#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  int min_time = 999999999;

  for (int i = 0; i < n; ++i) {
    int t, l;
    cin >> t >> l;
    min_time = min(min_time, t + l);
  }

  cout << min_time;
}