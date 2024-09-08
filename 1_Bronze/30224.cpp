#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  bool divisible = n % 7 == 0;
  string n_str = to_string(n);
  bool contain = false;
  for (char c : n_str) {
    if (c == '7') contain = true;
  }

  int result = 0;
  result += contain ? 2 : 0;
  result += divisible ? 1 : 0;
  cout << result;
}