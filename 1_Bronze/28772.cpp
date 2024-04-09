#include <iostream>
#include <map>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  map<string, int> tags;
  string str;
  while (cin >> str) {
    if (str.size() >= 2 && str[0] == '#') {
      bool flag = true;
      for (int i = 1; i < str.size(); i++) {
        if (str[i] == '#') {
          flag = false;
          break;
        }
      }
      if (flag) {
        if (tags.find(str) != tags.end()) {
          tags[str]++;
        } else {
          tags.insert({str, 1});
        }
      }
    }
  }

  cout << tags.size() << "\n";
  for (auto& i : tags) {
    cout << i.first << " " << i.second << "\n";
  }
}