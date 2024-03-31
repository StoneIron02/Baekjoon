#include <iostream>
#include <sstream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  cin.ignore();
  while (n--) {
    string s;
    getline(cin, s);
    stringstream ss;
    ss.str(s);
    string sub;
    bool first = true;
    while (ss >> sub) {
      if (first) {
        cout << "god";
        first = false;
      }
      else {
        cout << sub;
      }
    }
    cout << "\n";
  }
}