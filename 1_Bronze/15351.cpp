#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  cin.ignore();
  while (N--) {
    string str;
    getline(cin, str);

    int tot = 0;
    for (char c : str) {
      if (c >= 'A' && c <= 'Z') {
        int score = c - 'A' + 1;
        tot += score;
      }
    }

    if (tot == 100) {
      cout << "PERFECT LIFE\n";
    } else {
      cout << tot << "\n";
    }
  }
}