#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  string first;
  cin >> first;
  n--;
  cout << first[0];
  int beforeCnt = first.size();
  while (n--) {
    string str;
    cin >> str;
    if (str.size() < beforeCnt) {
      cout << ' ';
    } else {
      cout << str[beforeCnt - 1];
    }
    beforeCnt = str.size();
  }
}
