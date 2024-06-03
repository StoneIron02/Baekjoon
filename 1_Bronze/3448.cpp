#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    string str;
    int tot = 0;
    int fail = 0;
    while (getline(cin, str)) {
      if (str.empty()) break;
      for (char c : str) {
        tot++;
        if (c == '#') fail++;
      }
    }

    int result = (10000 * (tot - fail) / tot + 5) / 10;
    cout << "Efficiency ratio is " << result / 10;
    result %= 10;
    if (result > 0) cout << "." << result;
    cout << "%.\n";
  }

}