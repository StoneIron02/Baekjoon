#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  int t = 0;
  while (true) {
    t++;
    cin >> str;
    if (str == "0") break;
    while (true) {
      if (str.size() % 2 == 1) {
        cout << "Test " << t << ": " << str << "\n";
        break;
      }
      string result;
      for (int i = 0; i < str.size(); i += 2) {
        int cnt = stoi(str.substr(i, 1));
        char c = str[i + 1];
        for (int j = 0; j < cnt; j++) {
          result += c;
        }
      }

      int curCnt = 1;
      string restruct;
      for (int i = 0; i < result.size() - 1; i++) {
        if (result[i] != result[i + 1]) {
          restruct += to_string(curCnt);
          restruct += result[i];
          curCnt = 1;
        } else {
          curCnt++;
        }
      }
      restruct += to_string(curCnt);
      restruct += result[result.size() - 1];
      if (str != restruct) {
        cout << "Test " << t << ": " << str << "\n";
        break;
      }

      if (result == str) {
        cout << "Test " << t << ": " << result << "\n";
        break;
      }
      str = result;
    }
  }
}