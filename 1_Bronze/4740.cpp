#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  while (true) {
    string str;
    getline(cin, str);
    if (str == "***") break;
    reverse(str.begin(), str.end());
    cout << str << "\n";
  }
}