#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  unsigned long long result = 1;
  for (int i = 2; i <= n; i++) {
    result = (result * i) % 10'000'000'000'000;
    while (result % 10 == 0) {
      result /= 10;
    }
  }
  string sResult = to_string(result);
  cout << sResult.substr(sResult.size() - 5, 5);
}