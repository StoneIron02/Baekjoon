#include <iostream>
#include <numeric>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  long long b;
  cin >> n >> b;

  long long sum_x = 0;
  long long sum_y = 0;

  for (int i = 0; i < n; ++i) {
    long long x, y;
    cin >> x >> y;
    sum_x += x;
    sum_y += y;
  }

  if (sum_x == 0) {
    cout << "EZPZ" << "\n";
    return 0;
  }

  long long numerator = sum_y - n * b;
  long long denominator = sum_x;

  if (denominator < 0) {
    numerator = -numerator;
    denominator = -denominator;
  }

  long long g = gcd(abs(numerator), denominator);
  numerator /= g;
  denominator /= g;

  if (denominator == 1) {
    cout << numerator << "\n";
  } else {
    cout << numerator << "/" << denominator << "\n";
  }
}
