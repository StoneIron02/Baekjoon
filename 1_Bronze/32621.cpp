#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;

  int pos = str.find('+');
  if (pos == string::npos || pos == 0 || pos == str.size() - 1 || str.find('+', pos + 1) != string::npos) {
    cout << "No Money";
    exit(0);
  }

  string left = str.substr(0, pos);
  string right = str.substr(pos + 1);
  if (left[0] == '0' || right[0] == '0') {
    cout << "No Money";
    exit(0);
  }
  for (char c : left + right) {
    if (!isdigit(c)) {
      cout << "No Money";
      exit(0);
    }
  }

  if (left == right) {
    cout << "CUTE";
  } else {
    cout << "No Money";
  }
}
