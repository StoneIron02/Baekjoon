#include <iostream>
#include <cmath>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int m = (int)sqrt(n);
  cout << "The largest square has side length " << m << ".";
}