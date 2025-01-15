#include <iostream>

using namespace std;

int compute_weight(int num) {
  string sNum = to_string(num);
  int val = 0;
  for (auto i : sNum) {
    val += i - '0';
  }
  return sNum.size() * val;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;
  int wA = compute_weight(a);
  int wB = compute_weight(b);
  if (wA > wB) cout << 1;
  else if (wA < wB) cout << 2;
  else cout << 0;
}