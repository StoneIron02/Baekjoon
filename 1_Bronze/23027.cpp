#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string S;
  cin >> S;
  char minExist = 'D';
  for (char c : S) {
    if (c < minExist) {
      minExist = c;
    }
  }
  if (minExist == 'D') {
    for (char& c : S) {
      c = 'A';
    }
  } else {
    for (char& c : S) {
      if (c == 'B' || c == 'C' || c == 'D' || c == 'F') {
        c = minExist;
      }
    }
  }
  cout << S;
}