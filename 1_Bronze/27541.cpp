#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  string str;
  cin >> str;
  if (str[str.size() - 1] == 'G') {
    cout << str.substr(0, str.size() - 1);
  } else {
    cout << str << "G";
  }
}