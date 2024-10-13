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
    int cntG = 0, cntB = 0;
    for (char c : str) {
      if (c == 'G' || c == 'g') cntG++;
      if (c == 'B' || c == 'b') cntB++;
    }
    if (cntG > cntB) {
      cout << str << " is " << "GOOD" << "\n";
    } else if (cntG < cntB) {
      cout << str << " is " << "A BADDY" << "\n";
    } else {
      cout << str << " is " << "NEUTRAL" << "\n";
    }
  }
}