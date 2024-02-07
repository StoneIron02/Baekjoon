#include <iostream>
#include <algorithm>

using namespace std;

bool check(string str) {
  int i = 0, j = str.size() - 1;
  while (i < j) {
    if (str[i] != str[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    string str_rev = str;
    reverse(str_rev.begin(), str_rev.end());

    int iStr = stoi(str);
    int iStr_rev = stoi(str_rev);
    int sum = iStr + iStr_rev;
    string sSum = to_string(sum);
    if (check(sSum)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}