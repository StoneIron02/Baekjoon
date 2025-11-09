#include <iostream>
#include <cmath>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  long long a, b;
  cin >> a >> b;
  double A = (double)a * b;
  double acres = A / 4840.0;
  double bags = acres / 5.0;
  cout << (long long)ceil(bags);
}