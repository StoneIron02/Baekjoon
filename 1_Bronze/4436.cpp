#include <iostream>
#include <vector>
using namespace std;

bool isAllOn(vector<bool>& check) {
  for (int i = 0; i < 10; i++) {
    if (!check[i]) return false;
  }
  return true;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n;
  while (cin >> n) {
    vector<bool> check(10, false);
    int k = 0;
    while (++k) {
      string str = to_string(1LL * k * n);
      for (char c : str) {
        check[c - '0'] = true;
      }
      if (isAllOn(check)) break;
    }
    cout << k << "\n";
  }
}
