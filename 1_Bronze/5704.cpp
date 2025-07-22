#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  while (getline(cin, str)) {
    if (str == "*") break;

    set<char> letters;
    for (char c : str) {
      if ('a' <= c && c <= 'z') {
        letters.insert(c);
      }
    }

    if (letters.size() == 26) {
      cout << "Y\n";
    } else {
      cout << "N\n";
    }
  }
}