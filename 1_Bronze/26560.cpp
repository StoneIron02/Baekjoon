#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  cin.ignore();
  while (n--) {
    string str;
    getline(cin, str);
    if (str.back() != '.')
      str += '.';
    cout << str << "\n";
  }
}