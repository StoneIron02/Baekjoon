#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;
  int result = b - a;
  if (result < 0) {
    result += 24;
  }
  cout << result;
}