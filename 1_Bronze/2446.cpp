#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int r = n; r >= 2; r--) {
    int starCnt = r * 2 - 1;
    int blankCnt = ((n * 2 - 1) - starCnt) / 2;
    for (int c = 0; c < blankCnt; c++) {
      cout << ' ';
    }
    for (int c = 0; c < starCnt; c++) {
      cout << '*';
    }
    cout << "\n";
  }
  for (int r = 1; r <= n; r++) {
    int starCnt = r * 2 - 1;
    int blankCnt = ((n * 2 - 1) - starCnt) / 2;
    for (int c = 0; c < blankCnt; c++) {
      cout << ' ';
    }
    for (int c = 0; c < starCnt; c++) {
      cout << '*';
    }
    cout << "\n";
  }
}