#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  long long result = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      result += i + j;
    }
  }
  cout << result;
}