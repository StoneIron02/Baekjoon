#include <iostream>
using namespace std;

int cntUorC = 0;
int cntDorP = 0;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  for (char c : str) {
    if (c == 'U' || c == 'C')
      cntUorC++;
    else if (c == 'D' || c == 'P')
      cntDorP++;
  }

  int d = cntDorP % 2 == 1 ? cntDorP / 2 + 1 : cntDorP / 2;
  if (cntUorC > d) {
    cout << "U";
  }
  if (cntDorP > 0) {
    cout << "DP";
  }
}