#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  int n;
  cin >> n;
  int cnt = 0;
  while (n--) {
    string s;
    cin >> s;
    if (str == s) cnt++;
  }
  cout << cnt;
}