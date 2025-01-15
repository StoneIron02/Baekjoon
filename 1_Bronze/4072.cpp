#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  while (true) {
    cin >> str;
    if (str == "#") break;
    reverse(str.begin(), str.end());
    cout << str << " ";
  }
}