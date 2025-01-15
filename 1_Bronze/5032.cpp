#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int e, f, c;
  cin >> e >> f >> c;
  int sum = 0;
  int n = e + f;
  while (n / c > 0) {
    sum += n / c;
    n = n % c + n / c;
  }
  cout << sum;
}