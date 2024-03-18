#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string a, b;
  cin >> a >> b;
  if (a.size() < b.size()) {
    string tmp = a;
    a = b;
    b = tmp;
  }
  size_t diff = a.size() - b.size();
  for (int i = 0; i < diff; i++) {
    b = '0' + b;
  }

  string result;
  int carry = 0;
  for (int i = a.size() - 1; i >= 0; i--) {
    int a_i = a[i] - '0';
    int b_i = b[i] - '0';
    int sum = a_i + b_i + carry;
    if (sum > 9) {
      carry = 1;
      sum -= 10;
    } else {
      carry = 0;
    }
    result = to_string(sum) + result;
  }
  if (carry > 0) {
    result = to_string(carry) + result;
  }
  cout << result;
}