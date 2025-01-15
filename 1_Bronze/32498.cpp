#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    if (d % 2 != 0) {
      ++cnt;
    }
  }

  cout << cnt;

}