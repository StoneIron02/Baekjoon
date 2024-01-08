#include <iostream>
using namespace std;

bool visit[1'000'000];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  if (n == 1) {
    cout << 1;
    exit(0);
  }
  if (n % 2 != 0) {
    cout << -1;
    exit(0);
  }

  int p = 0;
  visit[p] = true;
  cout << n << " ";

  int t = n / 2 - 1;
  int cur = n - 1;
  while (t--) {
    if (!visit[(p + cur) % n]) {
      visit[(p + cur) % n] = true;
      p = (p + cur) % n;
      cout << cur << " ";
      visit[(p + (n + 1 - cur)) % n] = true;
      p = (p + (n + 1 - cur)) % n;
      cout << (n + 1 - cur) << " ";
    } else {
      visit[(p + (n + 1 - cur)) % n] = true;
      p = (p + (n + 1 - cur)) % n;
      cout << (n + 1 - cur) << " ";
      visit[(p + cur) % n] = true;
      p = (p + cur) % n;
      cout << cur << " ";
    }
    cur -= 2;
  }
  cout << 1;
}