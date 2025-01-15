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
    string str;
    getline(cin, str);
    stringstream ss(str);
    string save[2];
    ss >> save[0] >> save[1];
    string s;
    while (ss >> s) {
      cout << s << " ";
    }
    cout << save[0] << " " << save[1] << "\n";
  }
}