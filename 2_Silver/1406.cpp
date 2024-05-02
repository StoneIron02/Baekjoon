#include <iostream>
#include <list>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  list<char> l;
  string str;
  cin >> str;
  for (char c : str) {
    l.push_back(c);
  }
  auto pos = l.end();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char cmd;
    cin >> cmd;
    if (cmd == 'L') {
      if (pos != l.begin()) {
        --pos;
      }
    } else if (cmd == 'D') {
      if (pos != l.end()) {
        ++pos;
      }
    } else if (cmd == 'B') {
      if (pos != l.begin()) {
        auto erasePos = --pos;
        pos = l.erase(erasePos);
      }
    } else if (cmd == 'P') {
      char c;
      cin >> c;
      pos = ++l.insert(pos, c);
    }
  }
  for (char c : l) {
    cout << c;
  }
}