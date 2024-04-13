#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string a, b;
  cin >> a >> b;
  while (a.size() < b.size()) {
    a = '0' + a;
  }
  while (a.size() > b.size()) {
    b = '0' + b;
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  string result;
  for (int i = 0; i < a.size(); i++) {
    int aInt = a[i] - '0';
    int bInt = b[i] - '0';
    int r = aInt + bInt;
    result = to_string(r) + result;
  }
  cout << result;
}