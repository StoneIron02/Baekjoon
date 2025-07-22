#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int cnt = 0;

  for (int i = 1; i <= N; ++i) {
    int left1 = N - i;
    for (int j = i + 2; j <= left1; ++j) {
      int left2 = left1 - j;
      if (left2 <= 0) continue;
      if (left2 % 2 == 1) continue;
      ++cnt;
    }
  }

  cout << cnt;
}