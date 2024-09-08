#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  string answer;
  cin >> answer;

  int cntAdrian = 0, cntBruno = 0, cntGoran = 0;
  int curAdrian = 0, curBruno = 0, curGoran = 0;
  for (char c : answer) {
    if ((curAdrian == 0 && c == 'A') || (curAdrian == 1 && c == 'B') || (curAdrian == 2 && c == 'C')) {
      cntAdrian++;
    }
    if ((curBruno == 0 && c == 'B') || (curBruno == 1 && c == 'A') || (curBruno == 2 && c == 'B') || (curBruno == 3 && c == 'C')) {
      cntBruno++;
    }
    if ((curGoran == 0 && c == 'C') || (curGoran == 1 && c == 'C') || (curGoran == 2 && c == 'A') || (curGoran == 3 && c == 'A') || (curGoran == 4 && c == 'B') || (curGoran == 5 && c == 'B')) {
      cntGoran++;
    }
    curAdrian = (curAdrian + 1) % 3;
    curBruno = (curBruno + 1) % 4;
    curGoran = (curGoran + 1) % 6;
  }

  int curMax = 0;
  curMax = max(curMax, cntAdrian);
  curMax = max(curMax, cntBruno);
  curMax = max(curMax, cntGoran);
  cout << curMax << "\n";
  if (curMax == cntAdrian) {
    cout << "Adrian\n";
  }
  if (curMax == cntBruno) {
    cout << "Bruno\n";
  }
  if (curMax == cntGoran) {
    cout << "Goran\n";
  }
}