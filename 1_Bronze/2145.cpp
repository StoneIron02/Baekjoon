#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  while (true) {
    string str;
    cin >> str;
    if (str == "0") break;
    while (str.size() > 1) {
      int sum = 0;
      for (char c : str) {
        sum += c - '0';
      }
      str = to_string(sum);
    }
    cout << str << "\n";
  }
}