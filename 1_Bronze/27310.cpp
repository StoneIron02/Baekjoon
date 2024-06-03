#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  int level = 0;
  level += str.size();
  level += 2;
  for (char c : str) {
    if (c == '_') {
      level += 5;
    }
  }
  cout << level;
}