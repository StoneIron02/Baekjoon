#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int ready = 0;
  int half = n / 2 + n % 2;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a == 1) ready++;
  }
  cout << max(0, half - ready);
}