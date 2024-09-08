#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int cnt = 0;
  for (int a = 1; a <= 500; a++) {
    for (int b = 1; b <= 500; b++) {
      if (a * a == b * b + n) {
        cnt++;
      }
    }
  }
  cout << cnt;
}