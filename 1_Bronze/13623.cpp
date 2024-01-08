#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int a, b, c;
  cin >> a >> b >> c;
  if (a != b && a != c && b == c) {
    cout << "A";
  }
  else if (b != a && b != c && a == c) {
    cout << "B";
  }
  else if (c != a && c != b && a == b) {
    cout << "C";
  }
  else {
    cout << "*";
  }
}