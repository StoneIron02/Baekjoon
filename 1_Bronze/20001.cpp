#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int cnt = 0;
  string str;
  while (getline(cin, str)) {
    if (str == "문제") {
      cnt++;
    } else if (str == "고무오리") {
      if (cnt == 0) {
        cnt += 2;
      } else {
        cnt--;
      }
    } else if (str == "고무오리 디버깅 끝") {
      break;
    }
  }
  if (cnt == 0) {
    cout << "고무오리야 사랑해";
  } else {
    cout << "힝구";
  }
}