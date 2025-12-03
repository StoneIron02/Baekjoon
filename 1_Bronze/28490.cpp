#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int h, w;
    cin >> h >> w;
    int area = h * w;
    if (area > ans) ans = area;
  }
  cout << ans;
}