#include <iostream>
using namespace std;

int min_cnt = 200000000;
int max_cnt = 0;

void cut(const string& str, const int before_cnt) {
  int cnt = before_cnt;
  for (const char c : str) {
    if ((c - '0') % 2 == 1) {
      cnt++;
    }
  }

  if (str.size() == 1) {
    min_cnt = min(min_cnt, cnt);
    max_cnt = max(max_cnt, cnt);
    return;
  }

  if (str.size() == 2) {
    string new_str = to_string(stoi(str.substr(0, 1)) + stoi(str.substr(1)));
    cut(new_str, cnt);
    return;
  }

  for (int i = 1; i < str.size() - 1; i++) {
    for (int j = i + 1; j < str.size(); j++) {
      string str1 = str.substr(0, i);
      string str2 = str.substr(i, j - i);
      string str3 = str.substr(j);
      string new_str = to_string(stoi(str1) + stoi(str2) + stoi(str3));
      cut(new_str, cnt);
    }
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string s;
  cin >> s;
  cut(s, 0);
  cout << min_cnt << " " << max_cnt;
}
