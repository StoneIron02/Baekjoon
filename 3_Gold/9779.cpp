#include <iostream>
#include <regex>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  regex re("da+dd?(i|y)");
  string str;
  while (cin >> str) {
    if (regex_match(str, re)) {
      cout << "She called me!!!\n";
    } else {
      cout << "Cooing\n";
    }
  }
}