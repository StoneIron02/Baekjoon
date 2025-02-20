#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, k, a, b;
  cin >> n >> k >> a >> b;
  cout << (k + n - 2) * b << " ";
  cout << (n - 1) * a;
}