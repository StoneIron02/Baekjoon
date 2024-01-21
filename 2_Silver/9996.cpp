#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  cin.ignore();
  string prefix, suffix;
  getline(cin, prefix, '*');
  getline(cin, suffix);
  while (n--) {
    string str;
    cin >> str;
    if (prefix.size() + suffix.size() > str.size()) {
      cout << "NE\n";
      continue;
    }
    bool flag = true;
    for (int i = 0; i < prefix.size(); i++) {
      if (prefix[i] != str[i]) {
        flag = false;
        break;
      }
    }
    for (int i = 0; i < suffix.size(); i++) {
      if (suffix[suffix.size() - 1 - i] != str[str.size() - 1 - i]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "DA\n";
    } else {
      cout << "NE\n";
    }
  }
}