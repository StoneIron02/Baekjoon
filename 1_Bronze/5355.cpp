#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  cin.ignore();
  while (T--) {
    string str;
    getline(cin, str);
    istringstream ss(str);
    double num;
    ss >> num;
    char c;
    while (ss >> c) {
      if (c == '@') num *= 3;
      else if (c == '%') num += 5;
      else num -= 7;
    }
    cout << fixed << setprecision(2) << num << "\n";
  }
}