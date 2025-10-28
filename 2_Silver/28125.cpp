#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  cin.ignore();
  unordered_map<string, char> mp = {
    {"@", 'a'}, {"[", 'c'}, {"!", 'i'}, {";", 'j'},
    {"^", 'n'}, {"0", 'o'}, {"7", 't'}, {"\\'", 'v'}, {"\\\\'", 'w'}
  };
  for (int i = 0; i < N; ++i) {
    string str;
    getline(cin, str);
    string res;
    int cnt = 0;
    for (int j = 0; j < str.size(); ) {
      bool found = false;
      for (auto& [key, value] : mp) {
        if (str.substr(j, key.size()) == key) {
          res += value;
          ++cnt;
          j += key.size();
          found = true;
          break;
        }
      }
      if (!found) {
        res += str[j];
        ++j;
      }
    }
    if (cnt * 2 >= res.size()) cout << "I don't understand" << '\n';
    else cout << res << '\n';
  }
}