#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int s, t, d;
  cin >> s >> t >> d;
  int a = d / (s * 2);
  int b = a * t;
  cout << b;
}