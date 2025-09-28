#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t, s, h;
  cin >> t >> s >> h;

  for (int i = 0; i < t; ++i) {
    cout << '*' << string(s, ' ') << '*' << string(s, ' ') << '*';
    cout << '\n';
  }

  cout << string(2 * s + 3, '*') << '\n';

  for (int i = 0; i < h; ++i) {
    cout << string(s + 1, ' ') << '*' << '\n';
  }
}