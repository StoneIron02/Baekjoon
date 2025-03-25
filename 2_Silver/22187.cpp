#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  string tmp;
  for (char c : str) {
    if (c == '(') {
      cout << tmp;
      tmp = "";
    } else if (c == ')') {
      reverse(tmp.begin(), tmp.end());
      cout << tmp;
      tmp = "";
    } else {
      tmp += c;
    }
  }
  cout << tmp;
}