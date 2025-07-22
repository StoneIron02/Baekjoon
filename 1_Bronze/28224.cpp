#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, cur;
  cin >> n >> cur;
  for (int i = 1; i < n; ++i) {
    int diff;
    cin >> diff;
    cur += diff;
  }

  cout << cur;
}