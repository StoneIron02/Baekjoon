#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int p;
  cin >> p;
  int minVal = p;
  if (n >= 5) minVal = min(minVal, p - 500);
  if (n >= 10) minVal = min(minVal, (int)(p * 0.9));
  if (n >= 15) minVal = min(minVal, p - 2000);
  if (n >= 20) minVal = min(minVal, (int)(p * 0.75));
  if (minVal < 0) minVal = 0;
  cout << minVal;
}