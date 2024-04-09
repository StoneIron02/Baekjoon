#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;

int convertToNum[26];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  string str;
  cin >> str;
  for (int i = 0; i < n; i++) {
    cin >> convertToNum[i];
  }

  stack<double> stk;
  for (char c : str) {
    if ('A' <= c && c <= 'Z') {
      stk.push(convertToNum[c - 'A']);
    } else {
      auto b = stk.top();
      stk.pop();
      auto a = stk.top();
      stk.pop();
      if (c == '+') stk.push(a + b);
      if (c == '-') stk.push(a - b);
      if (c == '*') stk.push(a * b);
      if (c == '/') stk.push(a / b);
    }
  }
  cout << fixed << setprecision(2) << stk.top();
}