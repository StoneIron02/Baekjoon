#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<char, char> convert = {
    {'b', 'd'},
    {'d', 'b'},
    {'p', 'q'},
    {'q', 'p'},
    {'i', 'i'},
    {'o', 'o'},
    {'v', 'v'},
    {'w', 'w'},
    {'x', 'x'}
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  while (true) {
    cin >> str;
    if (str == "#") break;

    string res;
    bool invalid = false;
    for (char c : str) {
      if (convert.find(c) == convert.end()) {
        invalid = true;
        break;
      } else {
        res += convert[c];
      }
    }
    if (invalid) {
      cout << "INVALID\n";
    } else {
      reverse(res.begin(), res.end());
      cout << res << "\n";
    }
  }
}