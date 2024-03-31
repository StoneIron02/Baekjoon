#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  bool first = true;
  string str;
  while (cin >> str) {
    if (first) {
      char f = str[0] - 'a' + 'A';
      cout << f;
      first = false;
    } else {
      if (str == "i" || str == "pa" || str == "te" || str == "ni" || str == "niti" || str == "a" ||
        str == "ali" || str == "nego" || str == "no" || str == "ili") {
        continue;
      }
      char f = str[0] - 'a' + 'A';
      cout << f;
    }
  }
}