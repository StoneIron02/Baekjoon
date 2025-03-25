#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int a, b, T = 1;
  string op;

  while (cin >> a >> op >> b) {
    if (op == "E") break;

    bool result = false;
    if (op == ">") result = (a > b);
    else if (op == ">=") result = (a >= b);
    else if (op == "<") result = (a < b);
    else if (op == "<=") result = (a <= b);
    else if (op == "==") result = (a == b);
    else if (op == "!=") result = (a != b);

    cout << "Case " << T << ": " << (result ? "true" : "false") << endl;
    T++;
  }

}