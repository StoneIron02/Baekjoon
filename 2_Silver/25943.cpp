#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int left, right;
  int n;
  cin >> n;
  cin >> left >> right;
  n -= 2;
  while (n--) {
    int num;
    cin >> num;
    if (left <= right) {
      left += num;
    } else {
      right += num;
    }
  }
  int diff = abs(right - left);
  int cnt = 0;

  cnt += diff / 100;
  diff %= 100;

  cnt += diff / 50;
  diff %= 50;

  cnt += diff / 20;
  diff %= 20;

  cnt += diff / 10;
  diff %= 10;

  cnt += diff / 5;
  diff %= 5;

  cnt += diff / 2;
  diff %= 2;

  cnt += diff;

  cout << cnt;
}