#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int cnt = 0;
  while (n--) {
    string str;
    cin >> str;
    string sDay = str.substr(2);
    if (stoi(sDay) <= 90) cnt++;
  }
  cout << cnt;
}