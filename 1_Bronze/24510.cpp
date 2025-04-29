#include <iostream>
using namespace std;

int check(const string& str) {
  int count = 0;
  for (size_t i = 0; i < str.size();) {
    if (str.substr(i, 3) == "for") {
      count++;
      i += 3;
    } else if (str.substr(i, 5) == "while") {
      count++;
      i += 5;
    } else {
      i++;
    }
  }
  return count;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int C;
  cin >> C;

  int maxCnt = 0;
  string str;
  for (int i = 0; i < C; i++) {
    cin >> str;
    int cnt = check(str);
    if (cnt > maxCnt) {
      maxCnt = cnt;
    }
  }

  cout << maxCnt << endl;
}
