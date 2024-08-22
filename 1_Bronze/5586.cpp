#include <iostream>
using namespace std;

bool match1(const string& str, int i) {
  return (str[i] == 'J' && str[i + 1] == 'O' && str[i + 2] == 'I');
}

bool match2(const string& str, int i) {
  return (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I');
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string str;
  cin >> str;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < str.size() - 2; i++) {
    if (match1(str, i)) cnt1++;
    if (match2(str, i)) cnt2++;
  }
  cout << cnt1 << "\n" << cnt2;
}
