#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cal(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}


int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;
  int g = __gcd(a, b);
  int maxSum = 0;
  int res = 1;

  for (int i = 1; i * i <= g; ++i) {
    if (g % i == 0) {
      int sum1 = cal(i);
      if (sum1 > maxSum) {
        maxSum = sum1;
        res = i;
      }

      int div2 = g / i;
      if (div2 != i) {
        int sum2 = cal(div2);
        if (sum2 > maxSum) {
          maxSum = sum2;
          res = div2;
        }
      }
    }
  }

  cout << res;
}