#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  int cnt = 1;
  for (int i = 1; i < str.size(); i++) {
    if (str[i - 1] >= str[i]) cnt++;
  }
  cout << cnt;
}