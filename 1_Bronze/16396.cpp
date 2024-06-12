#include <iostream>

using namespace std;

bool draw[10001];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    for (int i = x; i < y; i++) {
      draw[i] = true;
    }
  }
  int cnt = 0;
  for (int i = 1; i < 10000; i++) {
    if (draw[i]) cnt++;
  }
  cout << cnt;
}