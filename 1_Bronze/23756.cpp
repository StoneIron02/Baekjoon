#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, prev;
  cin >> N >> prev;

  int res = 0;
  for (int i = 0; i < N; ++i) {
    int next;
    cin >> next;

    int diff = abs(next - prev);
    int rotation = min(diff, 360 - diff);

    res += rotation;
    prev = next;
  }

  cout << res;
}