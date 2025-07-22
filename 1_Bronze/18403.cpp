#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int year) {
  return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  cin.ignore();

  for (int i = 0; i < T; ++i) {
    string str;
    getline(cin, str);
    stringstream ss(str);
    string token;
    bool first = true;

    while (getline(ss, token, ',')) {
      int year = stoi(token);
      if (check(year)) {
        if (!first) cout << " ";
        cout << year;
        first = false;
      }
    }
    cout << "\n";
  }
}