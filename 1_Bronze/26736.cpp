#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  int scoreA = 0;
  int scoreB = 0;

  for (char c : str) {
    if (c == 'A') {
      scoreA++;
    } else if (c == 'B') {
      scoreB++;
    }
  }

  cout << scoreA << " : " << scoreB << endl;
}