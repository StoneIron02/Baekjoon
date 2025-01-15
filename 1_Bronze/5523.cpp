#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int cnt[2] {0, 0};
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (a > b) cnt[0]++;
    else if (a < b) cnt[1]++;
  }
  cout << cnt[0] << " " << cnt[1];
}