#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int A, B;
  cin >> A >> B;

  int x[2];
  x[0] = -A + sqrt(A * A - B);
  x[1] = -A - sqrt(A * A - B);
  sort(x, x + 2);

  cout << x[0] << " ";
  if (x[0] != x[1]) {
    cout << x[1];
  }
}