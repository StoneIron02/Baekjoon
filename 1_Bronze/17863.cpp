#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  if (str[0] == '5' && str[1] == '5' && str[2] == '5') {
    cout << "YES";
  } else {
    cout << "NO";
  }
}