#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  double a, b;
  cin >> a >> b;
  double res = a - (a * b / 100);
  cout << (res < 100);
}
