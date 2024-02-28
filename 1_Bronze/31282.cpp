#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;

  int rabbitDist = n, dogDist = 0;
  int cnt = 0;
  while (rabbitDist > dogDist) {
    rabbitDist += m;
    dogDist += k;
    cnt++;
  }
  cout << cnt;
}