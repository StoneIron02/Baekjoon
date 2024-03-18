#include <iostream>
#include <cmath>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  long long sum = 0;
  int digit = to_string(n).size();

  int w = 9;
  for (int i = 1; i < digit; i++) {
    sum += i * w;
    w *= 10;
  }
  int left = n - pow(10, digit - 1) + 1;
  sum += digit * left;
  cout << sum;
}