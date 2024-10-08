#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;
  int curSum = m;
  int maxSum = m;
  while (n--) {
    int a, b;
    cin >> a >> b;
    curSum -= b;
    curSum += a;
    maxSum = max(maxSum, curSum);
    if (curSum < 0) {
      cout << 0;
      exit(0);
    }
  }
  cout << maxSum;
}
