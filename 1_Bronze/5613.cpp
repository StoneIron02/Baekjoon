#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  long long res;
  cin >> res;

  while (true) {
    string op;
    cin >> op;
    if (op == "=") {
      cout << res << "\n";
      break;
    }

    long long num;
    cin >> num;
    if (op == "+") res += num;
    else if (op == "-") res -= num;
    else if (op == "*") res *= num;
    else if (op == "/") res /= num;
  }
}