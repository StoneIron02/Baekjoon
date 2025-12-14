#include <iostream>
#include <stack>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;
  stack<int> stk;

  for (char c : s) {
    if (isdigit(c)) {
      stk.push(c - '0');
    }
    else {
      int b = stk.top();
      stk.pop();
      int a = stk.top();
      stk.pop();
      if (c == '+')
        stk.push(a + b);
      else if (c == '-')
        stk.push(a - b);
      else if (c == '*')
        stk.push(a * b);
      else
        if (c == '/')
          stk.push(a / b);
    }
  }

  cout << stk.top();
}
