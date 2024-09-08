#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  double n1, n2, n12;
  cin >> n1 >> n2 >> n12;

  int n = (int)((n1 + 1) * (n2 + 1) / (n12 + 1)) - 1;
  cout << n;
}