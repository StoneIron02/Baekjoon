#include <iostream>
#include <set>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  set<char> rep;
  char c;
  while (cin >> c) {
    rep.insert(c);
  }
  for (char& ch : str) {
    if (rep.find(ch) != rep.end()) {
      ch = ch - 'A' + 'a';
    }
  }
  cout << str;
}